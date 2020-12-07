//==============================================================================
// Author      : Zhenia Steger
// Purpose     : Demonstrate computing hamming distance with loops.
// =============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "BitManipulations.h"

void hammingDistance(uint32_t inData1, uint32_t inData2);

int main(int argc, char const *argv[]) {

  if (argc != 3) {
    printf("\nUsing this function:\nhamming integerOne integerTwo\n\n");
    exit(0)
  }
  uint32_t input1;
  uint32_t input2;
  input1 = atoi(argv[1]);
  input2 = atoi(argv[2]);
  hammingDistance(input1, input2);
  return 0;
}

// PURPOSE: COMPUTES THE HAMMING DISTANCE BETWEEN TWO NUMBERS
// PARAMS: TWO UNSIGNED INTEGERS: inData1, inData2
void hammingDistance(uint32_t inData1, uint32_t inData2)
{
  int count = 0;           // to count how many bits differ
  int i = 31;              // loop counter
  int j = 31;              // loop counter
  uint32_t number1[32];    // array to store number1 as binary
  uint32_t number2[32];    // array to store number2 as binary

  printf("inData1 is %d\n", inData1);     // print for testing purposes
  printf("inData2 is %d\n", inData2);     // print for testing purposes

/*
  // FOR LOOP IMPLEMENTATION ==============
  for (int a = 31; a > 0; a--) {
    number1[a] = inData1 % 2;
    inData1 /= 2;
  }
  for (int b = 31; b > 0; b--) {
    number2[b] = inData2 % 2;
    inData2 /= 2;
  }
  // ======================================
*/

  // WHILE LOOP IMPLEMENTATION ============
  while(i > 0) {
    number1[i] = inData1 % 2;
    inData1 /= 2;
    i--;
  }

  while(j > 0) {
    number2[j] = inData2 % 2;
    inData2 /= 2;
    j--;
  }
  // ======================================

  // PRINT THE ARRAYS FOR FUN
  for (int l = 0; l < 32; l++)
    printf("%d", number1[l]);
    printf("\n");
    for (int l = 0; l < 32; l++)
      printf("%d", number2[l]);

    for (int k = 0; k < 32; k++) {
      if(number2[k] != number1[k])
        count++;
    }
  // OUTPUT THE HAMMING DISTANCE
  printf("\n");
  printf("The Hamming Distance is: %d\n", count);
}
