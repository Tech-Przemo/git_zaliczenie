#define MAX_KEYWORD_STRING_LTH 10 //maskymalna dlugosc komendy 

typedef enum TokenType {KEYWORD, NUMBER, STRING} TokenType; //typedef enum ogranicza nam wartosc -> w tym przypadku do 3

typedef enum KeywordCode {LD, ST, RST} KeywordCode;

typedef union TokenValue //wartosc tokenu 
{   
    enum KeywordCode    eKeyword; //jezeli KEYWORD
    unsigned int        uiNumber; //jezeli NUMBER
    char*               pcString; // jezeli STRING
} TokenValue;

typedef struct Token
{
    enum TokenType eType; //kazdy token ma swoja wartosc
    union TokenValue uValue;
} Token;

typedef struct Keyword
{
    enum KeywordCode eCode;
    char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;
