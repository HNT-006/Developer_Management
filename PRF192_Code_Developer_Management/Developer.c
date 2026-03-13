#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
 listdev
 listpro

void addDeveloper(Developer listdev[],int *DevCount)
{
    if(DevCount >= MAX_DEV)
    {
        printf("Developer list is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%6[^\n]", listdev[DevCount].ID);
    getchar();

    printf("Enter Name: ");
    scanf("%19[^\n]", listdev[DevCount].Name);
    getchar();

    printf("Enter Birth Date (YYYYMMDD): ");
    scanf("%8[^\n]", listdev[DevCount].BirthDate);
    getchar();

    printf("Enter Language: ");
    scanf("%19[^\n]", listdev[DevCount].Language);
    getchar();

    printf("Enter Salary: ");
    scanf("%lf", &listdev[DevCount].Salary);
    getchar();

    (*DevCount)++;   // tăng số developer
}

////  nhap vao id
void inputID(char id[7])
{
	scanf("%[^\n]",id);
	getchar();
}



////// kiem tra xem ID co hop le hay khong
int validateID(char id[7]) {
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
void displaydev(Developer listdev[],int DevCount,char id[7])
{
    if (validateID(id))
    {
    	for (int i=0;i<DevCount;i++)
    	{
    	   if (strcmp(id,listdev[i].ID)==0)
    	   {
    	   	printf("ID: %s | Name: %s | BirthDate: %s | Language: %s | Salary: %.2lf\n",listdev[i].ID,listdev[i].Name,listdev[i].BirthDate,listdev[i].Language,listdev[i].Salary);
		   }
		}
	}
}


void displayAllDev(Developer listdev[],int Devcount)
{
	for(int i=0;i<DevCount;i++)
	{
	   printf("ID: %s | Name: %s | BirthDate: %s | Language: %s | Salary: %.2lf\n",listdev[i].ID,listdev[i].Name,listdev[i].BirthDate,listdev[i].Language,listdev[i].Salary);
	}
}

