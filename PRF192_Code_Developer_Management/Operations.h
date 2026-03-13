#ifndef OPERATION_H
#define OPERATION_H
#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*========================= validName function =========================*/
int validName (char Name[]);

/*========================= validByID function =========================*/
int validID (char ID[]);

/*========================= validBirthDay function =========================*/
int validBirthDay (char BirthDay[]);

/*========================= findDevByName function =========================*/
int findDevByName(char Name[], Developer ListDev[], int DevCount);

/*========================= findDevByID function =========================*/
int findDevByID (char ID[], Developer ListDev[], int DevCount);

/*========================= calculateTotalExperience function =========================*/
int calculateTotalExperience (int ProCount);

/*========================= sortByID function =========================*/
void sortByID(Developer ListDev[], int DevCount);

/*========================= sortBySalary functions =========================*/
void sortBySalary(Developer ListDev[], int DevCount);



#endif 

// tìm kiếm, sắp xếp, tính toán, xác thực (vận hành chung). Cá nhân Tuấn làm