#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
int choice;
void removeDuplicates(char str[]){
    int hash[256]        =  {0};
    int currentIndex     = 0;
    int lastUniqueIndex  = 0;
    while(*(str+currentIndex)){
        char temp = *(str+currentIndex);
        if(0 == hash[temp]){
            hash[temp] = 1;
            *(str+lastUniqueIndex) = temp;
            lastUniqueIndex++;
        }
        currentIndex++;
    }
    *(str+lastUniqueIndex) = '\0';
 
}
void Playfair(char ch1, char ch2, char key[SIZE][SIZE]) {
    int i, j, r1, c1, r2, c2;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (ch1 == key[i][j]) {
                r1 = i;
                c1 = j;
            } else if (ch2 == key[i][j]) {
                r2 = i;
                c2 = j;
            }
        }
    }
    // Encrypt and decrypt the text
    if (r1 == r2) {
		if(choice==1){
			c1 = (c1 + 1) % SIZE;
			c2 = (c2 + 1) % SIZE;
		}
		else{
			c1 = ((c1 - 1) % SIZE+SIZE)%SIZE;
			c2 = ((c2 - 1) % SIZE+SIZE)%SIZE;
		}
        printf("%c%c", key[r1][c1], key[r2][c2]);
    } else if (c1 == c2) {
		if(choice==1){
			r1 = (r1 + 1) % SIZE;
			r2 = (r2 + 1) % SIZE;
		}
		else{
			r1 = ((r1 - 1) % SIZE+SIZE)%SIZE;
			r2 = ((r2 - 1) % SIZE+SIZE)%SIZE;
		}
        printf("%c%c", key[r1][c1], key[r2][c2]);
    } 
	else {
        printf("%c%c", key[r1][c2], key[r2][c1]);
    }
}

void Encr_Decr() {
    int i, j, k = 0, l, m = 0, keylength;
    char key[SIZE][SIZE], keyminus[25], keystr[10], str[25] = {0};
	char alpa[26] = 
    {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    fflush(stdin);
    printf("\nEnter key : ");
    gets(keystr);
    printf("Enter the text : ");
    gets(str);
	removeDuplicates(keystr);
    keylength = strlen(keystr);
    //convert the characters to uppertext
    for (i = 0; i < keylength; i++) {
        if (keystr[i] == 'j') keystr[i] = 'i';
        else if (keystr[i] == 'J') keystr[i] = 'I';
        keystr[i] = toupper(keystr[i]);
    }
    //convert all the characters of plaintext to uppertext
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'j') str[i] = 'i';
        else if (str[i] == 'J') str[i] = 'I';
        str[i] = toupper(str[i]);
    }
    // store all characters except key
    j = 0;
    for (i = 0; i < 26; i++) {
        for (k = 0; k < keylength; k++) {
            if (keystr[k] == alpa[i]) break;
            else if (alpa[i] == 'J') break;
        }
        if (k == keylength) {
            keyminus[j] = alpa[i];
            j++;
        }
    }
    //construct key keymatrix
    k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < keylength) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }
    // construct diagram and convert to cipher text
    printf("Your text is : %s\n", str);
    printf("The Encrypted text is : ");
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'J') str[i] = 'I';
        if (str[i + 1] == '\0') Playfair(str[i], 'X', key);
        else {
            if (str[i + 1] == 'J') str[i + 1] = 'I';
            if (str[i] == str[i + 1]) Playfair(str[i], 'X', key);
            else {
                Playfair(str[i], str[i + 1], key);
                i++;
            }
        }
    }
	if(choice==2) printf(" (Remove unnecessary X)");;
    
}

int main(){
    printf("\t\t\t ------------------    ------------------- \n");
    printf("\t\t\t Playfair Cipher Encryption and Decryption \n");
    printf("\t\t\t ------------------    ------------------- \n");
    printf("\t\t\t 1: Encryption\n");
    printf("\t\t\t 2: Decryption\n");
    printf("\t\t\t >2: Exit\n");
    while (1){
    printf("\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    if(choice!=1 && choice!=2){ 
        printf("\t\t\t  Invalid Choice...."); 
    break;
    }
    else Encr_Decr();
    }
    return 0;
}