#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"


//==================CODE CAC HAM TAM THOI. SAU DO CO THE BO SANG OPERATIONS.C.H=======================

//=====================================================================================

void addDeveloper(Developer ListDev[], int *DevCount){

    if(*DevCount >= MAX_DEV){
        printf("Developer list is full!\n");
        return;
    }

    getchar();

    demDev++;
    snprintf(ListDev[*DevCount].ID, sizeof(ListDev[*DevCount].ID), "DEV%03d", demDev);

    bool maintain = true;
    do{
    printf("Enter Name: ");
    scanf("%19[^\n]", ListDev[*DevCount].Name);
    getchar();
    if (!validateName(ListDev[*DevCount].Name)){
	
    printf("THIS NAME IS INVALID -_- \n");
    continue;
	} else{
		maintain = false;
	}
    } while (maintain);
    
    printf("Enter Birth Date (YYYYMMDD): ");
    scanf("%8[^\n]", ListDev[*DevCount].BirthDate);
    getchar();

    printf("Enter Language: ");
    scanf("%19[^\n]", ListDev[*DevCount].Language);
    getchar();

    printf("Enter Salary: ");
    scanf("%lf", &ListDev[*DevCount].Salary);
    getchar();

    (*DevCount)++;
}
//



//////// hien thi ra man hinh thong tin cua dev sau khi nhap ID

//
//
//////// kiem tra xem ID co hop le hay khong
//
////////// hien thi ra man hinh thong tin cua dev sau khi nhap ID
void displayDeveloper(Developer ListDev[],int DevCount,char devID[])
{
    if (validateID(devID))
    {
    	int index = findDevbyID(ListDev, DevCount, devID);
    	if (index == -1){
    		printf("THIS ID IS NOT FOUND -_-\n");
    		return;
		}
		
		printf("%-10s %-20s %-15s %-25s %-10.2lf\n", ListDev[index].ID,
												ListDev[index].Name,
												ListDev[index].BirthDate,
												ListDev[index].Language,
												ListDev[index].Salary);
	}
}
//
//
void displayAllDev(Developer ListDev[],int DevCount)
{
	for(int i=0;i<DevCount;i++)
	{
	   displayDeveloper(ListDev, DevCount, ListDev[i].ID);
	}
}
//


////// =========================HAM DELETE========================
void deleteDeveloper(Developer ListDev[], int *DevCount, char devID[])
{

    if(!validateID(devID))
    {
        printf("Invalid ID format!\n");
        return;
    }
    
    int index = findDevbyID(ListDev, *DevCount, devID);
    if(index == -1)
    {
        printf("Developer not found!\n");
        return;
    }

    for(int i = index; i < *DevCount - 1; i++)
    {
        ListDev[i] = ListDev[i + 1];
    }

    (*DevCount)--;

     // cập nhật lại ID
    for(int i = 0; i < *DevCount; i++)
    {
        sprintf(ListDev[i].ID, "DEV%03d", i + 1);
    }

    printf("Developer deleted successfully!\n");
}

void updateSalary(Developer ListDev[],int DevCount, char devID[])
{
	int index=findDevByID(devID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
      printf("Current info: %s - salary: %.2f\n",ListDev[index].Name, ListDev[index].Salary);

    float newSalary;

    printf("Enter new salary: ");
    scanf("%f", &newSalary);

    if (validateSalary(newSalary))
    {
        ListDev[index].Salary = newSalary;
        printf("Update successfully!\n");
    }
    else
    {
        printf("Salary must be at least 1000!\n");
    }

}



// update Language
void updateLanguage(Developer ListDev[],int DevCount,char devID[])
{
	int index=findDevByID(devID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].Language);
    
    char newLanguage[20];
    scanf("%[\n]",newLanguage);
    getchar();
    if (validateLanguage(newLanguage)!=1) return;
    strcpy(ListDev[index].Language,newLanguage);
    printf("Update Language successfully !");
    
}

// update Birthday
void updateBirthday(Developer ListDev[],int DevCount,char devID[])
{
    int index = findDevByID(devID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].BirthDate);
	
	char newBirth[9];
	scanf("%[\n]",newBirth);
	getchar();	

	if (validateBirthDay(newBirth))
	{
		strcpy(ListDev[index].BirthDate, newBirth);
		getchar();
		printf("Update Birthday successfully");
	}
}

void totalExperience(Developer ListDev[],int DevCount,char devID[],Project LisPro[])
{
	int index=findDevByID(ID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
      
     ListDev[index].totalExp = 0;   // reset trước khi tính
    for (int i=0;i<ProCount;i++)
    {
    	if (isDevInProject(ListPro,devID,proID,ProCount))
    	{
    	    ListDev[intdex].totalExp+=ListPro[i].Duration;
		}
	}
	 printf("Total experience of Dev %s: %d month(s)\n",
           ID, ListDev[index].totalExp);
}

//
//void updateSalary(Developer ListDev[],int DevCount, char ID[])
//{
//	int index=findDevByID(ID,ListDev,DevCount);
//	if (index < 0)
//      {
//        printf("ID not found!\n");
//        return;
//      }
//      printf("Current info: %s - salary: %.2f\n",ListDev[index].Name, ListDev[index].Salary);
//
//    float newSalary;
//
//    printf("Enter new salary: ");
//    scanf("%f", &newSalary);
//
//    if (newSalary >= 1000)
//    {
//        ListDev[index].Salary = newSalary;
//        printf("Update successfully!\n");
//    }
//    else
//    {
//        printf("Salary must be at least 1000!\n");
//    }
//
//}
//
//// update ID
//void updateName(Developer ListDev[],int DevCount,char ID[])
//{
//	int index=findDevByID(ID,ListDev,DevCount);
//	if (index < 0)
//      {
//        printf("ID not found!\n");
//        return;
//      }
//    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].ID);
//    
//    char newID[7];
//    scanf("%[\n]",newID);
//    getchar();
//    
//    if (validateID(newID))
//    {
//    	strcpy(ListDev[index].ID,newID);
//    	printf("Update ID successfully !");
//	}
//	else printf("Fail update ID");
//    
//}
//
//// update Language
//void updateLanguage(Developer ListDev[],int DevCount,char ID[])
//{
//	int index=findDevByID(ID,ListDev,DevCount);
//	if (index < 0)
//      {
//        printf("ID not found!\n");
//        return;
//      }
//    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].Language);
//    
//    char newLanguage[20];
//    scanf("%[\n]",newLanguage);
//    getchar();
//    
//    strcpy(ListDev[index].Language,newLanguage);
//    printf("Update Language successfully !");
//    
//}
//
//// update Birthday
//void updateBirthday(Developer ListDev[],int DevCount,char ID[])
//{
//    int index = findDevByID(ID,ListDev,DevCount);
//	if (index < 0)
//      {
//        printf("ID not found!\n");
//        return;
//      }
//    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].BirthDate);
//	
//	char newBirth[9];
//	scanf("%[\n]",newBirth);
//	getchar();	
//	
//	if (validBirthDay(newBirth))
//	{
//		strcpy(ListDev[index].BirthDate, newBirth);
//		getchar();
//		printf("Update Birthday successfully");
//	}
//}
////
////void totalExperience(Developer ListDev[],int DevCount,char ID[])
////{
////	int index=findDevByID(ID,ListDev,DevCount);
////	if (index < 0)
////      {
////        printf("ID not found!\n");
////        return;
////      }
////}
