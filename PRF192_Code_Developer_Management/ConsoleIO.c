#include "ConsoleIO.h"
#include "Common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//============SYSTEM FUNCTIONS ==============
void pauseSystem(){
	system("pause");
}
void clearSystem(){
	system("cls");
}

void clearBuffer() {
    while (getchar() != '\n'); 
}


//============CHECK YES/NO FUNCTION =========
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

bool ContinueOrNot() {
    char choice[20];

    printf("Do you want to continue? -_?\n");
    printf("Enter Yes (Y) or No (N)\n");

    while (true) {
        clearBuffer();
        scanf("%[^\n]", choice);
        toLowerCase(choice); // chuẩn hóa về chữ thường

        if (strcmp(choice, "y") == 0 || strcmp(choice, "yes") == 0) {
            return true;
        } else if (strcmp(choice, "n") == 0 || strcmp(choice, "no") == 0) {
            return false;
        } else {
            printf("-_- Your choice is invalide \"_- !!\n");
			printf("You should enter again -3- \n");
            continue;
        }
    }
}

int readInt(int n){
	scanf("%d", &n);
	
	return n;
}

int printfChoice(){
	int choice;
	printf("Enter your choice: ");
	return readInt(choice);
}

void MAIN_MENU(){
	printf("\t=============MAIN MENU=============\n");
	printf("\t1. Developer Services\n");
	printf("\t2. Project Services\n");
	printf("\t3. Exit.\n");
}

void SubMENU_DEV(){
	printf("\t=============DEVELOPER SERVICES=============\n");
	printf("1. Add new Developer\n");
	printf("2. Update Developer\n");
	printf("3. Delete Developer\n");
	printf("4. Display (Developer or List Developer)\n");
	printf("5. Find Developer\n");
	printf("6. Exit\n");
}

void SubMENU_PROJECT(){
	printf("\t=============PROJECT SERVICES=============\n");
	printf("1. Add new Project\n");
	printf("2. Assign Project to Developer\n");
	printf("3. Display (Project or List Project)\n");
	printf("4. Exit\n");
}

void SubMENU_UPDATE(){
	printf("\t=============UPDATE ELEMENT DETAILS=============\n");
	printf("1. Update Name Developert\n");
	printf("2. Update Programming Lanaguage Developer\n");
	printf("3. Update the Birth day for Developer\n");
	printf("4. Update Salary for Developer\n");
	printf("5. Exit\n");
}

