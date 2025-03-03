// My approach: Go through each neigboring side and count the live neighbors.
// If the current cell is alive, it will die if the live neighbors is < 2 or > 3.
// If current cell is dead, and live neighbors is 3, it will revive.

#include <stddef.h>
#include <stdbool.h>

void evolve (size_t rows, size_t cols, const bool cur_gen[rows][cols], bool next_gen[rows][cols])
{
  int live_neighbors;
  size_t left, right, top, bottom;
  bool verdict;
  
  // Access each cell
  for(size_t i = 0; i < rows; i++){
    for(size_t j = 0; j < cols; j++){
      // Set the counter for the neighbors
      live_neighbors = 0;
      
      // Set the cell's neigbors
      left = j != 0 ? j -1 : j;
      right = (j + 1) < cols ? j + 1 : j;
      top = i - 1;
      bottom = i + 1;
      
      // Top neighbors
      if(i != 0){
        for(size_t k = left; k <= right; k++) 
          if(cur_gen[top][k] == 1) live_neighbors++;
      }
      
      // Left neighbors
      if(j != 0){
        if(cur_gen[i][left] == 1) live_neighbors++;
      }

      // Right neighbors
      if(j != cols - 1){
        if(cur_gen[i][right] == 1) live_neighbors++;
      }

      // Bottom neighbors
      if(i != rows - 1){
        for(size_t k = left; k <= right; k++) 
          if(cur_gen[bottom][k] == 1) live_neighbors++;
      }
      verdict = ((cur_gen[i][j] == 1 && live_neighbors == 2) || live_neighbors == 3) ? 1 : 0;
      next_gen[i][j] = verdict;
    }
  }
}
