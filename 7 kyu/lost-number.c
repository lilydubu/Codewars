// An ordered sequence of numbers from 1 to N is given. One number might have deleted from it, 
// then the remaining numbers were mixed. Find the number that was deleted.

// Solution: Sort the mixed array, then compare each element with the original array. If it doesn't match return the element at the original array.

#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int find_deleted_number(const int arr[], size_t arr_sz, const int mix_arr[], size_t mix_sz)
{
  int *mixed = (int*)malloc(mix_sz * sizeof(int));
  
  if((arr_sz != mix_sz) && arr_sz != 0){
    
    memcpy(mixed, mix_arr, mix_sz * sizeof(int));
    qsort(mixed, mix_sz, sizeof(int), compare);
    
    for(size_t i = 0; i < mix_sz; i++){
      if(arr[i] != mixed[i]) {
        return arr[i];
      }
    }
    // If the missing number is the biggest
    return arr[arr_sz - 1];
  }
  return 0; 
}
