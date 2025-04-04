//
// Created by Epics on 4/2/2025.
//
#include "isPrime.h"
#include <iostream>
#include <ostream>


/*
 *Method checks if a [number] is a prime number.
 *Any number that is equal to or less than one is guaranteed non-prime.
 *The loop checks if the number is divisible by anything other than itself and 1
 *  (Looks like we only need to check half of the numbers from 2 - number therefore
 *  number is divided in half in the loop, this saves time).
 *Returns true if it does not match any of this criteria.
 */
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= number/2; i++) {
        if (number % i == 0 && number != i) {
            return false;
        }
    }
    return true;
}

void test() {
    std::cout << "Testing isPrime" << std::endl;
    std::cout << "===================" << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << "The current number is: " << i;
        if (isPrime(i)) {
            std::cout << " is a prime number!" << std::endl;
        } else {
            std::cout << " is not a prime number!" << std::endl;
        }
    }
}

int main() {
    test();
}
