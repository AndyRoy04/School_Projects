#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Main code function
int main(){
	int lower, upper, choice, num;
        srand(time(NULL));  // Use current time as seed for random generator
        printf("\t\t\t\t ---------    ---------- \n");
        printf("\t\t\t\t Random Number Generator \n");
        printf("\t\t\t\t ---------    ---------- \n");
        printf("\t\t\t Enter the min value: ");
        scanf("%d", &lower);
        printf("\t\t\t Enter the max value: ");
        scanf("%d", &upper);
	
    printf("\n\t\t\t Enter 1 to generate number\n\t\t\t Enter 2 to exit");
    while(1){
    printf("\n\n\t\t\t Enter choice : ");
    scanf("%d", &choice);    
        switch (choice)
        {
        case 1:	
		    num = (rand() % (upper - lower + 1)) + lower;
		    printf("\t\t\t %d", num);
            break;
        case 2:
            exit(0);
            break;
        default:
            break;
        }
    }
	return 0;
}
