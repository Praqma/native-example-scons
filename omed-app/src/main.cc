#include <iostream>

#include "mathy.h"

int main(const int argc, const char *argv[])
{
    printf("Hello world!\n");

    if (argc > 1) {
      printf("Number of arguments detected is %d.\n", argc);
      int i=0;
      while(argv[i]!=NULL){
        printf("The argv[%d] has `%s` value.\n", i, argv[i]);
        i++;
      }
    }

    printf("7 + 3 = %f\n", Mathy::Calculate::Add(5, 3));
    printf("7 - 3 = %f\n", Mathy::Calculate::Subtract(5, 3));
    printf("7 * 3 = %f\n", Mathy::Calculate::Multiply(5, 3));
    printf("7 / 3 = %f\n", Mathy::Calculate::Divide(5, 3));

    return 0;
}
