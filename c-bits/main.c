#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_MASK     0x00000001
#define CONST_TRUE    0x80000001
#define CONST_FALSE   0x00000001

extern long our_code_starts_here() asm("our_code_starts_here");
extern long print(long val)        asm("print");

long print(long val){
  if ((val & TYPE_MASK) == 0) { // val is int  
    printf("%ld\n", val >> 1);
  }
  else {
    if (val == CONST_TRUE) {
      printf("true\n");
    } else {
      if (val == CONST_FALSE) {
        printf("false\n");
      } else {
        printf("Unknown value: %#010lx\n", val);
      }
    }
  }
  return val;
}

/*

Copy over any error-detection functions here

*/

int main(int argc, char** argv) {
  long result = our_code_starts_here();
  print(result);
  return 0;
}
