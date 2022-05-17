#include <stdio.h>
#include "character_strings.h"
#include "conversions.h"
#include "decode.h"

#define MAX_TOKEN_NR 3 //maksymalna dopuszczalna ilosc tokenow
#define MAX_KEYWORD_NR 3
#define NULL 0

Token sToken[MAX_TOKEN_NR]; //Tablica ktorej pod ktorej indexem znajduja sie 2 elementy (Kazdy element tablicy jest struktura, ktora sklada sie z 2 elementow enum i union) 
unsigned char ucTokenNr;

Keyword sKeywordList[MAX_KEYWORD_NR] = //to jest slownik tak jakby
{
    {RST, "reset"},
    {LD, "load"},
    {ST, "store"}
};


unsigned char ucFindTokenInString(char* pcString)
{
    enum State {TOKEN, DELIMITER};
    enum State eState = TOKEN;

    unsigned char ucCurrentCharacter;
    unsigned char ucCharCounter;
    ucTokenNr = 0;

    for(ucCharCounter = 0 ;; ucCharCounter++)
    {
        ucCurrentCharacter = pcString[ucCharCounter];
        switch(eState)
        {
        case TOKEN:
            if(ucCurrentCharacter == NULL)
            {
                return ucTokenNr;
            } 
            else if(ucCurrentCharacter != ' ') 
            {
                sToken[ucTokenNr++].uValue.pcString = &pcString[ucCharCounter];
            }
            eState = DELIMITER;
        break;
        
        case DELIMITER:
            if(ucCurrentCharacter == NULL)
            {
                return ucTokenNr;
            } 
            else if(ucCurrentCharacter == ' ')
            {
                eState = TOKEN;
            }
        break;

        }
    }
}

enum Result eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode)
{
    unsigned char ucKeywordIndex;
    for(ucKeywordIndex = 0; ucKeywordIndex < MAX_KEYWORD_NR; ucKeywordIndex++)
    {
        if(EQUAL == eCompareString(sKeywordList[ucKeywordIndex].cString, pcStr))
        {
            *peKeywordCode = sKeywordList[ucKeywordIndex].eCode;
            return OK;
        }
    }
    return ERROR;
}

void DecodeTokens(void)
{
    
    //  [ uValue: pcString = 'loadNULL0x12NULLeax']
    //  uValue: pcString = '0x12NULLeax']
    //  uValue: pcString = 'eax']
    unsigned char ucTokenCounter;
    unsigned int uiTokenValue;
    KeywordCode eTokenCode;



    for(ucTokenCounter = 0; ucTokenCounter < ucTokenNr; ucTokenCounter++)
    {   
        // if pr�ba zamiany tokenu na keyword zwroci ERROR to spr�bujmy zamienic to na inta
        // if pr�ba zamiany na token zwr�ci OK to znaczy= ze to jest token
        // if zamiana na inta zwr�ci ERROR to zakladamy ze jest to zwyk� string (trzecia czesc tokenu)
        // if zamiana na inta zwr�ci OK to zakladamy ze jest to 0x12
        if(OK == eStringToKeyword(sToken[ucTokenCounter].uValue.pcString, &eTokenCode)) {
            sToken[ucTokenCounter].uValue.eKeyword = eTokenCode;
            sToken[ucTokenCounter].eType = KEYWORD;
            continue;
        }

        if(OK == eHexStringToUInt(sToken[ucTokenCounter].uValue.pcString, &uiTokenValue)) {
            // sToken[ucTokenCounter].uValue.eKeyword = sToken[ucTokenCounter].eType;
            sToken[ucTokenCounter].uValue.uiNumber = uiTokenValue;
            sToken[ucTokenCounter].eType = NUMBER;
            continue;
        }
        
        sToken[ucTokenCounter].eType = STRING;
    }
}



void DecodeMsg(char* pcString) //Za kazdym jesli zmieniamy wartosc pcString za pomoca wskaznika to modyfikujemy to na co on wskazuje 
{                              // Czyli jesli funkcja pozmienia cos w wskazniku to bedziemy miec to pozmieniane w innych wskaznikach
                              // ktore wskazuja na to samo miejsce w pamieci
                              
    ucFindTokenInString(pcString);
    // [ uValue: pcString = 'load 0x12 eax']
    //  uValue: pcString = '0x12 eax']
    //  uValue: pcString = 'eax']
    //printf("TEST REPLACE %s\n", pcString);
    ReplaceCharactersInString(pcString, ' ', NULL);
    
    //printf("TEST REPLACE %s\n", pcString);
    DecodeTokens();
    //TAK MA DZIALAC TA FUNKCJA
    //  uValue: pcString = 'loadNULL0x12NULLeax']
    //  {eType:KEYWORD ,uValue: {eKeyword = LD}  }
    //  {eType: NUMBER, uValue: {uiNumber = 18}}
    //  {eType: STRING, uValue: {pcString = 'eax'}}

    // eStringToKeyword()
     //uValue: pcString = '0x12NULLeax']
     //uValue: pcString = 'eax']  
}



int main() 
{
//FindToken
   //int ResultFindToken = ucFindTokenInString("load 0x12 eax");


//eStringToKeyword
	/*enum KeywordCode MyTokenCode;
	unsigned int Load = eStringToKeyword("load", &MyTokenCode); //0
	unsigned int Store = eStringToKeyword("store", &MyTokenCode); //1 
	unsigned int Reset = eStringToKeyword("reset", &MyTokenCode); //2
*/

	//DecodeMsg
	
	/*char tab[] = {"store 0x12 eax"};
	KeywordCode TokenKey;
	unsigned int TokenNumber;
	char* TokenString;
	
	KeywordCode Test = ST;
	DecodeMsg(tab);
	TokenKey = sToken[0].uValue.eKeyword;
	TokenNumber = sToken[1].uValue.uiNumber;
	TokenString = sToken[2].uValue.pcString;
	*/
	


}