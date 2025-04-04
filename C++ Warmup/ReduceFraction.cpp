//
// Created by Epics on 4/2/2025.
//

#include "ReduceFraction.h"
#include <iostream>
#include <array>

/*
following class demonstration
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

    std::string toString() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

};

/*
 *A helper method to find the largest common denominator
 */
int largestCommonDenominator(Fraction input) {
    for (int i = input.numerator; i > 0; i--) {
        if (input.denominator % i == 0 && input.numerator % i == 0) {
            return i;
        }
    }
}

Fraction reduce(Fraction input) {
    int indexOfDivider = input.toString().find('/');
    int numerator = stoi(input.toString().substr(0, indexOfDivider));
    int denominator = stoi(input.toString().substr(indexOfDivider + 1, input.toString().length()));

    int lcd =  largestCommonDenominator(input);
    input.numerator = numerator / lcd;
    input.denominator = denominator / lcd;
    return input;
}

void test() {
    /* reduce given fraction to minimum terms
     * 2/4 = 1/2
     * 4/2 = 2/1
     * 6/8 = 3/4
     * Given an input, the actual output should match the expected output
    */
    Fraction input[] = {Fraction(1, 2),
                        Fraction(2,4),
                        Fraction(4, 2),
                        Fraction(6, 8)};

    Fraction expected_output[] = {Fraction(1, 2),
                                  Fraction(1, 2),
                                  Fraction(2, 1),
                                  Fraction(3, 4)};
    for (int i = 0; i < sizeof(input) / sizeof(*input); i++) {
        std::cout << input[i].toString() << "  reduces to: " << reduce(input[i]).toString() << std::endl;
    }


    //call the function
    for (int i = 0; i < sizeof(input)/sizeof(*input); i++) {
        if (reduce(input[i]).denominator == expected_output[i].denominator &&
            reduce(input[i]).numerator   == expected_output[i].numerator) {

            std::cout << "Test passed" << std::endl;
        } else {
            std::cout << "Test failed! Case: " << input[i].toString() << std::endl;
        }
    }

    //compare expected vs actual

}

int main() {
    test();
    return 0;
}
