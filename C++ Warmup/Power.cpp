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

void printResult(bool result) {
  if (result == true) {
    printf("is a power of 2\n");
  } else {
    printf("is not a power of 2\n");
  }
}


int main() {

  bool result = is_power_of_two(1);
  bool resultLoop = is_power_of_two(1);
  std::cout << result;


  printf("Printing non-loop results\n");
  printf("========================\n");
  for (int num = 0; num < 10; num++) {
    std::cout << "Num = " << num << " Is power of two: " << is_power_of_two(num) << std::endl;
  }

  printf("========================\n");
  printf("Printing non-loop results\n");
  printf("========================\n");
  for (int num = 0; num < 10; num++) {
    std::cout << "Num = " << num << " Is power of two: " << is_power_of_two_Loop(num) << std::endl;
  }


}


