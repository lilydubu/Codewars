#include <stdlib.h>
#include <stdio.h>

char *range_extraction(const int *args, size_t n){
  char *string = calloc(n*4, sizeof(char)); // Use calloc so we don't have to manually terminate string
  char *ptr = string; // Points to beginning of string
  for(size_t i = 0; i < n; i++){
    if(i != 0) *ptr++ = ','; // Add comma after the previous iteration
    int first = args[i]; // Save the potential first number of the range
    int offset = 1; // Counts the length of the range
    // Checks if the next element is subsequent and updates the offset
    for(size_t j = i + 1; j < n && args[j] == first + offset; j++, offset++);
    ptr += sprintf(ptr, "%d", first); // Add the first number to the string and update the pointer forward
    if(offset > 2) ptr += sprintf(ptr, "-%d", args[i += offset-1]); // If range is at least 3, add the last element of the range to the string and update the i
  }
  return string;
}
