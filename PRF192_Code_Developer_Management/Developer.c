#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"

void addDeveloper(Developer ListDev[],int *DevCount)
{
    if(*DevCount >= MAX_DEV)
    {
        printf("Developer list is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%6[^\n]", ListDev[*DevCount].ID);
    getchar();

    printf("Enter Name: ");
    scanf("%19[^\n]", ListDev[DevCount].Name);
    getchar();

    printf("Enter Birth Date (YYYYMMDD): ");
    scanf("%8[^\n]", ListDev[DevCount].BirthDate);
    getchar();

    printf("Enter Language: ");
    scanf("%19[^\n]", ListDev[DevCount].Language);
    getchar();

    printf("Enter Salary: ");
    scanf("%lf", &ListDev[DevCount].Salary);
    getchar();

    (*DevCount)++;   // tăng số developer
}

////  nhap vao id
void inputID(char id[])
{
	scanf("%[^\n]",id);
	getchar();
}



////// kiem tra xem ID co hop le hay khong
int validateID(char id[]) {
    if (strlen(id) != 6)
        return 0;

    // Check first 3 characters
    if (id[0] != 'D' || id[1] != 'E' || id[2] != 'V')
        return 0;

    // Check last 3 characters are digits
    if (!isdigit(id[3]) || 
        !isdigit(id[4]) || 
        !isdigit(id[5]))
        return 0;

    return 1;
}

//////// hien thi ra man hinh thong tin cua dev sau khi nhap ID
void displaydev(Developer ListDev[],int DevCount,char id[])
{
    if (validateID(id))
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

