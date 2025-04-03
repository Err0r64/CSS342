//
// Created by Epics on 4/2/2025.
//

#include "ReduceFraction.h"
#include <iostream>

/*
 *  A helper method to find the largest common denominator
 */
int largestCommonDenominator(int numerator, int denominator) {
    for (int i = numerator; i > 0; i--) {
        if (denominator % i == 0 && numerator % i == 0) {
            return i;
        }
    }
}

/*
 *  Method reduces any given fraction to it's simplest form.
 *  Separates the given string fraction into it's two "numbers" and divider
 *      Converts the "numbers" into integers, find the common denominator between these numbers,
 *      and reduces them on the common denominator found.
 *  Returns a rebuilt string of the reduced fraction.
 */
std::string reduceFraction(std::string fraction) {
    int indexOfDivider = fraction.find('/');
    int numerator = stoi(fraction.substr(0, indexOfDivider));
    int denominator = stoi(fraction.substr(indexOfDivider + 1, fraction.length()));

    int lcd =  largestCommonDenominator(numerator, denominator);
    return std::to_string(numerator/lcd) + "/" + std::to_string(denominator/lcd);
}

int main() {
    std::cout << reduceFraction("2/3") << std::endl;
    std::cout << reduceFraction("3/2") << std::endl;
    std::cout << reduceFraction("12/14") << std::endl;
    std::cout << reduceFraction("12/18") << std::endl;
    return 0;
}
