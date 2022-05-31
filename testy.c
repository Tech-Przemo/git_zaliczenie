#include <stdio.h>
#include <string.h>
#include "character_strings.h"
#include "conversions.h"
#include "decode.h"

#define MAX_TOKEN_NR 3

extern Token sToken[MAX_TOKEN_NR];

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


//----------------------------KONWERSJE------------------------------------------------
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

//--------------------------------DEKODOWANIE------------------------------------
void TestOf_ucFindTokensInString(void)
{
    unsigned int uiTokenNumber; //Zmienna pomocnicza
    
    printf("TestOf_ucFindTokensInString\n");

    printf("Test 1 - ");
    //Tylko delimitery -> test odpornosci funkcji
    uiTokenNumber = ucFindTokenInString("   ");
    if(uiTokenNumber == 0)
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }

    printf("Test 2 - ");
    //Delimitery przed pierwszym tokenem
   uiTokenNumber = ucFindTokenInString("  load 0x12 eax");
    if(uiTokenNumber == 3)
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }

    printf("Test 3 - ");
    //Wiecej niz jeden delimiter pomiędzy tokenami
    uiTokenNumber = ucFindTokenInString("load  0x12  eax");
    if(uiTokenNumber == 3)
    {
        printf("OK\n");
        uiTokenNumber = 0;
    }
    else
    {
        printf("ERROR\n");
        
    }

    printf("Test 4 - ");
    //Delimitery przed pierwszym tokenem i mniej tokenow niz MAX
    uiTokenNumber = ucFindTokenInString("  load 0x12");
    if(uiTokenNumber == 2)
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }

    printf("Test 5 - ");
    //Zbyt duza ilosc tokenow i ustawienie wskaznikow na poczatki 3 pierwszych tokenow 
    
    char cTestString[] = {"load 0x45 ABCDE eax"}; 
    uiTokenNumber = ucFindTokenInString(cTestString);
    if((uiTokenNumber == 3) && (&cTestString[0] == sToken[0].uValue.pcString) && (&cTestString[5] == sToken[1].uValue.pcString) 
    && (&cTestString[10] == sToken[2].uValue.pcString))
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    
    }

    printf("Test 6 - ");
    //Poprawny lancuch do dekodowania
    uiTokenNumber = ucFindTokenInString("reset 0x123 eax");
    if(uiTokenNumber == 3) 
    {
        printf("OK\n\n");
    }
    else
    {
        printf("ERROR\n");
    }
}

//------------------------------------------------------------------
void TestOf_eStringToKeyword(void)
{
    enum KeywordCode eTokenCode;
    printf("TestOf_eStringToKeyword\n");

    printf("Test 1 - ");
    //rozpoznanie slowa kluczowego w stringu - poprawne slowo kluczowe
    if(eStringToKeyword("load", &eTokenCode) == OK) //jako lancuch wystarczy tylko kod slowa kluczowego
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }

    printf("Test 2 - ");
    //rozpoznanie slowa kluczowego w stringu - niepoprawne slowo
    if(eStringToKeyword("brum", &eTokenCode) == ERROR)
    {
        printf("OK\n\n");
    }
    else
    {
        printf("ERROR\n");
    }
}

//------------NIE DZIALA--------------------------
void TestOf_DecodeTokens(void)
{
    unsigned char ucTokenNumber;
    char cTestDecode[] = {"reset 0x45 abc"};
    printf("DecodeTokens\n");

    printf("Test 1 - ");
    //Zdekodowanie tokenu -> keyword i zapis kodu, liczba i jej zapis, string i ustawienie wskaznika na jego poczatek
    ucTokenNumber = ucFindTokenInString(cTestDecode);
    ReplaceCharactersInString(cTestDecode, ' ', NULL);
    DecodeTokens();
    if((ucTokenNumber == 3) && (sToken[0].eType == KEYWORD) && (sToken[0].uValue.eKeyword == RST)
    && (sToken[1].eType == NUMBER) && (sToken[1].uValue.uiNumber == 0x45)
    && (sToken[2].eType == STRING) && (sToken[2].uValue.pcString == &cTestDecode[11]))
    {
        printf("OK\n");
    }
    else
    {
        printf("ERROR\n");
    }
}

//---------------NIE DZIALA---------------------------------
void TestOf_DecodeMsg(void)
{
    char cStringToDecode[] = {"load 0x12 eax"};

    printf("DecodeMsg\n");

    printf("Test 1 - ");
    //keyword, liczba, string 
    DecodeMsg(cStringToDecode);
    if((sToken[0].eType == KEYWORD) && (sToken[0].uValue.eKeyword == LD)
    && (sToken[1].eType == NUMBER) && (sToken[1].uValue.uiNumber == 0x12)
    && (sToken[2].eType == STRING) && (strcmp("eax", sToken[2].uValue.pcString) == 0))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("ERROR\n");
    }
}



int main(void)
{
    printf("\nTESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n");

    TestOf_CopyString();
    TestOf_eCompareString();
    TestOf_AppendString();
    TestOf_ReplaceCharactersInString();

    printf("\n\nTESTY FUNKCJI: KONWERSJE \n\n\n");
    
    TestOf_UIntToHexStr();
    TestOf_eHexStringToUInt();
    TestOf_AppendUIntToString();

    printf("\n\nTESTY FUNKCJI: DEKODOWANIE \n\n\n");
    
    TestOf_ucFindTokensInString();
    TestOf_eStringToKeyword();
    TestOf_DecodeTokens();
    TestOf_DecodeMsg();
}
