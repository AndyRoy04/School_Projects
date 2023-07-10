#include <stdio.h>
#include <string.h>
	//Encryption Function
void encrypt(){
	char ch, text[100];
	int key, i;
	
	printf("Enter your Plaintext : ");
	gets(text);
	printf("Enter the key : ");
	scanf("%d", &key);

	for(i=0; i<strlen(text); i++){
		ch=text[i];

		if (ch>='A' && ch<='Z'){
			ch=(ch + key -'A') % 26 + 'A';
		}

		else if (ch>='a' && ch<='z'){
			ch=(ch + key -'a') % 26 + 'a';
		}
		text[i]=ch;
	}
    printf("The Encrypted text is : ");
	puts(text);
}
	//Decryprion funtion
void decrypt(){
	char text[100], ch;
	int key, i;

	printf("Enter the Ciphertext : ");
	gets(text);
	printf("Enter the key : ");
	scanf("%d", &key);

	for(i=0; i<strlen(text); i++){
		ch=text[i];

		if (ch>='A' && ch<='Z'){
			ch=(ch - key -'A' + 26) % 26 + 'A';
		}

		else if (ch>='a' && ch<='z'){
			ch=(ch - key -'a' + 26) % 26 + 'a';
		}
		text[i]=ch;
	}
    printf("The Decrypted text is : ");
	puts(text);
}
		//Main program
int main()
{
	char text[100];
	int choice;
    printf("\t\t\t\t ------------------    ----------------- \n");
    printf("\t\t\t\t Ceasar Cipher Encryption and Decryption \n");
    printf("\t\t\t\t ------------------    ----------------- \n");
	printf("\t\t\t\t 1: Encrypt\n");
	printf("\t\t\t\t 2: Decrypt\n");
	printf("\t\t\t\t 3: Exit program\n");
	printf("\t\t\t\t ----------------\n");
	while (1)
	{
	printf("\n\t\t\t\t Enter your choice : ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		gets(text);
		encrypt(text);
		break;
	case 2:
		gets(text);
		decrypt();
		break;
	case 3:
		exit(0);
		break;
	default:
		printf("\nInvalid choice my friend...");
		break;
	}
	}
	return 0;
}
