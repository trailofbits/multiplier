#include <string.h>

#define GET_LEN(a) strlen(a)

void test1(char *argument) {
    int len0 = strlen(argument);
    size_t len1 = strlen(argument);
    
    unsigned int len2 = GET_LEN(argument);
}