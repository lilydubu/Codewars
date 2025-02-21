// Given a code in the form of an array of Strings, return a single String representing the meaning of the code found through mewing it.
// Each character in the output string is the average of the corresponding characters in the input strings.
// Spaces are given a value of 0. Letters are given a value equal to their alphabetical index. a = 1, b = 2, c = 3, and so on.

#include <stddef.h>
#include <string.h>
#include <ctype.h>

void decipher(size_t length, const char * const code[length], char *mew) {
  int sum;
  size_t string = strlen(code[0]);
  
  // Go through each character
  for(size_t i = 0; i < string; i++){
    sum = 0;
  
    // Add up the chars of each index
    for(size_t j = 0; j < length; j++){
      if(isalpha(code[j][i])) sum += code[j][i] - 'a' + 1;
    }
    sum = (sum/length) + 'a' - 1;
    mew[i] = isalpha(sum) ? sum : 32;
  }
  mew[string] = '\0';
}
