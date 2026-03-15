#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <string.h>

#define MAX_DEV 300
#define MAX_PRO 50

typedef struct{
	char ID[7];
	char Name[20];
	char BirthDate[9];
	char Language[20];
	double Salary;
	
	int totalExp;
	int totalPro;
	
} Developer;


typedef struct{
	char IDPro[7];
	char NamePro[20];
    int Duration;  //So thang hoan thanh Project
    char StartDate[9];  // Ngay thang nam bat dau
    
    char Members[MAX_DEV][7];  //Luu so luong ID DEV thuc hien + Do dai cua ID DEV
    int MemberCount;

} Project;


//============ EXTERN: CHỈ THÔNG BÁO LÀ CÁC BIẾN NÀY SẼ ĐƯỢC KHAI BÁO Ở MAIN.C
//===================== KHÔNG KHAI BÁO TIẾP CỦA CÁC FILE KHÁC.
//======================= CHỈ CẦN LẤY VÀ SÀI THÔI
extern int DevCount;
extern int ProCount;
extern Developer ListDev[MAX_DEV];
extern Project ListPro[MAX_PRO];
#endif