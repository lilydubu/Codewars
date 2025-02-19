// Write a function that takes in a string of one or more words, and returns the same string, 
// but with all words that have five or more letters reversed (Just like the name of this Kata). 
// Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.

// My approach: Use a pointer to find the words and keep track of its length, then modify in place.

#include <string.h>
#include <stdio.h>

void reverse(char *start, char *end){
  char temp;
  for(; start < end; start++, end--){
    temp = *start;
    *start = *end;
    *end = temp;
  }
}

void spin_words(const char *sentence, char *result) {
  memcpy(result, sentence, strlen(sentence) * sizeof(char)); // Copy the sentence to result
  result[strlen(sentence)] = '\0'; // Make sure to terminate the string
  
  char *ptr = result; // Pointer used to traverse the string
  char *start = result; // Pointer to keep track of beginning of word
  int len = 0; // Used to keep track of the length of each word

  // While the ptr is pointing to a character
  while(*ptr){
    // Go through the string until we find a space (this marks the end of the word)
    if(*ptr == ' '){
      // Check the length, reverse if it's at least 5 characters
      if(len >= 5){
        reverse(start, (ptr - 1));
      }
      // Update the start of the next word
      start = ptr + 1;
      // Reset the length for the next word
      len = 0;
    } else{
      // If space not encountered, continue traversing the string
      // And update the length of the current word
      len++;
    }
    // Move the pointer to the next character
    ptr++;
  }
  // When we reach end of the word, check the length of the last word
  if(len >= 5){
    reverse(start, (ptr - 1));
  }
    
}
