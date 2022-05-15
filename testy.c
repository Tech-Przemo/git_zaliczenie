#include <stdio.h>
#include <string.h>
#include "character_strings.h"
#include "conversions.h"

void TestOf_CopyString(void)
{
    printf("CopyString \n");

    printf("Test 1 - ");
    //Czy funkcja dziala (pierwszy krotszy, drugi dluzszy)
    char cAfterCopy_1[] = "test1234";
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

    printf("Test 4 - ");
    //Pierwszy lancuch pusty
    char cAfterCopy_4[] = "ABCDE";
    CopyString(" ", cAfterCopy_4);

    if(strcmp(" ", cAfterCopy_4) == 0)
        printf("OK\n\n");
    else
        printf("ERROR\n\n");

    //POWODZENIE
}

//----------------------------------------------
void TestOf_eCompareString(void)
{
    printf("eCompareString \n");

    printf("Test 1 -");
    //Lancuchy takie same
    
    if(eCompareString("ABCDE", "ABCDE") == 0)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");

    printf("Test 2 -");
    //Lancuchy rozne -> rozna długość (pierwszy dluzszy)
    
    if(eCompareString("ABCDE", "ABC") == 0)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");

    printf("Test 3 -");
    //Drugi lancuch dluzszy
    
    if(eCompareString("ABCDE", "XXYYZZZZZZZ") == 0)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");

    printf("Test 4 -");
    //Lancuchy rozne -> ta sama długość 
    
    if(eCompareString("ABCDE", "XXYYZ") == 0)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");
    
    printf("Test 5 -");
    //Pierwszy lancuch pusty 
    
    if(eCompareString(" ", "XXYYZ") == 0)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");

    printf("Test 6 -");
    //Dtugi lancuch pusty
    
    if(eCompareString("ABCDE", " ") == 0)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");
    
    printf("Test 7 -");
    //Oba lancuchy puste
    
    if(eCompareString(" ", " ") == 0)
        printf("EQUAL\n\n");
    else
        printf("DIFFERENT\n");

    //POWODZENIE
}

//------------------------------------------
void TestOf_AppendString(void)
{
    printf("AppendString \n");

    printf("Test 1 - ");
    //Test poprawnosci dzialania funkcji 
    char cStringTab_Test1[] = {"ZZZ"};
    
    AppendString("XXX", cStringTab_Test1);

    if(strcmp("ZZZXXX", cStringTab_Test1) == 0)
    {
        printf("OK\n");
        printf("AppendString result Test_1: %s\n", cStringTab_Test1);  //zeby wyswietlic string uzywamy %s
    }
    else
        printf("ERROR\n");
        
    printf("Test 2 - ");
    //Pierwszy lancuch pusty
    char cStringTab_Test2[] ={"XXX"};
    
    AppendString("", cStringTab_Test2);

    if(strcmp("XXX", cStringTab_Test2) == 0)
    {
        printf("OK\n");
        printf("AppendString result Test_2: %s\n", cStringTab_Test2);
    } 
    else
        printf("ERROR\n");
        

    printf("Test 3 - ");
    //Drugi lancuch pusty
    char cStringTab_Test3[] ="";
    
    AppendString("XXYYZZ", cStringTab_Test3);

    if(strcmp("XXYYZZ", cStringTab_Test3) == 0)
    {
        printf("OK\n");
         printf("AppendString result Test_3: %s\n\n", cStringTab_Test3); 
    }
    else
        printf("ERROR\n\n");
       
    
    //POWODZENIE
}

//----------------------------------------
void TestOf_ReplaceCharactersInString(void)
{
    printf("ReplaceCharactersInString \n");

    printf("Test 1 - ");
    //Test poprawnosci dzialania funkcji -> rozne znaki
    char cString_Test1[] = {"XXXX"};
    ReplaceCharactersInString(cString_Test1, 'X', 'Z');
    
    if(strcmp(cString_Test1, "ZZZZ") == 0)
    {
        printf("OK\n");
        printf("ReplaceCharactersInString result Test_1: %s\n", cString_Test1);
    }
    else
        printf("ERROR\n");
        
    
    printf("Test 2 - ");
    //Spacja na NULL
    char cString_Test2[] = {"Znaki do zmiany"};
    ReplaceCharactersInString(cString_Test2, ' ', '\0');
    
    if(strcmp(cString_Test2, "Znaki\0do\0zmiany") == 0)
    {
        printf("OK\n");
        printf("ReplaceCharactersInString result Test_2: %s\n", cString_Test2);
    }
    else
        printf("ERROR\n\n");
    
    //POWODZENIE
}

//-------------------------------------------------------
void TestOf_UIntToHexStr(void)
{
    printf("UIntToHexStr \n");

    printf("Test 1 - ");
    //Sprawdzenie poprawnosci dzialania funkcji
    char cHexString[10];
    UIntToHexStr(43981, cHexString);

    if(strcmp(cHexString, "0xABCD") == 0)
    {
        printf("OK\n");
        printf("UIntToHexString result: %s\n\n", cHexString);
    }
    else
        printf("ERROR\n");
    
    //POWODZENIE
}

//---------------------------------
void TestOf_eHexStringToUInt(void)
{
    enum Result eReturnResult;
    unsigned int uiValue;

    printf("TestOf_eHexStringToUInt \n");

    printf("Test 1 - ");
    //Zamiana duzych liter
    eReturnResult = eHexStringToUInt("0xABCD", &uiValue);

    if(eReturnResult == OK)
    {
        printf("OK\n");
        uiValue = 0;
    }
    else
        printf("ERROR\n");
    
    printf("Test 2 - ");
    //Zamiana malych liter
     eReturnResult = eHexStringToUInt("0xabcd", &uiValue);

     if(eReturnResult == ERROR)
    {
        printf("OK\n");
        uiValue = 0;
    }
    else
        printf("ERROR\n");

    printf("Test 3 - ");
    //lancuch za krotki
     eReturnResult = eHexStringToUInt("0x", &uiValue);

     if(eReturnResult == ERROR)
    {
        printf("OK\n");
        uiValue = 0;
    }
    else
        printf("ERROR\n");

    printf("Test 4 - ");
    //lancuch za dlugi
     eReturnResult = eHexStringToUInt("0xABCDEFG", &uiValue);

     if(eReturnResult == ERROR)
    {
        printf("OK\n");
        uiValue = 0;
    }
    else
        printf("ERROR\n");

    printf("Test 5 - ");
    //Zly format lancucha
     eReturnResult = eHexStringToUInt("0zABCD", &uiValue);

     if(eReturnResult == ERROR)
    {
        printf("OK\n");
        uiValue = 0;
    }
    else
        printf("ERROR\n");
    
    printf("Test 6 - ");
    //mniejsza liczba w lancuchu
     eReturnResult = eHexStringToUInt("0x3", &uiValue);

     if(eReturnResult == OK)
    {
        printf("OK\n\n");
        uiValue = 0;
    }
    else
        printf("ERROR\n");
    
    //POWODZENIE
}

//-------------------------------------------------------
void TestOf_AppendUIntToString(void)
{
    printf("TestOf_AppendUIntToString\n");

    printf("Test 1 - ");
    //Test poprawnosci dzialania funkcji
    unsigned int uiNumber_Test1 = 43981;
    char cString_Test1[] = {"test"};
    AppendUIntToString(uiNumber_Test1, cString_Test1);

    if(strcmp(cString_Test1, "test0xABCD") == 0)
        printf("OK\n");
    else
        printf("ERROR\n");
    
    printf("Test 2 - ");
    //Pusty String
    unsigned int uiNumber_Test2 = 43981;
    char cString_Test2[] = {""};
    AppendUIntToString(uiNumber_Test2, cString_Test2);

    if(strcmp(cString_Test2, "0xABCD") == 0)
        printf("OK\n");
    else
        printf("ERROR\n");
    
    printf("Test 3 - ");
    //Liczba 0 przy niepustym stringu
    unsigned int uiNumber_Test3 = 0;
    char cString_Test3[] = {"test"};
    AppendUIntToString(uiNumber_Test3, cString_Test3);

    if(strcmp(cString_Test3, "test0x0000") == 0)
        printf("OK\n");
    else
        printf("ERROR\n");

    printf("Test 4 - ");
    //Liczba 0 przy pustym stringu
    unsigned int uiNumber_Test4 = 0;
    char cString_Test4[] = {""};
    AppendUIntToString(uiNumber_Test4, cString_Test4);
    
    if(strcmp(cString_Test4, "0x0000") == 0)
        printf("OK\n");
    else
        printf("ERROR\n");
    
    //POWODZENIE
}

int main(void)
{
    //printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n");

    // TestOf_CopyString();
    // TestOf_eCompareString();
    // TestOf_AppendString();
    // TestOf_ReplaceCharactersInString();

    //printf("TESTY FUNKCJI: KONWERSJE \n\n\n");
    //TestOf_UIntToHexStr();
    //TestOf_eHexStringToUInt();
    TestOf_AppendUIntToString();
}
