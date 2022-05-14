#include <stdio.h>
#include <stdlib.h>
#include "character_strings.h"

#define NULL 0


void CopyString(char pcSource[], char pcDestination[])              //FUNKCJA KOPIUJACA LANCUCH ZNAKOWY Z TABLICY SOURCE DO TABLICY DESTINATION
{
		unsigned char ucCharCounter;                                            //DEKLARACJA LICZNIKA KTORYM PRZESUWAMY SIE PO INDEKSACH TABLICY  
    for(ucCharCounter=0 ; pcSource[ucCharCounter]!=NULL ; ucCharCounter++)  //PETLA ZA POMOCA KTOREJ KOPIUJEMY ZNAKI 
    {
        pcDestination[ucCharCounter]=pcSource[ucCharCounter]; //PRZYPISANIE WARTOSCI INDEKSU TABLICY SOURCE DO DESTINATION
		}
		pcDestination[ucCharCounter]=NULL; //PRZEPISANIE ZNAKU KONCA TABLICY SOURCE DO DESTINATION 
}

//aab, aabc
enum CompResult eCompareString(char pcTab1[], char pcTab2[]) 				//FUNKCJA POROWNUJACA LANCUCHY ZNAKOWE ZAKONCZONE NULL 
{
		unsigned char ucLicznikZnakow;
		for(ucLicznikZnakow=0; pcTab1[ucLicznikZnakow]!=NULL || pcTab2[ucLicznikZnakow]!=NULL; ucLicznikZnakow++) //PETLA SPRAWDZAJACA CZY TABLICE SA ROZNE OD JEJ KONCA 
		{
				if(pcTab1[ucLicznikZnakow]!=pcTab2[ucLicznikZnakow]) //SPRAWDZANIE CZY WARTOSC POD TYM SAMYM INDEKSEM W DWOCH TABLICACH JEST TAKA SAMA 
					{
					return DIFFERENT;
					}
		}
		//if(pcTab2[ucLicznikZnakow] == pcTab1[ucLicznikZnakow]) 
		//{
			return EQUAL;
		//}
		//return DIFFERENT;
		
} // Ta funkcja moze zwrocic tylko wartosci enuma 

void AppendString (char pcZrodloTab[], char pcCelTab[]) //FUNKCJA DODAJACA LANCUCH ZNAKOWY Z SOURCE DO DESTINATION 
{
		unsigned char ucLicznikZnakow;
		for (ucLicznikZnakow=0 ; pcCelTab[ucLicznikZnakow]!=NULL ; ucLicznikZnakow++)
		{}
		CopyString(pcZrodloTab,pcCelTab+ucLicznikZnakow); //PRZESUNIECIE WSKAZNIKA POCZATKU TABLICY NA JEJ KONIEC I NADDPISANIE ZNAKU NULL TABLICY CEL PRZEZ PIERWSZY ZNAK LANCUCHA ZRODLO 
		 
}


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar) //FUNKCJA ZMIENIAJCA W STRINGU STARE ZNAKI NA NOWE 
{
		unsigned char ucCharCounter;
		for(ucCharCounter=0; pcString[ucCharCounter]!=NULL; ucCharCounter++) 
		{
				if(pcString[ucCharCounter]==cOldChar) //POROWNUJEMY STARE ZNAKI ZAPISANE POD DANYM INDEKSEM W TABLICY  
				{
				pcString[ucCharCounter]=cNewChar;    //TAM GDZIE BYL STARY ZNAK (POD TYM SAMYM INDEKSEM W TABLICY) WSTAWIAMY NOWY ZNAK 
				}
		}
}

// int main()
// {
// 	//CopyString
//     /*char cSource[]={"XXX"};
//     char cDestination[]={"ZZZZ"};
//     CopyString(cSource,cDestination); */
		
	
// 	//CompareString
// 	 /*enum	CompResult DIFFERENT, EQUAL;
// 	 char tab1 []={"aacd"};
// 	 char tab2 []={"aac"};
// 	 EQUAL = eCompareString(tab1,tab1);
// 	 DIFFERENT = eCompareString(tab1,tab2); */
	
	
// 	//AppendString
// 	char tab1 [10]={"XXZ"};
// 	char tab2 [10]={"YYY"};
// 	AppendString(tab1,tab2);
	
// 	//ReplaceCharactersInString
// 	/*char tab1[] ={"AAAAAVVVVV"};
// 	char StareZnaki = 'A'; 
// 	char NoweZnaki = 'B';
// 	ReplaceCharactersInString(tab1, StareZnaki, NoweZnaki);*/
	
	
// }
