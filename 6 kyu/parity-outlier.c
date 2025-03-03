// The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer, return the outlier.

// My approach: Determine the majority element, if even > odd then find and return the odd number, vice versa. 
// Time complexity: O(n + 3)

// Better approach: Have a counter for either even or odd. Save the current odd/even number. If the counter == 1, then return that number.
// Example: {1, 2, 0, 1, 0, 1, 0, 3, 0, 1} -> evenCounter = 1, evenNumber = 2, oddNumber = 1; Since evenCounter == 1, return the even number;

#include <stddef.h>

int find_outlier(const int values[/* count */], size_t count)
{
  // Find majority
  int even = 0, odd = 0;
  for(int i = 0; i < 3; i++){
    if(values[i] % 2 == 0) even++;
    else odd++;
  }
  
  for(size_t i = 0; i < count; i++){
    // Find the odd
    if(even > odd){
      if(values[i] % 2 != 0) return values[i];
    } 
    // Find the even number
    else{
      if(values[i] % 2 == 0) return values[i];
    }
  }
  
  return 0;
}
