#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"
#include "Project.h"
#include "ConsoleIO.h"

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
    
    ListDev[*DevCount].totalExp = 0;
    (*DevCount)++;
}
//
//////  nhap vao id


////  nhap vao id
//void inputIdDev(char ID[])
//{                              ben operation dax lam
//	scanf("%[^\n]",ID);
//	getchar();
//}



////// kiem tra xem ID co hop le hay khong

// ham nay operation da viet
/*
int validateID(char ID[]) {
    if (strlen(ID) != 6)
        return 0;

    // Check first 3 characters
    if (ID[0] != 'D' || ID[1] != 'E' || ID[2] != 'V')
        return 0;

    // Check last 3 characters are digits
    if (!isdigit(ID[3]) || 
        !isdigit(ID[4]) || 
        !isdigit(ID[5]))
        return 0;

    return 1;
}
*/
//////// hien thi ra man hinh thong tin cua dev sau khi nhap ID

//
//
//////// kiem tra xem ID co hop le hay khong
//
////////// hien thi ra man hinh thong tin cua dev sau khi nhap ID
void displayDeveloper(Developer ListDev[],int DevCount,char devID[]){
    if (validateID(devID))
    {
    	int index = findDevbyID(ListDev, DevCount, devID);
    	if (index == -1){
    		printf("THIS ID IS NOT FOUND -_-\n");
    		return;
		}
		
		printf("%-10s %-20s %-15s %-25s %-10.2lf %-12d\n", ListDev[index].ID,
												ListDev[index].Name,
												ListDev[index].BirthDate,
												ListDev[index].Language,
												ListDev[index].Salary,
												ListDev[index].totalExp);
	}
}
//
//
void displayAllDev(Developer ListDev[],int DevCount){
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
    
    //===================HÀM NÀY LÀ HÀM XÁC NHẬN DEV ĐÓ HIỆN TẠI ĐANG LÀM HAY ĐANG CÓ PROJECT
    int found = 0;
    int pos = 0;
    for (int i = 0; i < ProCount; i++){
    	if (isDevInProject(ListPro, devID, ListPro[i].IDPro, ProCount)){
    		found = 1;
    		pos = findProjectbyID(ListPro[i].IDPro, ListPro);
    		break;
		} 
	}
	
	if (found){
		printf("ThIS DEVELOPER IS WORKING IN %s PROJECT\n", ListPro[pos].NamePro);
		printf("SO WE CANNOT FIRE THEM\n");
		return;
	}
    //==============KHÚC KIỂM TRA ĐIỀU KIỆN

    for(int i = index; i < *DevCount - 1; i++)
    {
        ListDev[i] = ListDev[i + 1];
    }

    (*DevCount)--;

    printf("Developer deleted successfully!\n");
}


void updateSalary(Developer ListDev[],int DevCount, char ID[])
{
	int index = findDevbyID(ListDev, DevCount, ID);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
      
    printf("CURRENT INFORMATION: %s - salary: %.2f\n", ListDev[index].Name, ListDev[index].Salary);

    double newSalary;

    

    do{
    printf("Enter new salary: ");
    scanf("%lf", &newSalary);
    
    if (newSalary >= 1000){
    ListDev[index].Salary = newSalary;
    printf("Update successfully!\n");
    }
        
    else{
        printf("Salary must be at least 1000!\n");
        printf("The new Salary must be upper than 1000$. Enter again ^v^\n");
        pauseSystem();
        continue;
    }
	}while (true);

}



// update Language
void updateLanguage(Developer ListDev[],int DevCount,char devID[])
{
	int index = findDevbyID(ListDev, DevCount, devID);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].Language);
    
    char newLanguage[20];
    scanf("%[\n]",newLanguage);
    getchar();
    
    strcpy(ListDev[index].Language,newLanguage);
    printf("Update Language successfully !");
    
}

// update Birthday
//void updateBirthday(Developer ListDev[],int DevCount,char devID[])
//{
//    int index = findDevbyID(ListDev, DevCount, devID);
//	if (index < 0)
//      {
//        printf("ID not found!\n");
//        return;
//      }
//    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].BirthDate);
//	
//	printf("ENTER THE NEW BIRTHDAY (YYYYMMDD): ");
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

void updateName(Developer ListDev[],int DevCount,char ID[])
{
	int index = findDevbyID(ListDev, DevCount, ID);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
    printf("ID: %s - THE CURRENT NAME: %s\n",ListDev[index].ID, ListDev[index].Name);
    
    printf("ENTER THE NEW NAME: ");
    char newName[7];
    scanf("%[\n]",newName);
    getchar();
    
    if (validateID(newName))
    {
    	strcpy(ListDev[index].Name,newName);
    	printf("Update Name successfully !\n");
	}
	else printf("Fail update Name\n");
    
}
//void totalExperience(Developer ListDev[], int DevCount, char ID[], Project LisPro[], char proID[])
//{
//	int index = findDevByID(ID, ListDev, DevCount);
//	if (index < 0)
//      {
//        printf("ID not found!\n");
//        return;
//      }
//    
//    for (int i = 0; i < ProCount; i++)
//    {
//    	if (isDevInProject(ListPro, ID, proID, ProCount))
//    	{
//    	    ListDev[index].totalExp += ListPro[i].Duration;
//		}
//	}
//	 printf("Total experience of Dev %s: %d month(s)\n",
//           ID, ListDev[index].totalExp);
//}

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

