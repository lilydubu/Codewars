// You must concatenate the nth letter from each word to construct a new word which should be returned as a string, where n is the position of the word in the list.
// Solution: Iterate through each string, assign the ith element of str_out to the ith string's ith character

#include <stddef.h>
#include <string.h>

char *nth_char(size_t length, const char *const strings[length],
                char str_out[length + 1])
{
    for(size_t i = 0; i < length; i++){
      str_out[i] = strings[i][i];
    }
    str_out[length] = '\0';
    return str_out;
}
