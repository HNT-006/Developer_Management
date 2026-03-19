#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"
#include "Project.h"
#include "ConsoleIO.h"
//====================CAC HAM NHAP XUAT CO BAN ====================

int getNextProID() {
    int maxID = 0;
    for (int i = 0; i < ProCount; i++) {
        int idNum;
        sscanf(ListPro[i].IDPro, "PRO%d", &idNum);
        if (idNum > maxID) maxID = idNum;
    }
    return maxID + 1;
}
//==================CAC HAM FIND ID PROJECT VÀ FIND NAME PROJECT=================
int findProjectbyName(char proName[], Project ListPro[], int ProCount){
	for (int i = 0; i< ProCount; i++){
		if (strcmp(proName, ListPro[i].NamePro) == 0) return i;
	}
	
	return -1;
}

int findProjectbyID(char proID[], Project ListPro[], int ProCount){
	for (int i = 0; i<ProCount; i++){
		if (strcmp(proID, ListPro[i].IDPro) == 0) return i;
	}
	
	return -1;
}

//================CAC HAM DUA RA LUA CHON, VA SUBMENU===============
 int LuaChon_1or2(){
	int chon;
	
	do{
	printf("Enter your choice: ");
	scanf("%d", &chon);
	clearBuffer();
	printf("\n");
	if (chon == 1 || chon == 2) return chon;
	else{
		printf("Your  choice is Invalid -_-. YOU JUST CHOOSE 1 OR 2, PLEASE\n");
		printf("IF YOU UNDERSTAND, CHOOSE AGAIN\n");
		pauseSystem();
		clearSystem();
		continue;
	}
}while(true);
	
}

//==============ADD NEW PROJECT==================
void addnewProject(Project ListPro[], int *ProCount){
	if ((*ProCount) >= MAX_PRO){
		printf("THE NUMBER OF PROJECT IN LIST PROJECT IS FULL (MAXIMUM 50) -_-\n");
		return;
	}
	
	int nextID = getNextProID();

	snprintf(ListPro[*ProCount].IDPro, sizeof(ListPro[*ProCount].IDPro), "PRO%03d", nextID);

	Project* p = &ListPro[*ProCount];
	
	snprintf(p->IDPro, sizeof(p->IDPro), "PRO%03d", nextID);
	
	clearBuffer();
	printf("Enter Name Project: ");
    strcpy(ListPro[*ProCount].NamePro, readString(ListPro[*ProCount].NamePro));
	
	printf("Enter Duration (THE NUMBER OF MONTH, DEV HAVE TO FINISH PROJECT): ");
	ListPro[*ProCount].Duration = readInt(ListPro[*ProCount].Duration);
	
	clearBuffer();
	printf("Enter StartDate (DATE, DEV START TO WORK): ");
    strcpy(ListPro[*ProCount].StartDate, readString(ListPro[*ProCount].StartDate));
	
    ListPro[*ProCount].MemberCount = 0;
	printf("Add new Project Successfully ^v^\n");
	
	(*ProCount)++;
}



// Ham kiem tra Dev đã có trong project chưa
// su dung ham inputdevid va input proid ben operation de nhap
int isDevInProject(Project ListPro[], char devID[], char proID[],int ProCount)  
{
	int proIndex = findProjectbyID(proID, ListPro, ProCount);
	
    if (proIndex == -1)
    {
    	return 0;
	}
	
    for(int i = 0; i < ListPro[proIndex].MemberCount; i++)
    {
    	 if (strcmp(ListPro[proIndex].Members[i], devID) == 0)
        {
            return 1;
        }
	}
    return 0;
}


int LuaChon_assignProjecttoDev(Project ListPro[]){
	
	if (ProCount == 0){
		printf("NO PROJECT IS NOW. YOU NEED TO ADD NEW PROJECT\n");
		pauseSystem();
		return 0;   //==========================KHONG CO BAT KI MOT PROJECT NAO THI RA VE 0
	}
	printf("=====================CHOOSING THE METHOD TO ENTER===================== \n");
	printf("\t1. Enter Name Project\n");
	printf("\t2. Enter ID Project\n");
    int luachon_forAssign = LuaChon_1or2();
    if (luachon_forAssign == 1){
    	do{
    		printf("Enter Name Project: ");
    	    char nameProject[100];
    	    strcpy(nameProject, readString(nameProject));
    	
    	    int indexN = findProjectbyName(nameProject, ListPro, ProCount);
    	    if (indexN == -1){
    		    printf("Not found This Project -_-\n");
    		    printf("Do you want to out or continue? \n");
    		    printf("\t1. Exit\n");
    		    printf("\t2. Continue ^v^\n");
    		    int choice = LuaChon_1or2();
    		    clearBuffer();
    		    if (choice == 1){
    		    	printf("Thank you and Bye Bye ^^\n");
    		    	pauseSystem();
    		    	return -1;
				} else{
					printf("Great choice. Continue now\n");
					pauseSystem();
					clearSystem();
					continue;
				}
		    } else{
		    	printf("Greate. Continue now\n");
		    	pauseSystem();
		    	clearSystem();
		    	return indexN;
			}
		} while (true);
    	
    	
	} else if (luachon_forAssign == 2){
		do{
    		printf("Enter ID Project: ");
    	    char  IDProject[100];
    	    strcpy(IDProject, readString(IDProject));
    	
    	    int indexI = findProjectbyID(IDProject, ListPro, ProCount);
    	    if (indexI == -1){
    		    printf("Not found This Project -_-\n");
    		    printf("Do you want to out or continue? \n");
    		    printf("\t1. Exit\n");
    		    printf("\t2. Continue ^v^\n");
    		    int choice = LuaChon_1or2();
    		    clearBuffer();
    		    if (choice == 1){
    		    	printf("Thank you and Bye Bye ^^\n");
    		    	pauseSystem();
    		    	return -1;
				} else{
					printf("Great choice. Continue now\n");
					pauseSystem();
					clearSystem();
					continue;
				}
		    } else{
		    	printf("Greate. Continue now\n");
		    	pauseSystem();
		    	clearSystem();
		    	return indexI;
			}
		} while (true);
    	
    	
	}
	
}

 //// ==============ASSIGN PROJECT TO DEVELOPER====================

bool assignProjecttoDev(Project ListPro[], char IdDev[]) {

    int index = LuaChon_assignProjecttoDev(ListPro);

    if (index == -1) {
        return false;
    }

    if (ListPro[index].MemberCount >= MAX_MEM) {
        printf("Project is full\n");
        pauseSystem();
        return false;
    }

    // check dev tồn tại
    int devIndex = findDevbyID(ListDev, DevCount, IdDev);
    if (devIndex == -1) {
        printf("Developer not found!\n");
        return false;
    }

    int pos = ListPro[index].MemberCount;

    strcpy(ListPro[index].Members[pos], IdDev);

    // cộng exp đúng dev
    ListDev[devIndex].totalExp += ListPro[index].Duration;

    ListPro[index].MemberCount++;

    printf("Assign Dev Successfully ^v^\n");
    return true;
}

//==================DISPLAY PROJECTS=======================
void displayProject(Project ListPro[], int ProCount, char proID[])
{
    int index = -1;

    for(int i = 0; i < ProCount; i++)
    {
        if(strcmp(ListPro[i].IDPro, proID) == 0)
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        printf("THIS PROJECT ID IS NOT FOUND -_-\n");
        return;
    }

    printf("%-10s %-20s %-15d %-25s %-15d\n",
            ListPro[index].IDPro,
            ListPro[index].NamePro,
            ListPro[index].Duration,
            ListPro[index].StartDate,
            ListPro[index].MemberCount);
}

void displayAllProject(Project ListPro[], int ProCount)
{
    for(int i = 0; i < ProCount; i++)
    {
        displayProject(ListPro, ProCount, ListPro[i].IDPro);
    }
}