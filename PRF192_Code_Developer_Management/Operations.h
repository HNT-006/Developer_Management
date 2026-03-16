#ifndef OPERATION_H
#define OPERATION_H
#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/*========================= input functions =========================*/
/*------------------------- inputIdDev function -------------------------*/
void inputIdDev (char ID[]);
/*------------------------- inputIdPro function -------------------------*/
void inputIdPro (char IDPro[]);


/*========================= ValidateName functions =========================*/
bool validateName (char name[]);

/*========================= validateID function =========================*/
int validateID(char ID[]);

/*========================= validBirthDay function =========================*/
int validBirthDay (char BirthDay[]);

/*========================= findDevByName function =========================*/
int findDevByName(char Name[], Developer ListDev[], int DevCount);

/*========================= findDevByID function =========================*/
int findDevbyID(Developer ListDev[], int DevCount, char ID[]);

/*========================= calculateTotalExperience function =========================*/
int calculateTotalExperience (Project ListPro[], int ProCount);

/*========================= sortByID function =========================*/
void sortByID(Developer ListDev[], int DevCount);

/*========================= sortBySalary functions =========================*/
void sortBySalary(Developer ListDev[], int DevCount);



#endif 

