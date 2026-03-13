#ifndef OPERATION_H
#define OPERATION_H
#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/*========================= ValidName functions =========================*/
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
int calculateTotalExperience (Project ListPro[], int ProCount);

/*========================= sortByID function =========================*/
void sortByID(Developer ListDev[], int DevCount);

/*========================= sortBySalary functions =========================*/
void sortBySalary(Developer ListDev[], int DevCount);



#endif 

