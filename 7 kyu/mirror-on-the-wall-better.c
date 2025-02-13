// You get a list of integers, and you have to write a function mirror that returns the "mirror" (or symmetric) version of this list: 
// i.e. THE MIDDLE ELEMENT IS THE BIGGEST, then the next greatest on both sides, then the next greatest, and so on...

// Changes:
// 1. Use memcpy instead of manually copying the data array
// 2. Copy straight to the results
// 3. Sort in ascending order
// 4. From the end to the middle+1, copy elements from the first index up to middle-1

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// Helper for qsort 
int compare(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

void mirror(const int *data, size_t n, int *result) {
  // Use memcpy to copy the data array to the result array 
  // Note: the result array CAN be modified

  // Usage: destination, source, size in bytes
  memcpy(result, data, n * sizeof(int);

  // Sort in ASCENDING order, from here the result is already set until the middle
  qsort(result, n, sizeof(int), compare);

  // Fill in the elements from n to 2*n-2
  for(size_t i = 0; i < n-1; i++){
    // From the end to nth, fill in using elements from 0th index
    result[2*n-i-2] = result[0];
  }
}
