// Write a function which converts the input string to uppercase.

#include <ctype.h>
#include <string.h>
char *makeUpperCase (char *string)
{
  // Note: 
  // int len = sizeof(string) / sizeof(string[0];
  // will not work as string is only a pointer to a char
  
  int len = strlen(string);
  for(int i = 0; i < len; i++) {
    if(isalpha(string[i])) string[i] = toupper(string[i]);
  }

  // Alternatively:
  // for(char *ptr = string; *ptr; ptr++){
  //   *ptr = toupper(*ptr);
  // }
  
  return string;
}


