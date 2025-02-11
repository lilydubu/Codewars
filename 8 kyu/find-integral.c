// Create a function that finds the integral of the expression passed.
// In order to find the integral all you need to do is add one to the exponent (the second argument), and divide the coefficient (the first argument) by that new number.

#include <stdio.h>
#include <stdlib.h>
char *integrate(int coefficient, int exponent) {
    int new_exponent = exponent + 1;
    int new_coef = coefficient / new_exponent;
    
    char* str = malloc(100 * sizeof(char));
    sprintf(str, "%dx^%d", new_coef, new_exponent);
    return str;
}
