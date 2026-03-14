#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"

void addDeveloper(Developer ListDev[],int *DevCount){
	
    if(*DevCount >= MAX_DEV)
    {
        printf("Developer list is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%6[^\n]", ListDev[*DevCount].ID);
    getchar();

    printf("Enter Name: ");
    scanf("%19[^\n]", ListDev[*DevCount].Name);
    getchar();

    printf("Enter Birth Date (YYYYMMDD): ");
    scanf("%8[^\n]", ListDev[*DevCount].BirthDate);
    getchar();

    printf("Enter Language: ");
    scanf("%19[^\n]", ListDev[*DevCount].Language);
    getchar();

    printf("Enter Salary: ");
    scanf("%lf", &ListDev[*DevCount].Salary);
    getchar();

    (*DevCount)++;   // tăng số developer
}

////  nhap vao id
void inputID(char ID[])
{
	scanf("%[^\n]",ID);
	getchar();
}



////// kiem tra xem ID co hop le hay khong
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

//////// hien thi ra man hinh thong tin cua dev sau khi nhap ID
void displaydev(Developer ListDev[],int DevCount,char ID[])
{
    if (validateID(ID))
    {
    	for (int i=0;i<DevCount;i++)
    	{
    	   if (strcmp(id,ListDev[i].ID)==0)
    	   {
    	   	printf("ID: %s | Name: %s | BirthDate: %s | Language: %s | Salary: %.2lf\n",ListDev[i].ID,ListDev[i].Name,ListDev[i].BirthDate,ListDev[i].Language,ListDev[i].Salary);
		   }
		}
	}
}


void displayAllDev(Developer ListDev[],int Devcount)
{
	for(int i=0;i<DevCount;i++)
	{
	   printf("ID: %s | Name: %s | BirthDate: %s | Language: %s | Salary: %.2lf\n",ListDev[i].ID,ListDev[i].Name,ListDev[i].BirthDate,ListDev[i].Language,ListDev[i].Salary);
	}
}

//// ham deleteDev
void deleteDev(Developer ListDev[], int *DevCount, char ID[])
{
    int index = findDevByID(ID,ListDev,*DevCount);

    if(index == -2)
    {
        printf("Invalid ID format!\n");
        return;
    }

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

    printf("Developer deleted successfully!\n");
}

void updateSalary(Developer ListDev[],int DevCount, char ID[])
{
	int index=findDevByID(ID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
      printf("Current info: %s - salary: %.2f\n",ListDev[index].Name, ListDev[index].Salary);

    float newSalary;

    printf("Enter new salary: ");
    scanf("%f", &newSalary);

    if (newSalary >= 1000)
    {
        ListDev[index].Salary = newSalary;
        printf("Update successfully!\n");
    }
    else
    {
        printf("Salary must be at least 1000!\n");
    }

}

// update ID
void updateID(Developer ListDev[],int DevCount,char ID[])
{
	int index=findDevByID(ID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].ID);
    
    char newID[7];
    scanf("%[\n]",newID);
    getchar();
    
    if (validateID(newID))
    {
    	strcpy(ListDev[index].ID,newID);
    	printf("Update ID successfully !");
	}
	else printf("Fail update ID");
    
}

// update Language
void updateLanguage(Developer ListDev[],int DevCount,char ID[])
{
	int index=findDevByID(ID,ListDev,DevCount);
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
void updateBirthday(Developer ListDev[],int DevCount,char ID[])
{
       int index=findDevByID(ID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
    printf("Current info: %s - ID: %s\n",ListDev[index].Name, ListDev[index].BirthDate);
	
	char newBirth[9];
	scanf("%[\n]",newBirth);
	getchar();	
	
	if (validBirthDay(newBirth))
	{
		strcpy(listDev[index].newBirth);
		getchar();
		printf("Update Birthday successfully")
	}
}

void totalExperience(Developer ListDev[],int DevCount,char ID[])
{
	int index=findDevByID(ID,ListDev,DevCount);
	if (index < 0)
      {
        printf("ID not found!\n");
        return;
      }
}
