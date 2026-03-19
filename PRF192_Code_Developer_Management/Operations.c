
#include "Operations.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*========================= CAC HAM DINH DANG FORMAT =========================*/
void lTrim(char str[]) {
    int i = 0;
    while (str[i] == ' ') i++;

    int j = 0;
    while (str[i] != '\0') {
        str[j] = str[i];
        i++; j++;
    }
    str[j] = '\0';
}

void rTrim(char str[]) {
    int len = strlen(str) - 1;
    while (len >= 0 && str[len] == ' ') {
        str[len] = '\0';
        len--;
    }
}

void trim(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        } else if (j > 0 && str[j-1] != ' ') {
            str[j++] = ' ';
        }
        i++;
    }
    str[j] = '\0';
}

void nameStr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (i == 0 || str[i-1] == ' ')
            str[i] = toupper(str[i]);
        else
            str[i] = tolower(str[i]);
        i++;
    }
}





void formatNameDev(char name[])
{
     lTrim(name);      // bỏ khoảng trắng đầu
     rTrim(name);      // bỏ khoảng trắng cuối
     trim(name);       // bỏ khoảng trắng dư giữa các từ
     nameStr(name);    // viết hoa chữ cái đầu mỗi từ
}

void formatNamePro(char name[])
{
	 lTrim(name);      // bỏ khoảng trắng đầu
     rTrim(name);      // bỏ khoảng trắng cuối
     trim(name);       // bỏ khoảng trắng dư giữa các từ
     nameStr(name);    // viết hoa chữ cái đầu mỗi từ
}

void formatIdDev(char name[])
{
	 lTrim(name);      // bỏ khoảng trắng đầu
     rTrim(name);      // bỏ khoảng trắng cuối
}

void formatIdPro(char name[])
{
	 lTrim(name);      // bỏ khoảng trắng đầu
     rTrim(name);      // bỏ khoảng trắng cuối
}
 
void formatLanguage(char name[])
{
	lTrim(name);      // bỏ khoảng trắng đầu
    rTrim(name);      // bỏ khoảng trắng cuối
}

void formatBirthDate(char name[] )
{
		lTrim(name);      // bỏ khoảng trắng đầu
    rTrim(name);      // bỏ khoảng trắng cuối
}




/*========================= HAM INPUT =========================*/

/*========================= input NameDev function =========================*/
void inputNameDev(char name[])
{
    scanf("%[^\n]",name);
    getchar();
}
/*========================= input NameProJECT function =========================*/
void inputNamePro(char name[])
{
	scanf("%[^\n]",name);
	getchar();
}

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



/*========================= HAM CHECK VALIDATE =========================*/

/*========================= ValidateName function =========================*/
int validateName(char name[])
{
    int length = strlen(name);
    int spaceCount = 0;

    if (length == 0)
        return 0;

    if (name[0] == ' ' || name[length - 1] == ' ')
        return 0;

    for (int i = 0; i < length; i++)
    {
        if (name[i] == ' ')
        {
            spaceCount++;

            if (name[i + 1] == ' ')
                return 0;
        }
    }

    if (spaceCount >= 1)
        return 1;

    return 0;
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
int validateBirthDate (char BirthDate[]) {
	// Kiểm tra xem độ dài có đúng 8 kí tự hay chưa
	if (strlen(BirthDate) != 8) {
		return 0;
	}
	// Kiểm tra xem các kí tự đó có phải là số hay không?
	for (int i=0; i<8; i++) {
		if (BirthDate[i]<'0' || BirthDate[i]>'9')
			return 0;
	}
	// Tách DDMMYY ra từ chuỗi
	char tmpD[3]= {BirthDate[0], BirthDate[1], '\0'};
	char tmpM[3]= {BirthDate[2], BirthDate[3], '\0'};
	char tmpY[5]= {BirthDate[4], BirthDate[5], BirthDate[6], BirthDate[7], '\0'};
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



/*========================= CAC HAM TIM KIEM =========================*/
/*========================= findDevByName function =========================*/
// Trả về: index nếu tìm thấy | -1 nếu không tìm thấy | -2 nếu Name không hợp lệ
int findDevByName(char Name[], Developer ListDev[], int DevCount)
{
    // Kiểm tra format tên
    formatNameDev(Name);
    
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
	formatIdDev(ID);
	if (!validateID(ID)){
		return -1;
	} 
	
	for (int i = 0; i < DevCount; i++){
		if (strcmp(ID, ListDev[i].ID) == 0) return i;
	}
	
	return -1;
}



/*========================= CAC HAM SAP XEP =========================*/

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


//=======================CÁC NORMALIZE NAME, BIRTHDATE VÀ STRING=======================

void normalizeBirthDate(char birthday[]){
    char day[3], month[3], year[5];

    strncpy(day, birthday, 2);
    day[2] = '\0';

    strncpy(month, birthday + 2, 2);
    month[2] = '\0';

    strncpy(year, birthday + 4, 4);
    year[4] = '\0';

    sprintf(birthday, "%s - %s - %s", day, month, year);
}