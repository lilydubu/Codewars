#include <stdlib.h>
#define MAX 1000

int convert(int n, char *string, int index);
void reverse(char* string, int start, int end);

char *range_extraction(const int *args, size_t n) {

    char *string = malloc(MAX * sizeof(char)); // Output string
    size_t i = 0;
    int index = 0;

    while (i < n) {
        size_t start = i;

        // Count consecutive numbers
        while (i + 1 < n && args[i + 1] - args[i] == 1) {
            i++;
        }

        size_t len = i - start + 1;

        if (len >= 3) { // If at least 3 consecutive numbers
            index = convert(args[start], string, index); // First number
            string[index++] = '-';
            index = convert(args[i], string, index); // Last number
            if (i < n-1) string[index++] = ',';
        } else { // Individual numbers or pairs
            for (size_t j = start; j <= i; j++) {
                index = convert(args[j], string, index);
                if (j < n-1) string[index++] = ','; // Add commas except for last element
            }
        }

        i++; // Move to the next number
    }

    string[index] = '\0'; // Null-terminate the string
    return string;
}

int convert(int n, char* string, int index){
  if(n < 0) string[index++] = '-';
  if(n == 0) string[index++] = '0';
  int start = index;
  while(n != 0){
    string[index++] = (abs(n % 10)) + '0';
    n = n/10;
  }
  int end = index-1;
  reverse(string, start, end);
  return index; // Update the string's ending index
}

void reverse(char *string, int start, int end){
  int temp;
  while(start < end){
    temp = string[start];
    string[start++] = string[end];
    string[end--] = temp;
  }
}

// Imagine if I used sprintf XDDDDDDDDDDDDDDDDD
