// Let's say you start with this: "012345"
// The first thing you do is reverse it:"543210"
// Then you will take the string from the 1st position and reverse it again:"501234"
// Then you will take the string from the 2nd position and reverse it again:"504321"
// Then you will take the string from the 3rd position and reverse it again:"504123"
// Continue this pattern until you have done every single position, and then you will return the string you have created. 
// For this particular number, you would return:"504132"

#include <string.h>

void nreverse(char *str, int n, int size){
  char *ptr = str + n; // Points to the element at index n
  char *r_ptr = str + (size - 1); // Points to element at last index
  
  // Approach: Swap elements from each side
  for(int i = 0; i < (size-n)/2; i++, ptr++, r_ptr--){
    char temp = *ptr;
    *ptr = *r_ptr;
    *r_ptr = temp;
  }
}

void reverse(char *str) {
    int size = strlen(str);
    for(int i = 0; i <= size-2; i++){
      nreverse(str, i, size);
    }
}
