#include <stdio.h>
#include <string.h>
#include "character_strings.h"
#include "conversions.h"

void TestOf_CopyString(void)
{
    printf("CopyString \n\n");

    printf("Test 1 - ");
    //Czy funkcja dziala (pierwszy dluzszy, drugi krotszy)
    char cAfterCopy_1[] = "test1";
    CopyString("abcd", cAfterCopy_1);
    
    if(strcmp("abcd", cAfterCopy_1) == 0)
        printf("OK\n");
    else
        printf("ERROR\n");

    printf("Test 2 - ");
    //Pierwszy lancuch dluzszy drugi krotszy
    char cAfterCopy_2[] = "test2";
    CopyString("ABCDEFG", cAfterCopy_2);

    if(strcmp("ABCDEFG", cAfterCopy_2) == 0)
        printf("OK\n");
    else
        printf("ERROR\n");

    printf("Test 3 - ");
    //Lancuchy tej samej dlugosci 
    char cAfterCopy_3[] = "test3";
    CopyString("ABCDE", cAfterCopy_3);

    if(strcmp("ABCDE", cAfterCopy_3) == 0)
        printf("OK\n");
    else
        printf("ERROR\n");
}


int main(void)
{
    TestOf_CopyString();
}
