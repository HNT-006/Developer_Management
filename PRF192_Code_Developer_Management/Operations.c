
#include "Operations.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*========================= ValidateName function =========================*/
bool validateName(char name[]) {
    int length = strlen(name);
    int spaceCount = 0;

    if (length == 0) return false;

    for (int i = 0; i < length; i++) {
        if (name[i] == ' ') {
            spaceCount++;
        }
    }

    if (spaceCount >= 1) {
        return true;
    }

    return false;
}


/*========================= validateID function =========================*/
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


/*========================= validBirthDay function =========================*/
int validBirthDay (char BirthDay[]);









/*========================= findDevByName function =========================*/
// Trả về: index nếu tìm thấy | -1 nếu không tìm thấy | -2 nếu Name không hợp lệ
int findDevByName(char Name[], Developer ListDev[], int DevCount)
{
    // Kiểm tra format tên
    if (!validateName(Name))
    {
        return -2; // Name không hợp lệ
    }

    for (int i = 0; i < DevCount; i++)
    {
        if (strcmp(ListDev[i].Name, Name) == 0)
        {
            return i; // Tìm thấy, trả về vị trí
        }
    }

    return -1; // Không tìm thấy
}


/*========================= findDevByID function =========================*/
// Trả về: index nếu tìm thấy | -1 nếu không tìm thấy | -2 nếu ID không hợp lệ
int findDevbyID(Developer ListDev[], int DevCount, char ID[]){
	if (!validateID(ID)){
		return -1;
	} 
	
	for (int i = 0; i < DevCount; i++){
		if (strcmp(ID, ListDev[i].ID) == 0) return i;
	}
	
	return -1;
}


/*========================= calculateTotalExperience function =========================*/
int calculateTotalExperience (Project ListPro[], int ProCount) {
	if (ProCount==0) return 0;
	
	int total =0;
	for (int i=0; i<ProCount; i++) {
		total=total+ListPro[i].Duration;
	}
	return total;
}


/*========================= sortByID function =========================*/
/*------------------------- swap function -------------------------*/
void swap(Developer *a, Developer *b)
{
    Developer tmp = *a;
    *a = *b;
    *b = tmp;
}

/*------------------------- partition function -------------------------*/
int partition(Developer ListDev[], int l, int r)
{
    char pivot[7];
    strcpy(pivot, ListDev[r].ID);

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (strcmp(ListDev[j].ID, pivot) < 0)
        {
            i++;
            swap(&ListDev[i], &ListDev[j]);
        }
    }
    i += 1;
    swap(&ListDev[i], &ListDev[r]);
    return i;
}

/*------------------------- quicksort function -------------------------*/
void quicksort(Developer ListDev[], int l, int r)
{
    if (l >= r) return;

    int p = partition(ListDev, l, r);
    quicksort(ListDev, l, p - 1);
    quicksort(ListDev, p + 1, r);
}

/*------------------------- sortByID function -------------------------*/
void sortByID(Developer ListDev[], int DevCount)
{
    if (DevCount <= 1) return; // Không cần sort nếu chỉ có 1 phần tử

    quicksort(ListDev, 0, DevCount - 1);
}




/*========================= sortBySalary functions =========================*/



