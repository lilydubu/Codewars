// Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements. (In place)

// 1st approach: If the current element is zero, swap with the next element. However, this does not work for adjacent zeroes.
// 2nd approach: Use two pointers, 1 for the place of the non-zero, then 2 for finding the next non-zero

#include <stddef.h>
void move_zeros(size_t len, int arr[len])
{
  // i is the pointer to non zeros, if i is a number move forward
  // j will move through the array, finding the non-zeroes
  int i = 0;
    for(size_t j = 0; j < len; j++){
      if(arr[i] != 0) i++;
      // if next element is 0, find the next non-zero
      else{
        if(arr[j] != 0){
          arr[i++] = arr[j];
          arr[j] = 0;
        }
      }
    }
}
