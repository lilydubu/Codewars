// Write a function that takes in a string of one or more words, and returns the same string, 
// but with all words that have five or more letters reversed (Just like the name of this Kata). 
// Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

// My approach: Use a pointer to find the words and keep track of its length, then modify in place.

#include <string.h>
#include <stdio.h>

void reverse(char *start, char *end){
  char temp;
  for(; start < end; start++, end--){  // Switches char from each side
    temp = *start;
    *start = *end;
    *end = temp;
  }
}

void spin_words(const char *sentence, char *result) {
  memcpy(result, sentence, strlen(sentence) * sizeof(char)); // Copy sentence to result
  result[strlen(sentence)] = '\0'; // Terminate string
  
  char *ptr = result; // Will traverse the string (pointing to the start of the sentence initially)
  *start = result; // Keep track of the beginning of the word
  int len = 0; // Will count the length of each word
  
  while(*ptr){
    if(*ptr == ' '){ // Reached end of word
      if(len > 4) reverse(start, ptr-1); // Check if it should be reversed
      // Reset variables for next word
      len = 0;
      start = ptr + 1;
    }
    else{ // Still traversing the word
      len++; // Update the length of the word
    }
    ptr++; // Update the pointer to the next char
  }
  if(len > 4) reverse(start, ptr-1); // Handles the last word
}
