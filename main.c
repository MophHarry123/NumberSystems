#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h> 
#include <ctype.h>

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
        scanf("%llu", &UserInput);
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

void HexaToBinary() {
    char HexaDeciInpu[50];
    int SystemPass = 0;
    printf("Provide the Hexadecimal input you want to change : ");
    scanf("%49s", HexaDeciInpu);
    

    int CCount = strlen(HexaDeciInpu);
    int TotalBit = CCount * 4;

    char* RawReservation = (char*)malloc(TotalBit+1);
    char* DenaryReservation = (char*)malloc((TotalBit*2)+1);
    char* BinaryReservation = (char*)malloc((TotalBit*4)+1);

    for (int i = 0;  i < CCount; i++) { // Putting Each Inside Another chamber for safety , and putting everything in Upper
        
        RawReservation[i] = toupper(HexaDeciInpu[i]); // bubble swapping.
        RawReservation[i+1] = '\0'; // put \0 to notify that the appending has done

        if (HexaDeciInpu[i] > 70) {
            printf("Hey! You cannot provide a letter greater than F! \n");
        } else {
            SystemPass = 1;
        }
    } 
if (SystemPass == 1) {  
    for (int i = 0; i < CCount; i++){ // Now getting those number into another chamber, but with a base 10 value before binary.
        if (RawReservation[i] >= 65 && RawReservation[i] <= 90) { // check if it is an alphabet
            for (int y = 0; y < 6; y++ ) { // if yes go through each,check whether if a character is = to something.
                int tempChecker = 65 + y; // double the ASCII value store. 
                if (RawReservation[i] == tempChecker) { // Check if the ASCII value is equal to its ASCII value of additonal Y loop. 
                    DenaryReservation[i] = tempChecker - 55; // if yes, then put a Denerial base 10 hexavalue inside a slot. Since the gap between each is always 65
                }  
            }
        } else if (RawReservation[i] >= 48 && RawReservation[i] <= 57) { // now the shit is a digit number in a string format
            DenaryReservation[i] = RawReservation[i] - '0'; // we now purt it inside DenaryReservation, substract by ASCII of 0 (48), to get the number.
        }
    }

    for (int i = 0; i < CCount; i++) {
        int CalStore = DenaryReservation[i];

        for (int y = 0; y < 4; y++) {
            int Substractor = pow(2, 3 - y); 

            if (CalStore >= Substractor) {
                BinaryReservation[(i * 4) + y] = '1';
                CalStore = CalStore - Substractor;
            } else {
                BinaryReservation[(i * 4) + y] = '0';
            }
        }
    }
    
    // Cap off the whole string right here at the very end
    BinaryReservation[CCount * 4] = '\0';
    
} else {
    printf("Existing the program due to wrong inputs.");
}
    printf("%s", BinaryReservation);

    free(RawReservation);
    free(DenaryReservation);
    free(BinaryReservation);
}

void BinaryToHex() {
    
    char BinaryInput[50] ="";
    int CurrentTotal = 0;
    printf("Enter Your Binary Code.");
    scanf("%s", &BinaryInput);

    
    int CCount = strlen(BinaryInput);
    int AdditionalZero = (4 - (CCount % 4)) % 4;
    char* BinaryReservation = (char*)malloc((CCount+AdditionalZero)+1);
    int TimesLooped = 0;

    for (int i = 0; i < AdditionalZero; i++) {
        BinaryReservation[i] = '0';
    }
    
    for (int i = 0; i < CCount; i++) {
        BinaryReservation[AdditionalZero + i] = BinaryInput[i];
    }
    BinaryReservation[CCount + AdditionalZero] = '\0';
    int NibbleCount = strlen(BinaryReservation) / 4;
    char* BinaryValueReservation = (char*)malloc(NibbleCount+1);

    for (int i = 0; i < NibbleCount; i++) {
        int CurrentTotal = 0;
        
        for (int times = 0; times < 4; times++) {
            CurrentTotal = (CurrentTotal * 2) + (BinaryReservation[(i * 4) + times] - '0');
        }
        BinaryValueReservation[i] = CurrentTotal;
    }

    char* HexReservation = (char*)malloc(NibbleCount+1);

    for (int i = 0; i < NibbleCount; i++) {
        if (BinaryValueReservation[i] >= 10) {
            HexReservation[i] = 'A' + (BinaryValueReservation[i] - 10);
        } else {
            // FIX 4: Added '0' so numeric values turn into actual character glyphs ('0'-'9')
            HexReservation[i] = '0' + BinaryValueReservation[i];
        }
    }

    HexReservation[NibbleCount] = '\0';
    printf("%s", HexReservation);
}

void HexaToDenary() {
    
    char Hex[50];

    printf("Enter Your Hexadecimal: ");
    scanf("%s", &Hex);

    int CCount = strlen(Hex);
    int SystemPass = 0;

    for (int i = 0; i < CCount; i++) {
        Hex[i] = toupper(Hex[i]);

        if (Hex[i] >= 70) {
            SystemPass++;
        }
    }

    unsigned long long CurrentTotal = 0;
    unsigned int Initialize = 0;
    int Initialization = 0;
    int Adder = 0;


if (SystemPass == 0) {
    for (int i = 0; i < CCount;  i++) {
        CurrentTotal *= 16;
        if (Hex[i] >=  65) {
            CurrentTotal += (Hex[i] - 55);
        } else {
            CurrentTotal += (Hex[i] - '0');
        }
    }

    printf("%llu", CurrentTotal);
}

}
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

int main() {
    int selected = 0;
    int totalOptions = 6;
    int key = 0;

while (1) {
        
        system("cls");

        printf("==============================\n");
        printf("   SELECT CONVERSION MODE\n");
        printf("==============================\n");

        
        const char *options[6] = {
            "Denary to Hexadecimal",
            "Denary to Binary",
            "Hexadecimal to Binary",
            "Binary To HexaDecimal",
            "HexaDecimal to Denary",
            "Exit."
        };

        for (int i = 0; i < totalOptions; i++) {
            if (i == selected) {
                printf(" > [X] %s < \n", options[i]); // Highlighted option
            } else {
                printf("   [ ] %s   \n", options[i]);
            }
        }

        printf("==============================\n");
        printf("Use Up/Down arrows to move, Enter to select.\n");

        
        key = _getch();

        
        if (key == 224 || key == 0) {
            key = _getch(); // Get the actual arrow code
            if (key == KEY_UP) {
                selected--;
                if (selected < 0) selected = totalOptions - 1; // Wrap around to bottom
            } else if (key == KEY_DOWN) {
                selected++;
                if (selected >= totalOptions) selected = 0; // Wrap around to top
            }
        } 
        
        else if (key == KEY_ENTER) {
            system("cls");
            if (selected == 0) {
                printf("Launching Denary to Hex mode...\n");
                DenaryToHexa();
            } else if (selected == 1) {
                printf("Launching Denary to Binary mode...\n");
                DenaryToBinary();
            } else if (selected == 2) {
                printf("Launching Hex to Binary mode...\n");
                HexaToBinary();
            } else if (selected == 3) {
                printf("Launching Binary to Hex mode... ");
                BinaryToHex();
            } else if (selected == 4) {
                printf("Exiting...");
                break;
            } 
            printf("\nPress any key to return to menu...");
            _getch();
        }
    }

    return 0;

}