#include <stdio.h>
#include <math.h>

int convertToInt(char* charID);

int main()
{
    char charID[8] = "A000123";
    int intID = 0;
    
    intID = convertToInt(charID);

    printf("\n%s -> %i\n", charID, intID);
    return 0;
}

int convertToInt(char* charID)
{
    int intID = 0;  

    for (int i = 1; i <= 6; i++){

        int digit = charID[i] - '0';  
        int decimalPlace = pow(10, 6 - i);    
        intID += digit * decimalPlace;        
    }

    return intID;
}
