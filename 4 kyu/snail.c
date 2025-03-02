#include <stdlib.h>

// The numbers of rows and cols are passed separately for historical reasons
// Return a heap allocated array, report the size in *outsz

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
  int *spiral = calloc((rows*cols), sizeof(int)); // 1D array
  int top = 0, left = 0;
  int bottom = rows - 1, right = cols - 1;
  *outsz = rows * cols;
  
  int index = 0;
  while(top <= bottom && left <= right){
    // Left to right (From the top)
    for(int i = left; i <= right; i++){
      spiral[index++] = mx[top][i];
    }
    top++; // Move the top since top layer is fully traversed
    
    // Top to bottom (From the right side)
    for(int i = top; i <= bottom; i++){
      spiral[index++] = mx[i][right];
    } 
    right--; // Move the right side since right side is fully traversed
    
    // Right to left (From bottom)
    for(int i = right; i >= left; i--){
      spiral[index++] = mx[bottom][i];
    }
    bottom--; // Move the bottom pointer since bottom layer is fully traversed
    
    // Bottom to top
    for(int i = bottom; i >= top; i--){
      spiral[index++] = mx[i][left];
    }
    left++; // Move the left pointer since left side is fully traversed
  }
  return spiral;
}
