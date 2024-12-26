#include <stdio.h>

int main(){
    int num;
    float f;
    char c;
    double d;

    printf("Size of char: %zu byte\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of short int: %zu bytes\n", sizeof(short int));
    printf("Size of long int: %zu bytes\n", sizeof(long int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of signed int: %zu bytes\n", sizeof(signed int));

    return 0;
}


