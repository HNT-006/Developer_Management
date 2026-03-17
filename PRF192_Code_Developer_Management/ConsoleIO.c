#include "ConsoleIO.h"
#include "Common.h"
#include "Developer.h"
#include "Project.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//============SYSTEM FUNCTIONS ==============
void pauseSystem() {
	system("pause > nul");
}
void clearSystem() {
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
		clearBuffer();
		readString(choice);
		//THEM NORMALIZE_STRING O CÁC HÀM NHẬP STRING NHƯ NHẬP TÊN Ở ADDING HAY UPDATE HAY NHẬP SỰ LỰC CHỌN STRING YES NO
		toLowerCase(choice); // chuẩn hóa về chữ thường

		if (strcmp(choice, "y") == 0 || strcmp(choice, "yes") == 0) {
			return true;
		} else if (strcmp(choice, "n") == 0 || strcmp(choice, "no") == 0) {
			return false;
		} else {
			printf("Your choice is invalid\n");
			printf("Please enter again\n");
			pauseSystem();
			continue;
		}
	}
}

//======================CAC HAM NHAP THONG TIN GOM INTERGER VA STRING========================
int readInt(int n) {
	scanf("%d", &n);

	return n;
}

int printfChoice() {
	int choice;
	printf("Enter your choice: ");
	return readInt(choice);
}


char* readString(char str[]) {
	scanf("%[^\n]", str);
	return str;
}
void printfID(char str[]) {
	printf("Enter ID: ");
	str = readString(str);
}

//======================IN KHUNG VA TIEU DE CHO DISPLAY DEVELOPER=================
void bolder() {
	printf("\n-----------------------------------------------------------------------------------------------------\n");
}
void title_Developer() {
	printf("%-10s %-20s %-15s %-25s %-10s %-12s\n",
	       "ID",
	       "NAME DEVELOPER",
	       "BIRTH DATE",
	       "PROGRAMMING LANGUAGE",
	       "SALARY",
	       "EXPERIMENT");
}

void title_Project(){
	printf("%-10s %-20s %-15s %-25s %-10s\n", 
	         "ID",
		    "NAME PROJECT",
			"DURATION",
			"START DATE",
		     "MEMBER COUNT");
}

void MAIN_MENU() {
	printf("\t======================MAIN MENU======================\n");
	printf("1. Developer Services\n");
	printf("2. Project Services\n");
	printf("3. Exit.\n");
}

void SubMENU_DEV() {
	printf("\t=============DEVELOPER SERVICES=============\n");
	printf("1. Add new Developer\n");
	printf("2. Update Developer\n");
	printf("3. Delete Developer\n");
	printf("4. Display List Developer\n");
	printf("5. Find Developer\n");
	printf("6. Exit\n");
}

void SubMENU_PROJECT() {
	printf("\t=============PROJECT SERVICES=============\n");
	printf("1. Add new Project\n");
	printf("2. Assign Project to Developer\n");
	printf("3. Display (Project or List Project)\n");
	printf("4. Exit\n");
}

void SubMENU_UPDATE() {
	printf("\t=============UPDATE SERVICE===============\n");
	printf("1. Update Name Developert\n");
	printf("2. Update Programming Lanaguage Developer\n");
	printf("3. Update the Birth day for Developer\n");
	printf("4. Update Salary for Developer\n");
	printf("5. Exit\n");
}

void SubMENU_DISPLAY() {
	printf("\t=============DISPLAY SERVICES=============\n");
	printf("1. Display Developer\n");
	printf("2. Display all Developer in List Developer\n");
	printf("3. Exit\n");
}


void showDeveloperID(Developer ListDev[], int DevCount) {
	printf("\n===== CURRENT DEVELOPERS =====\n");

	for(int i = 0; i < DevCount; i++) {
		printf("%s\n", ListDev[i].ID);
	}

	printf("==============================\n");
}


//===================CAC CASE TRONG CAC MUC CHINH TRONG MAIN MENU================
void DEFAULT_CASE() {
	clearSystem();

	printf("\n=================================\n");
	printf("              ERROR              \n");
	printf("=================================\n");
	printf(" Invalid choice! -_- \n");
	printf(" Please choose from the menu. \'3\' \n");
	printf("=================================\n");

	pauseSystem();
	clearBuffer();

}
//===================CAC CASE TRONG DEVELOPER SERVICE=================
void ADD_NEW_DEVELOPER() {
	bool tieptuc = true;
	do {
		clearSystem();
		printf("\t================ADD NEW DEVELOPER================\n");
		addDeveloper(ListDev, &DevCount);
		printf("\t================Add new Developer Successfully================\n\n");
		// Gan tieptuc cho ContinueOrNot

		tieptuc = ContinueOrNot();
	} while (tieptuc);
}

void DELETE_DEVELOPER() {
	clearSystem();
	printf("===================DELETE SERVICES==================\n");

	char ID[10];
	bool tieptuc = true;

	while (tieptuc) {

		showDeveloperID(ListDev, DevCount);   // hiển thị bảng Dev

		printfID(ID);

		clearBuffer();

		deleteDeveloper(ListDev, &DevCount, ID);

		tieptuc = ContinueOrNot();  // hỏi user có tiếp tục không
	}
}
void DISPLAY_DEVELOPER() {
	bool tieptuc = true;

	do {
		clearSystem();

		bolder();
		title_Developer();
		bolder();

		displayAllDev(ListDev, DevCount);


		tieptuc = ContinueOrNot();

	} while (tieptuc);

}

void FIND_DEVELOPER() {
	bool tieptuc = true;

	while (tieptuc) {

		clearSystem();
		printf("============== FIND DEVELOPER ==============\n");

		char ID[20];

		showDeveloperID(ListDev, DevCount);   // hiển thị danh sách ID

		clearBuffer();
		printfID(ID);                         // nhập ID
		clearBuffer();

		clearSystem();

		if (findDevbyID(ListDev, DevCount, ID) >= 0) {
			bolder();
			title_Developer();
			bolder();
		}

		displayDeveloper(ListDev, DevCount, ID);   // hiển thị developer tìm được


		tieptuc = ContinueOrNot();                 // hỏi có tìm tiếp không
	}
}
//void UPDATE_DEVELOPER();


////===================CAC CASE TRONG PROJECT SERVICE=================
void ADD_NEW_PROJECT() {
	bool tieptuc = true;
	do {
		clearSystem();
		printf("========================ADD NEW PROJECT========================\n");
		addnewProject(ListPro, &ProCount);
		// Gan tieptuc cho ContinueOrNot
		tieptuc = ContinueOrNot();
	} while (tieptuc);
}
void ASSIGN_PPOJECT_TO_DEV() {
	bool tieptuc = true;
	do {
		clearSystem();

		// Gan tieptuc cho ContinueOrNot
		if (!assignProjecttoDev()) {
			tieptuc = false;
		} else {
			tieptuc = ContinueOrNot();
		}

	} while (tieptuc);
}


void DISPLAY_PROJECT(){
	clearSystem();
							
							bolder();
							title_Project();
							bolder();
							
						    displayAllProject(ListPro, ProCount);
							pauseSystem();
}