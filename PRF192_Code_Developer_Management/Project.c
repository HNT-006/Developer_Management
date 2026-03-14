#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"
#include "Project.h"
#include "ConsoleIO.h"
//typedef struct{
//	char IDPro[7];
//	char NamePro[20];
//    int Duration;  //So thang hoan thanh Project
//    char StartDate[9];  // Ngay thang nam bat dau
//    
//    char Members[MAX_DEV][7];  //Luu so luong ID DEV thuc hien + Do dai cua ID DEV
//    int MemberCount;
//
//} Project;

//====================CAC HAM NHAP XUAT CO BAN ====================

//================CAC HAM DUA RA LUA CHON, VA SUBMENU===============

 int LuaChon_1or2(){
	int chon;
	
	do{
	scanf("%d", &chon);
	if (chon == 1 || chon == 2) return chon;
	else{
		printf("Your  choice is Invalid -_-. YOU JUST CHOOSE 1 OR 2, PLEASE\n");
		printf("IF YOU UNDERSTAND, CHOOSE AGAIN\n");
		pauseSystem();
		
		continue;
	}
}while(true);
	
}

int findNameProject(char str[], Project ListPro[]){
	for (int i = 0; i< ProCount; i++){
		if (strcmp(str, ListPro[i].NamePro) == 0) return i;
	}
	
	return -1;
}

int findIDProject(char str[], Project ListPro[]) {
	for (int i = 0; i< ProCount; i++){
		if (strcmp(str, ListPro[i].IDPro) == 0) return i;
	}
	
	return -1;
}




void addnewProject(Project ListPro[]){
	if ((ProCount) >= MAX_PRO){
		printf("THE NUMBER OF PROJECT IN LIST PROJECT IS FULL (MAXIMUM 50) -_-\n");
		return;
	}
	
	demPro++; 
<<<<<<< HEAD
	snprintf(ListPro[ProCount].IDPro, sizeof(ListPro[ProCount].IDPro), "PRO%03d", demPro);
=======
	Project* p = &ListPro[ProCount];
	
	snprintf(p->IDPro, sizeof(p->IDPro), "PRO%03d", demPro);
>>>>>>> 8edff95c23197880d681b4d213f503aef6856e47
	
	printf("Enter Name Project: ");
    strcpy(ListPro[ProCount].NamePro, readString(ListPro[ProCount].NamePro));
	
	printf("Enter Duration (THE NUMBER OF MONTH, DEV HAVE TO FINISH PROJECT): ");
	ListPro[ProCount].Duration = readInt(ListPro[ProCount].Duration);
	
	printf("Enter StartDate (DATE, DEV START TO WORK): ");
    strcpy(ListPro[ProCount].StartDate, readString(ListPro[ProCount].StartDate));
	
    ListPro[ProCount].MemberCount = 0;
	printf("Add new Project Successfully ^v^\n");
	
	ProCount++;
}


int LuaChon_assignProjecttoDev(Project ListPro[]){
	
	printf("Enter Name Project or ID Project to Assign with ID Dev: ");
	printf("\t1. Enter Name Project\n");
	printf("\t2. Enter ID Project\n");
    int luachon_forAssign = LuaChon_1or2();
    
    if (luachon_forAssign == 1){
    	do{
    		printf("Enter Name Project: ");
    	    char nameProject[100];
    	    strcpy(nameProject, readString(nameProject));
    	
    	    int indexN = findNameProject(nameProject, ListPro);
    	    if (indexN == -1){
    		    printf("Not found This Project -_-\n");
    		    printf("Do you want to out or continue? \n");
    		    printf("\t1. Exit\n");
    		    printf("\t2. Continue ^v^\n");
    		    int choice = LuaChon_1or2();
    		    
    		    if (choice == 1){
    		    	printf("Thank you and Bye Bye ^^\n");
    		    	return -1;
				} else{
					printf("Great choice. Continue now\n");
					pauseSystem();
					continue;
				}
		    } else{
		    	printf("Greate. Continue now\n");
		    	pauseSystem();
		    	return indexN;
			}
		} while (true);
    	
    	
	} else if (luachon_forAssign == 2){
		do{
    		printf("Enter ID Project: ");
    	    char  IDProject[100];
    	    strcpy(IDProject, readString(IDProject));
    	
    	    int indexI = findIDProject(IDProject, ListPro);
    	    if (indexI == -1){
    		    printf("Not found This Project -_-\n");
    		    printf("Do you want to out or continue? \n");
    		    printf("\t1. Exit\n");
    		    printf("\t2. Continue ^v^\n");
    		    char choice = LuaChon_1or2();
    		    
    		    if (choice == 1){
    		    	printf("Thank you and Bye Bye ^^\n");
    		    	return -1;
				} else{
					printf("Great choice. Continue now\n");
					pauseSystem();
					continue;
				}
		    } else{
		    	printf("Greate. Continue now\n");
		    	pauseSystem();
		    	return indexI;
			}
		} while (true);
    	
    	
	}
	
}

void assignProjecttoDev(Project ListPro[], char IdDev[]){
	int index = LuaChon_assignProjecttoDev(ListPro);
	if (index == -1){
		return;
	}
	
	if(ListPro[index].MemberCount >= MAX_MEM){
       printf("Project is full\n");
       pauseSystem();
       return;
    }
	
	int pos = ListPro[index].MemberCount;
	
	strcpy(ListPro[index].Members[pos], IdDev);
	
	ListPro[index].MemberCount++;
	
	printf("Assign Dev Successfully ^v^ \n");
}