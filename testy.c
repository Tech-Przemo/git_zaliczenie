#include <stdio.h>
#include <string.h>
#include "character_strings.h"
#include "conversions.h"

void TestOf_CopyString(void)
{
    printf("CopyString \n\n");

    printf("Test 1 - ");
    //Czy funkcja dziala 
    char cAfterCopy_1[] = "test1";
    CopyString("abcd", cAfterCopy_1);
    
    if(strcmp("abcd", cAfterCopy_1) == 0)
        printf("OK\n");
    else
        printf("ERROR\n");

    printf("Test 2 - ");
}


int main(void)
{
    TestOf_CopyString();
}
