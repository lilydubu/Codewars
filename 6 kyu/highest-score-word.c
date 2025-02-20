// Given a string of words, you need to find the highest scoring word.
// Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.
// You need to return the highest scoring word as a string.

#include <stdlib.h>
#include <string.h>

char  *highestScoringWord(const char *str)
{
  const char *ptr = str; // Used to traverse the string
  const char *best_word = ptr; // Used to remember the address of the best word
  const char *start = ptr; // Used to remember the beginning of the current word
  
  int best_score = 0, best_len = 0; // Best word variables
  int score = 0, len = 0; // Current word variables
  
  for(int i = 0; i <= (int)strlen(str); i++, ptr++){ // Loop until the  '\0'
    // If the current char is not a letter, we have reached the end of the word
    if(*ptr == ' ' || *ptr == '\0'){
      // Check for highest score and update best_word
      if(score > best_score){ best_score = score,  best_len = len, best_word = start;}
      // Update variables for the next word
      start = ptr+1, score = 0, len = 0;
    }
    else{
      // Update variables for current word
      score += *ptr - 'a' + 1, len++;
    }
  }
  
  char *result = (char*)malloc((best_len+1) * sizeof(char)); // Dynamically allocate space for result string
  if (!result) return NULL; // Check for allocation failure
  memcpy(result, best_word, (best_len) * sizeof(char)); // Copy best_word
  result[best_len] = '\0'; // Terminate the string
  return result;
}
