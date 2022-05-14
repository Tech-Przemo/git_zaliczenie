#include <stdio.h>
#include "conversions.h"

#define NULL 0 
#define MAX_STRING_SIZE 6
#define NIBBLE_MASK 0x000F
#define ASCII_CHAR_A 65
#define ASCII_ZERO 48

void UIntToHexStr(unsigned int uiValue, char pcStr[])
{
    unsigned int uiCurrentNibble;
    unsigned int uiNibbleCounter;
    
    //Przypisanie stalych znakow w tablicy -> literały 
	pcStr[0] = '0'; 
    pcStr[1] = 'x';
    pcStr[6] = NULL;

    for(uiNibbleCounter = 0; uiNibbleCounter < 4; uiNibbleCounter++ )
    {
        uiCurrentNibble = uiValue >> (4*uiNibbleCounter) & NIBBLE_MASK; //to 0x000F jest po to aby do uiActualValue nie weszly nam smieci, czyli na tym czym nie pracujemy
        if(uiCurrentNibble<10) // 0-9															// Interesuje nas ta skrajna tetrada, reszta niezbyt 
        {
            pcStr[5 - uiNibbleCounter] = '0' + uiCurrentNibble;
        }
        else 
        {
            pcStr[5 - uiNibbleCounter] = 'A' + (uiCurrentNibble - 10); // Przesuniecie '10' w ASCII o aktualna wartosc czyli A-F
        }																														// Nie mo|emy tu dac '0' + uiActualValue, bo HEX ma znaki od 0-9 i A-F 
    }																																// Wiec jesli do '0' dodamy 10 to on nie zrozumie ~ tak mi sie wydaje, wychodzimy poza zakres		
}


enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue)
{
  unsigned int uiCharCounter;
  unsigned char ucCurrentChar;
  //unsigned int uiActualDecimalValue;
	
	*puiValue = 0; //zerujemy wskaznik aby nie bylo w nim zadnych smieci 
	
	if((pcStr[0] != '0') || (pcStr[1] != 'x') || (NULL == pcStr[2] )) //wymusic kolejnosc operatorow, ostatni warunek jest zly bo nie wiemy co na tym miejscu bedzie
	{
		return ERROR;
	}

	for(uiCharCounter = 2;  NULL != pcStr[uiCharCounter]; uiCharCounter++)
    {
		if(uiCharCounter == MAX_STRING_SIZE) //Sprawdzenie czy string ma odpowiednia dlugosc
		{
			*puiValue = 0;
			return ERROR;
		}
				
		*puiValue = *puiValue << 4; //Przesuwamy w lewo gdyz najpierw odczytujemy MSB
        
		ucCurrentChar = pcStr[uiCharCounter]; //Przypisanie danego elementu tablicy do zmiennej

    if(ucCurrentChar >= '0' && ucCurrentChar <= '9')
    {
        *puiValue = *puiValue | (ucCurrentChar - ASCII_ZERO); //48
    }
    else if(ucCurrentChar >= 'A' && ucCurrentChar <= 'F')
    {
        *puiValue = *puiValue | (ucCurrentChar - ASCII_CHAR_A + 10) ; //Zamiana Char na Int, znak 'A' ma wartosc 65 wiec 65 - 55 = 10 -> nasza wartosc w INT   
    }
    else
    {
				*puiValue = 0;
         return ERROR;
    }

        //*puiValue = *puiValue | uiActualDecimalValue; //Przypisujemy do wskaznika wartosc LSB
     
    }
		return OK;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[])
{
    unsigned char ucCharCounter;
    for(ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL; ucCharCounter++){}
    UIntToHexStr (uiValue, &pcDestinationStr[ucCharCounter]); //Pobieramy sobie adres konca tablicy, czyli adres indeksu na ktorym wystepuje NULL  
}

// int main ()
// {
// 	//UIntToHexStr
// 	/*char pcTab[7];
// 	unsigned int uiWartosc = 43981;
// 	UIntToHexStr(uiWartosc, pcTab); 
// 	*/

// 	//eHexStringToUInt
// 	char pcTabeHexString[] = "0xABCD";
// 	unsigned int uiWartoscUInt;
// 	eHexStringToUInt(pcTabeHexString, &uiWartoscUInt); //Pobieramy sobie adres bo wskaznik zawsze na cos wskazuje, w tym przypadku na elementy typu ui
// 																										 // wiec pobieramy sobie adres elementu na ktory ma wskazywac i na nim wykonujemy funkcje 
// 																										 // Zgodnosc typu
	
// 	//AppendUIntToString
// 	/*unsigned int uiWartoscAppend = 2;
// 	char pcTabAppend[15] = "0xABCD";
// 	AppendUIntToString(uiWartoscAppend, pcTabAppend);
// */
// }

/*
Iterujemy po tetradach uiValue
uiActualValue = uiValue >> (4*uiNibbleCounter) & 0x000F
0x0111 >>8 0x0001

Podczas pierwszej iteracji 
uiValue = 1
Sprawdzamy czy jest z zakresu takiego albo takiego 

>= 10 && <=15
'0' + uiActualValue;
*/