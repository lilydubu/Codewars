// Given a string of words, you need to find the highest scoring word.
// Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.
// You need to return the highest scoring word as a string.

#include <stdlib.h>
#include <string.h>

char  *highestScoringWord(const char *str)
{
  // Use const pointers to traverse the string and store places in the string w/o modifying
  const char *ptr = str;
  const char *best_word = ptr, *start = ptr;

  // Variables to keep track of the best word and the current word
  int best_score = 0, best_len = 0;
  int score = 0, len = 0;

  // While the character != '\0'
  while(*ptr){
    if(*ptr == ' '){ // If char is a space, we have reached the end of a word
      if(score > best_score){ // Check if the current word has the highest score
        best_score = score; 
        best_len = len;
        best_word = start;
      }
      start = ptr+1; // Move the start of the next word to the next char
      score = 0; // Reset score for next word
      len = 0; // Reset length for next word
    }
    else{ // If it's not a space then it would be a letter
      score += ((*ptr + 1) - 'a'); // Update the current word's score
      len++; // Update the current word's length
    }
    ptr++; // Move on to the next char
  }
  if(score > best_score){ // Check the last word's score
      best_score = score;
      best_len = len;
      best_word = start;
  }
  
  char *result = (char*)malloc((best_len+1) * sizeof(char)); // Create a variable to store the best word since best_word is just a pointer
  memcpy(result, best_word, (best_len) * sizeof(char)); // Copy best_word to the result
  result[best_len] = '\0'; // Terminate the string
  return result;
}
