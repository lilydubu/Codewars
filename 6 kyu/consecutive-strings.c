// You are given an array(list) strarr of strings and an integer k. 
// Your task is to return the first longest string consisting of k consecutive strings taken in the array.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *longestConsec (const char *const strings[/*arr_len*/], int arr_len, int k)
{
  // For invalid input (not using strdup cos it gives me errors)
  if(arr_len == 0 || k == 0 || k > arr_len){
    char *none = malloc(1);
    none[0] = '\0';
    return none;
  }
  
  int sum = 0;
  int lengths[arr_len];
  
  // Get the lengths, and the first sum of k elements
  for(int i = 0; i < arr_len; i++){
    lengths[i] = strlen(strings[i]);
    if(i < k)  sum += lengths[i];
  }
  
  int most_sum = sum, most_i = 0;
  
  // Get the sum of each consecutive k elements by subtracting the front element's length and adding the next
  for(int i = 1; i <= arr_len - k ; i++){
    sum += lengths[k+i-1] - lengths[i-1];
    if(sum > most_sum){most_sum = sum, most_i = i;}
  }
  
  // Create string of consecutive strings
  char *result = (char*)calloc(most_sum + 1, sizeof(char)); // Use calloc to initialize the string
  for(int i = most_i; i < most_i + k; i++){
    strcat(result, strings[i]); // Concatenate the strings 
  }
  result[most_sum] = '\0'; // Terminate the string
  return result;
}
