//
// Created by Epics on 4/2/2025.
//

#include "ReduceFraction.h"
#include <iostream>

/*
 * following class demonstration of creating a class object in cpp
 */
class Fraction {
  public:
    int numerator;
    int denominator;

    // I prefer the java constructor
    Fraction(int numerator, int denominator) {
      this->numerator = numerator;
      this->denominator = denominator;
    }

    // Method returns a string representation of the fraction
    std::string toString() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

};



/*
 * A helper method to find the largest common denominator
 */
int largestCommonDenominator(Fraction input) {
    for (int i = abs(input.numerator); i > 0; i--) {
        if (input.denominator % i == 0 && input.numerator % i == 0) {
            return i;
        }
    }
}

/*
 * This method reduces any fraction to it's simplest form by dividing both the numerator and denominator by the
 *  largest common denominator.
 * The method returns the input fraction but in it's reduced form.
 * METHOD ASSUMES ALL FRACTIONS ARE VALID (but I tried experimenting with a try catch to throw a readable error)
 */
Fraction reduce(Fraction input) {
    try {
        if (input.denominator == 0) {
            throw std::runtime_error("Division by zero error!");
        }

        if (input.numerator == 0) {
            return Fraction{0,0};
        }

        int indexOfDivider = input.toString().find('/');
        int numerator = stoi(input.toString().substr(0, indexOfDivider));
        int denominator = stoi(input.toString().substr(indexOfDivider + 1, input.toString().length()));

        int lcd =  largestCommonDenominator(input);
        input.numerator = numerator / lcd;
        input.denominator = denominator / lcd;
        return input;

    } catch (std::runtime_error) {
        std::cerr << "ERROR: DIVISION BY ZERO" << std::endl;
    }


}

void test() {
    /* reduce given fraction to minimum terms
     * 2/4 = 1/2
     * 4/2 = 2/1
     * 6/8 = 3/4
     * Given an input, the actual output should match the expected output
     * Negative fractions use the same algorithm except we use the absolute values within loops
     * Whole numbers will return 1/1
    */
    Fraction input[] = {Fraction(1, 2),
                        Fraction(2,4),
                        Fraction(4, 2),
                        Fraction(6, 8),
                        Fraction(-1, 2),
                        Fraction(-2, 4),
                        Fraction(4, 4),
                        Fraction(1, -2),
                        Fraction(0, 1),
                        Fraction(1, 0)};

    Fraction expected_output[] = {Fraction(1, 2),
                                  Fraction(1, 2),
                                  Fraction(2, 1),
                                  Fraction(3, 4),
                                  Fraction(-1, 2),
                                  Fraction(-1, 2),
                                  Fraction(1, 1),
                                  Fraction(1, -2),
                                  Fraction(0, 0)};

    //compare expected vs actual (the actual input is compared within the if else statement)
    for (int i = 0; i < sizeof(input)/sizeof(*input); i++) {
        if (reduce(input[i]).denominator == expected_output[i].denominator &&
            reduce(input[i]).numerator   == expected_output[i].numerator) {

            std::cout << "Test passed" << std::endl;
        } else {
            std::cout << "Test failed! Case: " << input[i].toString() << std::endl;
        }
    }
}

int main() {
    test();
    return 0;
}
