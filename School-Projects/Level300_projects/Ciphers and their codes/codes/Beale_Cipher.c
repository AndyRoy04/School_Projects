#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Function to read the book and store the word positions in a hash table
void readBook(char *filename, int *hashTable) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int position = 0;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %sn", filename);
        exit(1);
    }
    
    while (fscanf(fp, "%s", word) != EOF) {
        int len = strlen(word);
        if (len > 0) {
            // Convert the word to lowercase
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }
            // Store the word position in the hash table
            if (hashTable[word[0] - 'a'] == -1) {
                hashTable[word[0] - 'a'] = position;
                position += len + 1;
            } else {
                position += len + 1;
            }
        }
    }
    
    fclose(fp);
}

// Function to encrypt the plaintext using the Beale cipher
void encrypt(char *plaintext, int *hashTable) {
    char word[MAX_WORD_LENGTH];
    int wordPositions[MAX_WORDS];
    int numWords = 0;
    
    // Split the plaintext into words and store their positions in the hash table
    char *token = strtok(plaintext, " ");
    while (token != NULL) {
        int len = strlen(token);
        if (len > 0) {
            // Convert the word to lowercase
            for (int i = 0; i < len; i++) {
                word[i] = tolower(token[i]);
            }
            word[len] = '0';
            // Store the word position in the wordPositions array
            if (hashTable[word[0] - 'a'] != -1 && strcmp(word, &plaintext[hashTable[word[0] - 'a']]) == 0) {
                wordPositions[numWords++] = hashTable[word[0] - 'a'];
            }
        }
        token = strtok(NULL, " ");
    }
    
    // Encrypt the plaintext using the word positions
    for (int i = 0; i < numWords; i++) {
        printf("%d ", wordPositions[i]);
    }
    printf("The encrypted text is : %d", wordPositions);
}

int main() {
    char filename[100], plaintext[1000];
    int hashTable[26];
    printf("\t\t\t\t ------------------    ----------------- \n");
    printf("\t\t\t\t  BEALE Cipher Encryption and Decryption \n");
    printf("\t\t\t\t ------------------    ----------------- \n");
    
    // Initialize the hash table with -1
    for (int i = 0; i < 26; i++) {
        hashTable[i] = -1;
    }
    
    printf("Enter the name of the book file: ");
    scanf("%s", filename);
    
    readBook(filename, hashTable);
    
    printf("Enter the plaintext: ");
    getchar();
    fgets(plaintext, 1000, stdin);
    plaintext[strlen(plaintext) - 1] = '0';
    
    encrypt(plaintext, hashTable);
    
    return 0;
}
