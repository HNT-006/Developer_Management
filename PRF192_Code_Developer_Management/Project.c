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

char* readString(char str[]){
	scanf("%[^\n]", str);
	return str;
}

void addnewProject(){
	if ((ProCount) >= MAX_PRO){
		printf("THE NUMBER OF PROJECT IN LIST PROJECT IS FULL (MAXIMUM 50) -_-\n");
		return;
	}
	
	demPro++; 
	Project* p = &ListPro[ProCount];
	
	sprintf(p->IDPro, sizeof(p->IDPro), "PRO%03d", demPro);
	
	printf("Enter Name Project: ");
	p->NamePro = readString(p->NamePro);
	
	printf("Enter Duration (THE NUMBER OF MONTH, DEV HAVE TO FINISH PROJECT): ");
	p->Duration = readInt(p->Duration);
	
	printf("Enter StartDate (DATE, DEV START TO WORK): ");
	p->StartDate = readString(p->StartDate);
	
	p->MemberCount = 0;
	printf("Add new Project Successfully ^v^\n");
}

// Ham kiem tra Dev đã có trong project chưa
int isDevInProject(Project ListPro[], int proIndex, char devID[])  
{
    for(int i = 0; i < ListPro[proIndex].MemberCount; i++)
    {
        if(strcmp(ListPro[proIndex].Members[i], devID) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void assignProjecttoDev(){
    char devID[7];
    char proID[7];

    printf("Enter Developer ID: ");
    scanf("%6s", devID);

    int devIndex = findDevByID(devID, ListDev, DevCount);

    if(devIndex < 0)
    {
        printf("Developer not found!\n");
        return;
    }

    printf("Enter Project ID: ");
    scanf("%6s", proID);

    int proIndex = findProjectByID(proID, ListPro, ProCount);

    if(proIndex < 0)
    {
        printf("Project not found!\n");
        return;
    }

    if(isDevInProject(ListPro, proIndex, devID))
    {
        printf("Developer already in this project!\n");
        return;
    }

    strcpy(ListPro[proIndex].Members[ListPro[proIndex].MemberCount], devID);

    ListPro[proIndex].MemberCount++;

    printf("Assign successfully!\n");
}