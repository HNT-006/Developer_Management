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
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//============CHECK YES/NO FUNCTION =========
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

bool ContinueOrNot() {
    char choice[20];

    printf("Do you want to continue?\n");
    printf("Enter Yes (Y) or No (N)\n");

    while (true) {
        
        readString(choice);
        clearBuffer();
        toLowerCase(choice); // chuẩn hóa về chữ thường
        
        if (strcmp(choice, "y") == 0 || strcmp(choice, "yes") == 0) {
            return true;
        } else if (strcmp(choice, "n") == 0 || strcmp(choice, "no") == 0) {
            return false;
        } else {
            printf("Your choice is invalid\n");
            printf("Please enter again\n");
            continue;
        }
    }
}

//======================CAC HAM NHAP THONG TIN GOM INTERGER VA STRING========================
int readInt(int n){
	scanf("%d", &n);
	
	return n;
}

int printfChoice(){
	int choice;
	printf("Enter your choice: ");
	return readInt(choice);
}


char* readString(char str[]){
	scanf("%[^\n]", str);
	return str;
}
void printfID(char str[]){
	printf("Enter ID: ");
	str = readString(str);
}

//======================IN KHUNG VA TIEU DE CHO DISPLAY DEVELOPER=================
void bolder(){
	printf("\n------------------------------------------------------------------------------------------------\n");
}
void titile(){
	printf("%-10s %-20s %-15s %-25s %-10s\n",
                                                        "ID", 
														"NAME DEVELOPER", 
														"BIRTH DATE",
														"PROGRAMMING LANGUAGE", 
														"SALARY");
}



void MAIN_MENU(){
	printf("\t======================MAIN MENU======================\n");
	printf("1. Developer Services\n");
	printf("2. Project Services\n");
	printf("3. Exit.\n");
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
	printf("\t=============UPDATE SERVICE===============\n");
	printf("1. Update Name Developert\n");
	printf("2. Update Programming Lanaguage Developer\n");
	printf("3. Update the Birth day for Developer\n");
	printf("4. Update Salary for Developer\n");
	printf("5. Exit\n");
}

void SubMENU_DISPLAY(){
	printf("\t=============DISPLAY SERVICES=============\n");
	printf("1. Display Developer\n");
	printf("2. Display all Developer in List Developer\n");
	printf("3. Exit\n");
}


