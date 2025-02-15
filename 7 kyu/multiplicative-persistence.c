// Create a function that calculates the individual results of each step, not including the original number, 
// but including the single digit, and outputs the result as a list/array. 
// If the input is a single digit, return an empty list/array.

#include <stddef.h>
#include <stdlib.h>

long multiply(long m){
  long out = 1; // This variable will hold the multplied number
  
  while(m){ // Get each digit from m and multiply to out
    out *= m % 10;
    m /= 10;
  }
  return out;
}

long *per(long n, size_t *z) {
  *z = 0;
  // Dynamically allocate space for the array  
  long *arr = (long*)malloc(20 * sizeof(long));
  if(abs(n) > 9){
      long m = n;
      while(m > 9){ // While m is not a single digit
        m = multiply(m);  // Update m
        arr[(*z)++] = m; // Add the multiplied number to the array, then update z
      }
      return arr;
  }
    // If n is a single digit
    return NULL;
}
