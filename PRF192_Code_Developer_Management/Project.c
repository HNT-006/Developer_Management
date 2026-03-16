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



//==================CAC HAM FIND ID PROJECT VÀ FIND NAME PROJECT=================
int findProjectbyName(char proName[], Project ListPro[]){
	for (int i = 0; i< ProCount; i++){
		if (strcmp(proName, ListPro[i].NamePro) == 0) return i;
	}
	
	return -1;
}

int findProjectbyID(char proID[], Project ListPro[]) {
	for (int i = 0; i<ProCount; i++){
		if (strcmp(proID, ListPro[i].IDPro) == 0) return i;
	}
	
	return -1;
}

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



<<<<<<< HEAD


void addnewProject(Project ListPro[]){
	if ((ProCount) >= MAX_PRO){
		printf("THE NUMBER OF PROJECT IN LIST PROJECT IS FULL (MAXIMUM 50) -_-\n");
		return;
	}
	
	demPro++; 

	snprintf(ListPro[ProCount].IDPro, sizeof(ListPro[ProCount].IDPro), "PRO%03d", demPro);

	Project* p = &ListPro[ProCount];
	
	snprintf(p->IDPro, sizeof(p->IDPro), "PRO%03d", demPro);
	
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


=======
>>>>>>> b235272930b7833d84163ed2ad6ee994bfa5a65b
// Ham kiem tra Dev đã có trong project chưa
// su dung ham inputdevid va input proid ben operation de nhap
int isDevInProject(Project ListPro[], char devID[], char proID[],int ProCount)  
{
	int proIndex = findProjectbyID(proID, ListPro);
	
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
	clearBuffer();
	printf("Enter Name Project or ID Project to Assign with ID Dev: ");
	printf("\t1. Enter Name Project\n");
	printf("\t2. Enter ID Project\n");
    int luachon_forAssign = LuaChon_1or2();
    
    if (luachon_forAssign == 1){
    	do{
    		printf("Enter Name Project: ");
    	    char nameProject[100];
    	    strcpy(nameProject, readString(nameProject));
    	
    	    int indexN = findProjectbyName(nameProject, ListPro);
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
    	
    	    int indexI = findProjectbyID(IDProject, ListPro);
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

<<<<<<< HEAD

=======
 
//void assignProjecttoDev(){
//    char devID[7];
//    char proID[7];
//
//    printf("Enter Developer ID: ");
//    scanf("%6s", devID);
//
//    int devIndex = findDevByID(devID, ListDev, DevCount);
//
//    if(devIndex < 0)
//    {
//        printf("Developer not found!\n");
//        return;

//=================== ADD NEW PROJECT =======================
void addnewProject(Project ListPro[], int *ProCount){
	if ((*ProCount) >= MAX_PRO){
		printf("THE NUMBER OF PROJECT IN LIST PROJECT IS FULL (MAXIMUM 50) -_-\n");
		return;
	}
	
	demPro++; 

	snprintf(ListPro[*ProCount].IDPro, sizeof(ListPro[*ProCount].IDPro), "PRO%03d", demPro);

	Project* p = &ListPro[*ProCount];
	
	snprintf(p->IDPro, sizeof(p->IDPro), "PRO%03d", demPro);
	
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

 //// ==============ASSIGN PROJECT TO DEVELOPER====================
>>>>>>> b235272930b7833d84163ed2ad6ee994bfa5a65b

void assignProjecttoDev(){
<<<<<<< HEAD
    char devID[7];
    char proID[7];

    printf("Enter Developer ID: ");
    scanf("%6s", devID);

    int devIndex = findDevByID(devID, ListDev, DevCount);

    if(devIndex < 0)
    {
        printf("Developer not found!\n");
        return;

void assignProjecttoDev(Project ListPro[], char IdDev[]){
=======
>>>>>>> b235272930b7833d84163ed2ad6ee994bfa5a65b
	int index = LuaChon_assignProjecttoDev(ListPro);
	if (index == -1 || index == 0){
		return;
	}
	
	if(ListPro[index].MemberCount >= MAX_MEM){
       printf("Project is full\n");
       pauseSystem();
       return;
<<<<<<< HEAD

=======
>>>>>>> b235272930b7833d84163ed2ad6ee994bfa5a65b
    }
	//===========ĐOẠN TRÊN XÉT TÍNH ĐÚNG SAI TRƯỚC KHI VÀO=========
	
	int pos = ListPro[index].MemberCount;
	
	strcpy(ListPro[index].Members[pos], ListDev[index].ID);
		//=====SAU KHI GAN XONG THI SE TINH EXP CHO DEV
	ListDev[findDevbyID(ListDev, DevCount, ListDev[index].ID)].totalExp += ListPro[index].Duration;
      //==========SAU ĐÓ MEMBERCOUNT SẼ TĂNG LEN 1 ĐƠN VỊ
	ListPro[index].MemberCount++;
	
	printf("Assign Dev Successfully ^v^ \n");
}