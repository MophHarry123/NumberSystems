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

void DenaryToHexa() {
    int UserInput;
    int Remainder;
    int Quotient;
    int DivNeed;
    int i;
    int index = 0;
    char HexaString[300];


    char temp;


    printf("|Denary to HexaDecimal Mode|\n\n");
    printf("Type in the Denary Number");
    scanf("%d", &UserInput);

    if (UserInput >= 1048576) {
        DivNeed = 6;
    } else if ( UserInput >= 65536) {
        DivNeed = 5;
    } else if (UserInput >= 4096) {
        DivNeed = 4;
    } else if (UserInput >= 256 ) {
        DivNeed = 3;
    } else if (UserInput >= 16 ) {
        DivNeed = 2;
    } else {
        DivNeed = 1;
    }


    int CheckQuotient = UserInput / 16;  // to prevent exra 0 from dumping in.
    int TempRemainder = UserInput;
    int TempQuotient = UserInput; 

        for (i = DivNeed; i >=1; i-- ) {

            TempRemainder = TempQuotient % 16;
            TempQuotient = TempQuotient / 16;
            if (TempRemainder == 15 ) {
                HexaString[index] = 'F';
                index++;
                HexaString[index] = '\0';
            } else if (TempRemainder == 14) {
                HexaString[index] = 'E';
                index++;
                HexaString[index] = '\0';
            } else if (TempRemainder == 13) {
                HexaString[index] = 'D';
                index++;
                HexaString[index] = '\0';
            } else if (TempRemainder == 12) {
                HexaString[index] = 'C';
                index++;
                HexaString[index] = '\0';
            } else if (TempRemainder == 11) {
                HexaString[index] = 'B';
                index++;
                HexaString[index] = '\0';
            } else if (TempRemainder == 10) {
                HexaString[index] = 'A';
                index++;
                HexaString[index] = '\0';
            } else {
                HexaString[index] = TempRemainder + '0';
                index++;
                HexaString[index] = '\0';
            }
        }
    int start = 0;
    int end = strlen(HexaString) - 1;

        while (start<end) {
                temp = HexaString[start];
                HexaString[start] = HexaString[end];
                HexaString[end] = temp;

                start++;
                end--;
        }
        printf("%s", HexaString);
    
}

int main() {
    

    int ModeInput;
        
    printf("[Welcoming to Number Converter. Choose the Mode] \n\n");
    printf("Type 1 to Turn Denary to Binary. \n");

    scanf("%d", &ModeInput);
    
    

    if (ModeInput == 1) {
         DenaryToBinary();
    } else if (ModeInput == 2 ) {
        DenaryToHexa();
    } 

}