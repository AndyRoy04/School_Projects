#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void Encrypt(){
      int i,j,k,textnum[100],keynum[100],numcipher[100];
      char text[100],key[100];

      printf("Enter a string : ");
      scanf("%s",text);
      printf("Enter a key : ");
     scanf("%s",key);
 //converting entered string and key to Capital letters
      for(i=0,j=0;i<strlen(text);i++){
      if(text[i]!=' ' && key[i]!=' '){
         text[j]=toupper(text[i]); 
         key[j]=toupper(key[i]); 
         j++;
      }
         }
      text[j]='\0';
      key[j]='\0';
      printf("\nYour string is : %s",text);
      printf("\nThe key is : %s",key);
 //Storing string in terms of ascii
      for(i=0;i<strlen(text);i++){
      textnum[i]=text[i]-'A';
      }
 //Assigning key to the string
      for(i=0;i<strlen(text);){
      for(j=0;(j<strlen(key))&&(i<strlen(text));j++){
         keynum[i]=key[j]-'A';
         i++;
      } 
      }
    
    for(i=0;i<strlen(text);i++){
     numcipher[i]=textnum[i]+keynum[i];
     if(numcipher[i]>25){
      numcipher[i]=numcipher[i]-26;
     }
    }
    printf("\nVigenere Cipher text is : ");   
    for(i=0;i<strlen(text);i++)
    {
      printf("%c",(numcipher[i]+'A')); 
    }
}

void Decrypt(){
      int i,j,k,textnum[100],keynum[100],numcipher[100];
      char text[100],key[100];
      
            printf("Enter an Encrypted text : ");
            scanf("%s",text);
            printf("Enter the key : ");
            scanf("%s",key);
      
      for(i=0,j=0;i<strlen(text);i++){
      if(text[i]!=' ' && key[i]!=' '){
         text[j]=toupper(text[i]); 
         key[j]=toupper(key[i]); 
         j++;
      }
         }
      text[j]='\0';
      key[j]='\0';
      printf("\nYour Encrypted text is : %s",text);
      printf("\nThe key is : %s",key);
 
      for(i=0;i<strlen(text);i++){
      textnum[i]=text[i]-'A';
      }
 
      for(i=0;i<strlen(text);){
      for(j=0;(j<strlen(key))&&(i<strlen(text));j++){
         keynum[i]=key[j]-'A';
         i++;
      } 
      }
    
    for(i=0;i<strlen(text);i++){
     numcipher[i]=textnum[i]- keynum[i];
     if(numcipher[i]>25){
      numcipher[i]=numcipher[i]-26;
     }
     else if(numcipher[i]<0){
      numcipher[i]=numcipher[i]+26;
     }
    }
    printf("\nThe plaintext is : ");   
    for(i=0;i<strlen(text);i++)
    {
      printf("%c",(numcipher[i]+'A')); 
    }
}
int main(){ 
    char text[100],key[100];
    int choice;
    printf("\t\t\t ------------------------------------ \n");
    printf("\t\t\t Viginere Encryption and Decryption \n");
    printf("\t\t\t ------------------------------------ \n");
    printf("\t\t\t 1: Encryption\n");
    printf("\t\t\t 2: Decryption\n");
    printf("\t\t\t 3: Exit\n");
    while (1){
    printf("\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            Encrypt();
            break;
        case 2:
            Decrypt();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice...");
            break;   
        }
    }
    return 0;
}