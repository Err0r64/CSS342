//
// Created by Alec Situ on 4/1/25.
//

#include "Power.h"
#include <iostream>
#include <ostream>

/*
 *Non-loop method that uses bitwise operation.
 *Returns true if the number is a power of two AND greater than 0
 *Note for self the & operator is the bitwise AND. It compares the bit of two numbers
 *  And returns a new bit where:
 *    1's indicate both bits have a one and a 0 otherwise.
 *    Ex: 2 = 10, (2-1) = 1, Result = (10 & 1) -> 00 == 0
*/
bool is_power_of_two(int num) {
  return ((num > 0) && (num & (num - 1)) == 0);
}

/*
 *Loop method that returns:
 *  True when num == 1 to signal that it is a power of 2
 *  False when num == 0 or that it is not a power of 2
*/
bool is_power_of_two_Loop(int num) {
  if (num == 0) {
    return false;
  }
  while (true) {
    if (num == 1) {
      return true;
    }

    if (num % 2 == 0) {
      num = num / 2;
    } else {
      return false;
    }
  }
}

std::string printResult(bool result) {
  if (result == true) {
    return " is a power of 2";
  } else {
    return " is NOT a power of 2";
  }
}

void loopTest() {
  printf("Printing loop results\n");
  printf("========================\n");
  for (int num = 0; num < 10; num++) {
    std::cout << num << printResult(is_power_of_two_Loop(num)) << std::endl;
  }
  printf("========================\n");
}

void nonLoopTest() {
  printf("Printing non-loop results\n");
  printf("========================\n");
  for (int num = 0; num < 10; num++) {
    std::cout << num << printResult(is_power_of_two(num)) << std::endl;
  }
  printf("========================\n");
}


int main() {
  nonLoopTest();
  loopTest();
  return 0;
}


