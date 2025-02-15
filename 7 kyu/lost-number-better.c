// An ordered sequence of numbers from 1 to N is given. One number might have deleted from it, 
// then the remaining numbers were mixed. Find the number that was deleted.

// Found this solution and thought it was clever and fitting since only one number would be deleted.
// Approach: Sum up the original array, then subtract the mixed array, return the sum.

#include <stdlib.h>

int find_deleted_number(const int arr[], size_t arr_sz, const int mix_arr[], size_t mix_sz)
{
  int sum = 0;  
  for(size_t i = 0; i < arr_sz; i++) sum += arr[i];
  for(size_t i = 0; i < mix_sz; i++) sum -= mix_arr[i];
  return sum;
}
