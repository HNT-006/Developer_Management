#ifndef OPERATION_H
#define OPERATION_H
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*========================= Find functions =========================*/
int findDevByName(char Name[], Developer developers[], int DevCount);
int findDevByID (char ID[], Developer developers[], int DevCount);
/*========================= Sort functions =========================*/
void sortByID (Developer developers[],  int DevCount, char ID []);
void sortBySalary (Developer developers[], int DevCount, double Salary[]);
/*========================= Calculate functions =========================*/
int calculateTotalExperience (int duration, int ProCount);
/*========================= Validate functions =========================*/
int validBirthDay (char BirthDay[]);
int validID (char ID[]);
int validName (char Name[]);

#endif 

// tìm kiếm, sắp xếp, tính toán, xác thực (vận hành chung). Cá nhân Tuấn làm