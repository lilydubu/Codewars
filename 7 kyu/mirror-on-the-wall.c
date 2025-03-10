// You get a list of integers, and you have to write a function mirror that returns the "mirror" (or symmetric) version of this list: 
// i.e. THE MIDDLE ELEMENT IS THE BIGGEST, then the next greatest on both sides, then the next greatest, and so on...

// First INSANE solution (idk what i was thinking): 
// 1. Sort the copied array in reverse order
// 2. Copy the sorted array to the results starting from the end (so from the smallest) 😭
// 3. Starting from the nth index until the 2*n-2th index, copy from the sorted array (from the 2nd biggest)

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Helper for qsort to compare each int
int compare(const void*a, const void*b){
  return *(int*)b - *(int*)a ;
}

void mirror(const int *data, size_t n, int *result) {
  // Create variable to copy the array since we cannot modify the original array
  int sorted[n];

  // Copy the array
  for(size_t i = 0; i < n; i++){
    sorted[i] = data[i];
  }

  // Sort the array
  qsort(sorted, n, sizeof(data[0]), compare);

  // From the sorted array, copy the elements to the results in reverse
  for(size_t i = 0; i < n; i++){
    result[i] = sorted[n-1-i];
  }
  // Skip the middle/largest element
  // Copy the elements in order, starting from the nth index
  for(size_t i = n, j = 1; i < (n*2)-1; i++, j++){
    result[i] = sorted[j];
  }
}
