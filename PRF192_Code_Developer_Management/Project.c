#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"
#include "Project.h"

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
void addnewProject(){
	if ((*ProCount) >= MAX_PRO){
		printf("THE NUMBER OF PROJECT IN LIST PROJECT IS FULL (MAXIMUM 50) -_-\n");
		return;
	}
	
	Project* p = ListPro[ProCount];
	printf("Enter Name Project: ");
	p->NamePro = readString(p->NamePro);
	
	printf("Enter Duration (THE NUMBER OF MONTH, DEV HAVE TO FINISH PROJECT): ");
	p->Duration = readInt(p->Duration);
	
	printf("Enter StartDate (DATE, DEV START TO WORK): ");
	p->StartDate = readString(p->StartDate);
	
	p->MemberCount = 0;
	printf("Add new Project Successfully ^v^\n");
}

void assignProjecttoDev(){
	
}