//
// Created by Alec Situ on 4/10/25.
//
#include <iostream>

void test();

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    std::string to_string() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // operator overload
    bool operator==(Fraction &other) const {
        return this->numerator == other.numerator &&
               this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction &input) {
    int divider = 2;
    while (divider <= input.numerator && divider <= input.denominator) {
        if (input.numerator % divider == 0 &&
            input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
            }
        divider++;
    }
    return input;
}

int main() {
    test();
}

void test() {
    // given an input, the actual output should match the expected output
    Fraction inputs[4] = {Fraction(1, 2),
                          Fraction{2, 4},
                          Fraction{4, 2},
                          Fraction{6, 8}
    };

    Fraction outputs[4] = {Fraction(1, 2),
                           Fraction{1, 2},
                           Fraction{2, 1},
                           Fraction{3, 4}
    };

    // call the function
    for (int i = 0; i < 4; ++i) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        reduce(input);

        // compare expected vs actual
        if (expect == input) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! case is: " << input.to_string() << std::endl;
        }
    }

}