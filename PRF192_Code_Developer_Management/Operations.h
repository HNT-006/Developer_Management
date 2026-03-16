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
void inputIdDev (char devID[]);
/*------------------------- inputIdPro function -------------------------*/
void inputIdPro (char proID[]);


/*========================= ValidateName functions =========================*/
bool validateName (char name[]);

/*========================= ValidateID functions =========================*/
int validateSalary (double Salary);

/*========================= validateID function =========================*/
int validateID(char ID[]);

/*========================= validBirthDay function =========================*/
int validateBirthDay (char BirthDay[]);
/*========================= validLanguage function =========================*/
int validateLanguage (char Language[]);

/*========================= findDevByName function =========================*/
int findDevByName(char Name[], Developer ListDev[], int DevCount);

/*========================= findDevByID function =========================*/
int findDevbyID(Developer ListDev[], int DevCount, char ID[]);


/*========================= Sort =========================*/
void swap(Developer *a, Developer *b);
/*========================= sortByID function =========================*/
void sortByID(Developer ListDev[], int DevCount);

/*========================= sortBySalary functions =========================*/
void sortBySalary(Developer ListDev[], int DevCount);



#endif 

