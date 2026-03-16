
#include "Operations.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*========================= input devID function =========================*/
void inputIdDev (char devID[])
{
	scanf("%[^\n]",devID);
	getchar();
}
/*========================= input proID function =========================*/
void inputIdPro (char proID[])
{
	scanf("%[^\n]",proID);
	getchar();
}
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

/*========================= ValidateSalary function =========================*/
int validateSalary (double Salary) {
    if (Salary >= 1000 && Salary <= 100000)
        return 1;
    return 0;
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
int validateBirthDay (char BirthDay[]) {
	// Kiểm tra xem độ dài có đúng 8 kí tự hay chưa
	if (strlen(BirthDay) != 8) {
		return 0;
	}
	// Kiểm tra xem các kí tự đó có phải là số hay không?
	for (int i=0; i<8; i++) {
		if (BirthDay[i]<'0' || BirthDay[i]>'9')
			return 0;
	}
	// Tách DDMMYY ra từ chuỗi
	char tmpD[3]= {BirthDay[0], BirthDay[1], '\0'};
	char tmpM[3]= {BirthDay[2], BirthDay[3], '\0'};
	char tmpY[5]= {BirthDay[4], BirthDay[5], BirthDay[6], BirthDay[7], '\0'};
	// chuyển chuỗi thành sô
	int d=atoi(tmpD);
	int m=atoi(tmpM);
	int y=atoi(tmpY);

	// Kiểm tra năm (ví dụ Developer phải từ 18 tuổi -> 56 tuổi)
	if (y<1970 || y>2008) {
		return 0;
	}
	// Kiểm tra tháng
	if (m<1 || m>12) {
		return 0;
	}
	// Kiểm tra ngày
	int maxDays = 31; // Mặc định là ngày 31
	if (m==4 || m==6 || m==9 || m==11) {
		maxDays = 30;
	} else if (m==2) {
		// Kiểm tra năm nhuận cho tháng 2
		if ((y%400==0)||(y%4==0 && y%100!=0)) {
			maxDays=29;
		} else maxDays=28;
	}
	if (d<1 || d>maxDays) {
		return 0;
	}
	return 1; // Chương trình chạy đến return 1 là kết quả hợp lệ
}
/*========================= validate Language =========================*/
int validateLanguage (char Language[]) {
	// Check string
	if (Language==NULL || strlen(Language)==0)
		return 0;
	// List of language of system
	char *LanguageS []= {"C++", "Java", "JS", "HTML/CSS"};
	int totalLanguae=4;
	for (int i=0; i<totalLanguae; i++) {
		if (strcmp(Language, LanguageS[i])==0)
			return 1;
	}
	return 0;
	
}
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
/*------------------------- partitionBySalary function -------------------------*/
int partitionBySalary(Developer ListDev[], int l, int r) {
	double pivot = ListDev[r].Salary; // 
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (ListDev[j].Salary < pivot) {
			i++;
			swap(&ListDev[i], &ListDev[j]); //  đúng tên mảng
		}
	}
	i++;
	swap(&ListDev[i], &ListDev[r]);
	return i;
}

/*------------------------- quicksortBySalary function -------------------------*/
void quicksortBySalary(Developer ListDev[], int l, int r) {
	if (l >= r) return;
	int p = partitionBySalary(ListDev, l, r);
	quicksortBySalary(ListDev, l, p - 1);
	quicksortBySalary(ListDev, p + 1, r);
}

/*------------------------- sortBySalary function -------------------------*/
void sortBySalary(Developer ListDev[], int DevCount) {
	if (DevCount <= 1) return;
	quicksortBySalary(ListDev, 0, DevCount - 1);
}


