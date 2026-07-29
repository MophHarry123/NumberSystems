#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void DenaryToBinary() { 
    unsigned long long UserInput;
    unsigned long long TempHolder;
    int SlotCountRemainder = 0;
    int SlotTimesCount = 0;
    char BinaryString[3000]= "";
    int index = 0;
    unsigned long long tempChecker;
    int SystemBit;

    printf("|Binary Mode|\n\n");
        
        printf("Type in the System bit.\n");
        scanf("%d", &SystemBit);

        printf("Type in the Denary Number.\n");
        scanf("%d", &UserInput);
        TempHolder = UserInput;

        unsigned long long MaxLimit = pow(2, SystemBit) - 1;
        if (UserInput <= MaxLimit) {
            
        for (int X = SystemBit; X > 0; X--) {
            
            tempChecker = pow(2, X-1);

            if (TempHolder >=  tempChecker) {
                BinaryString[index] = '1';
                index++;
                BinaryString[index] = '\0';
                

                TempHolder = TempHolder - tempChecker;
                SlotTimesCount++;

            } else if (TempHolder == 0 ) {

                for (int i = 0; i < X; i++) {
                BinaryString[index] = '0';
                index++;
                BinaryString[index] = '\0';
                }

            } else {
                BinaryString[index] = '0';
                index++;
                BinaryString[index] = '\0';
                
            }
        }       
        printf("The Binary String for your Number is : %s", BinaryString);
     }else {
            printf("Far excced what your system could handle.");
        } 

    

}


int main () {
    

    int ModeInput;
        
    


    printf("[Welcoming to Number Converter. Choose the Mode] \n\n");
    printf("Type 1 to Turn Denary to Binary. \n");

    scanf("%d", &ModeInput);
    
    

    if (ModeInput == 1) {
         DenaryToBinary();
    }

}