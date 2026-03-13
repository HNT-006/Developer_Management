<<<<<<< HEAD
=======

>>>>>>> d5048850c9accad2b2f982585f98a085f80f14f3
#include "Operations.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*========================= findDevByName function =========================*/
// Trả về: index nếu tìm thấy | -1 nếu không tìm thấy | -2 nếu Name không hợp lệ
int findDevByName(char Name[], Developer ListDev[], int DevCount)
{
    // Kiểm tra format tên
//    if (!validName(Name))
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
int findDevByID(char ID[], Developer ListDev[], int DevCount)
{
    // Kiểm tra format ID
//    if (!validID(ID))
    {
        return -2; // ID không hợp lệ
    }

    // Duyệt mảng từ 0 -> DevCount - 1
    for (int i = 0; i < DevCount; i++)
    {
        if (strcmp(ListDev[i].ID, ID) == 0)
        {
            return i; // Tìm thấy, trả về vị trí
        }
    }

    return -1; // Không tìm thấy
}

/*========================= validBirthDay function =========================*/

<<<<<<< HEAD
int validBirthDay (char BirthDay[]) {
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
	char tmpD[3]={BirthDay[0], BirthDay[1], '\0'};
	char tmpM[3]={BirthDay[2], BirthDay[3], '\0'};
	char tmpY[5]={BirthDay[4], BirthDay[5], BirthDay[6], BirthDay[7], '\0'};
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
	}
	else if (m==2) {
		// Kiểm tra năm nhuận cho tháng 2
		if ((y%400==0)||(y%4==0 && y%100!=0)) {
			maxDays=29;
		}
		else maxDays=28;
	}
	if (d<1 || d>maxDays) {
		return 0;
	}
	return 1; // Chương trình chạy đến return 1 là kết quả hợp lệ
}

/*========================= validID function =========================*/

int validID(char ID[]) {
    
    // Remove newline if using fgets
    ID[strcspn(ID, "\n")] = '\0';
//In fact: DEV100 is saved with form 'D' 'E' 'V' '1' '0' '0' '\n' '\0' 
//If don't remove '\n' -> length = 7 -> next step is wrong -> always wrong

    // Check length
    if (strlen(ID) != 6)
        return 0;

    // Check first 3 characters
    if (ID[0] != 'D' || ID[1] != 'E' || ID[2] != 'V')
        return 0;

    // Check last 3 characters are digits
    if (!isdigit(ID[3]) || !isdigit(ID[4]) || !isdigit(ID[5]))
        return 0;

    return 1;
}

/*========================= validName function =========================*/

int validName(char Name[]) {
	// Check empty name?
	if (Name==NULL || strlen(Name)==0) {
		return 0;
	}
	// Check length of Name?
	if (strlen(Name)>19) {
		return 0;
	}
	// Check alphabet Name?
	int i=0;
	while (Name[i] != '\0') {
		if (!isalpha(Name[i]) && (Name[i]!=' ')) {
			return 0;
		}
		i++;
	
	}
	
	// Check Name
    i = 0;
    int wordCount = 0;

    while (Name[i] != '\0') {
        
        if (Name[i] != ' ' && (i == 0 || Name[i - 1] == ' ')) {
            wordCount++;
        }
        i++;
    }

    if (wordCount >= 2)
        return 1;
    else
        return 0;
}

/*========================= calculateTotalExperience function =========================*/
int calculateTotalExperience (int ProCount) {
	if (ProCount==0) return 0;
	
	int total =0;
	for (int i=0; i<ProCount; i++) {
		total=total+ListPro[i].Duration;
	}
	return total;
}

/*========================= sortByID functions =========================*/
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
    strcpy(pivot, ListDev[r].ID); // Đúng tên mảng

    int i = l - 1;
    for (int j = l; j < r; j++) // j bắt đầu từ l
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
int partitionBySalary(Developer ListDev[], int l, int r)
{
    double pivot = ListDev[r].Salary; // ✅ double, không phải int
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (ListDev[j].Salary < pivot)
        {
            i++;
            swap(&ListDev[i], &ListDev[j]); // ✅ đúng tên mảng
        }
    }
    i++;
    swap(&ListDev[i], &ListDev[r]);
    return i;
}
/*------------------------- quicksortBySalary function -------------------------*/
void quicksortBySalary(Developer ListDev[], int l, int r)
{
    if (l >= r) return;
    int p = partitionBySalary(ListDev, l, r);
    quicksortBySalary(ListDev, l, p - 1);
    quicksortBySalary(ListDev, p + 1, r);
}
/*------------------------- sortBySalary function -------------------------*/
void sortBySalary(Developer ListDev[], int DevCount)
{
    if (DevCount <= 1) return;
    quicksortBySalary(ListDev, 0, DevCount - 1);
}







=======
>>>>>>> d5048850c9accad2b2f982585f98a085f80f14f3

