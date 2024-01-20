#include <stdio.h>

#define F_TO_C(temp) ((temp - 32)/1.8) /* Fahrenheit to celsius formula */
#define C_TO_F(temp) ((temp * 1.8) + 32) /* celsius to Fahrenheit formula */

int main(void)
{
    char tempType;   /* create variables for temp,f,c*/
    float temp, convertTemp;  
   

    printf("What would you like to convert, C to F or F to C?: ");  /* ask what to convert, c to f or f to c */
    scanf(" %c", &tempType);

    printf("What temprature would you like to convert: ");
    scanf(" %f", &temp);
    
    if (tempType == 'F' || tempType == 'f'){   /* if c to f, then run celsius formula */
        convertTemp = F_TO_C(temp);
        printf("The temprature in celsius is: %.2f\n", convertTemp);
    } else if (tempType == 'C' || tempType == 'c') {
        convertTemp = C_TO_F(temp);
        printf("The temprature in Fahrenheit is: %.2f\n", convertTemp);
    
    } else  {
        printf("Invalid input. \n");
    
    }
return 0;
}
