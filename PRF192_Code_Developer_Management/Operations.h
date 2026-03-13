#ifndef OPERATION_H
#define OPERATION_H
#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

<<<<<<< HEAD
/*========================= validName function =========================*/
=======
/*========================= Find functions =========================*/
int findDevByName(char Name[], Developer ListDev[], int DevCount);
int findDevByID (char ID[], Developer ListDev[], int DevCount);
/*========================= Sort functions =========================*/
void sortByID (Developer ListDev[],  int DevCount, char ID []);
void sortBySalary (Developer ListDev[], int DevCount, double Salary[]);
/*========================= Calculate functions =========================*/
int calculateTotalExperience (int duration, int ProCount);
/*========================= Validate functions =========================*/
int validBirthDay (char BirthDay[]);
int validID (char ID[]);
>>>>>>> d5048850c9accad2b2f982585f98a085f80f14f3
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

