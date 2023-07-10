#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to encrypt the message
void encrypt(char* message, int key) {
    int messageLen = strlen(message), k, j, a;
    int rows = (messageLen + key - 1)/key;
    char cipher[rows][key], scipher[rows][key] , order[key];

    printf("Enter the order of your message : ");
    for(int i = 0; i < key; i++){
      scanf("%d", &order[i]);
    }
    // fill the cipher array with the message
    k = 0;
    for (int i = 0; i < rows; i++) {
        for (j = 0; j < key; j++) {
            if (k < messageLen){
               cipher[i][j] = message[k];
               k++;
            }
            else 
               cipher[i][j] = '_';
               printf("%c  ", cipher[i][j]);
        }
        printf("\n");
    }

    // sorting the matrix
    printf("\n");
    printf("The sorted matrix is :\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            a = order[j];
            scipher[i][j]= cipher[i][a];
            printf("%c  ", scipher[i][j]);
            }
            printf("\n");
        }
    
    // printing the encrypted message
    k = 0;
    printf("\n");
    printf("The Encrypted text is : ");
    for (int i = 0; i < key; i++) {
        for (j = 0; j < rows; j++) {
            printf("%c", scipher[j][i]);
        }
    }
}

// function to decrypt the message
void decrypt(char* message, int key) {
    int messageLen = strlen(message), k = 0, j, a;
    int rows = (messageLen + key - 1)/key;
    char cipher[rows][key], scipher[rows][key] , order[key];

    printf("Enter the order of your message : ");
    for(int i = 0; i < key; i++){
      scanf("%d", &order[i]);
    }
   //storing encrypted message in a matrix
    for (int i = 0; i < key; i++) {
        for (j = 0; j < rows; j++) {
               cipher[j][i] = message[k];
               k++;
               printf("%c  ", cipher[j][i]);
        }
        printf("\n");
    }
    // sort in new matrix
    printf("\n");
    printf("The sorted matrix is :\n");
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            a = order[j];
            scipher[i][a]= cipher[i][j];
            printf("%c  ", scipher[i][a]);
            }
            printf("\n");
        }

    // print decrypted message
    printf("The Decrypted text is : ");
    for (int i = 0; i < rows; i++) {
        for (j = 0; j < key; j++) {
            printf("%c", scipher[i][j]);
        }
    }
}

int main() {
    char message[100];
    int choice, key;
    printf("\t\t\t ----------------------    ----------------------- \n");
    printf("\t\t\t Columnar Transposition Encryption and Decryption \n");
    printf("\t\t\t ----------------------    ---------------------- \n");
    printf("\t\t\t 1: Encryption\n");
    printf("\t\t\t 2: Decryption\n");
    printf("\t\t\t 3: Exit\n");
    while (1){
    printf("\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);

   switch (choice)
   {
    case 1:
         printf("\nEnter the message to be encrypted : ");
         scanf("%s",message);
         printf("Enter the key : ");
         scanf("%d",&key);
        encrypt(message, key);
      break;
    case 2:
         printf("Enter the message to be decrypted : ");
         scanf("%s", message);
         printf("Enter the key : ");
         scanf("%d", &key);
        decrypt(message, key);
      break;
    case 3:
         exit(0);
        break;
    default:
      //   printf("Invalid choice my friend");
        break;
   }
    }
    return 0;
}