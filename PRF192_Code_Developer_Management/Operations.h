#ifndef OPERATION_H
#define OPERATION_H
#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*========================= CAC HAM INPUT =========================*/

/*========================= input NameDev function =========================*/
void inputNameDev(char name[]);
/*========================= input NameProJECT function =========================*/
void inputNamePro(char name[]);
/*========================= input functions =========================*/
void inputIdDev (char devID[]);
/*------------------------- inputIdPro function -------------------------*/
void inputIdPro (char proID[]);





/*========================= DINH DANG FORMAT =========================*/
void lTrim(char str[]);
void rTrim(char str[]);
void trim(char str[]);
void nameStr(char str[]);

void formatNameDev(char name[]);
void formatNamePro(char name[]);
void formatIdDev(char name[]);
void formatIdPro(char name[]);
void formatLanguage(char name[]);
void formatBirthDate(char name[] );





/*========================= KIEM TRA GIA TRI=========================*/

/*========================= ValidateName functions =========================*/
int validateName (char name[]);

/*========================= ValidateID functions =========================*/
int validateSalary (double Salary);

/*========================= validateID function =========================*/
int validateID(char ID[]);

/*========================= validBirthDay function =========================*/
int validateBirthDate (char BirthDay[]);
/*========================= validLanguage function =========================*/
int validateLanguage (char Language[]);





/*========================= TIM KIEM=========================*/

/*========================= findDevByName function =========================*/
int findDevByName(char Name[], Developer ListDev[], int DevCount);

/*========================= findDevByID function =========================*/
int findDevbyID(Developer ListDev[], int DevCount, char ID[]);






/*========================= SAP XEP=========================*/

/*========================= Sort =========================*/
void swap(Developer *a, Developer *b);
/*========================= sortByID function =========================*/
void sortByID(Developer ListDev[], int DevCount);

/*========================= sortBySalary functions =========================*/
void sortBySalary(Developer ListDev[], int DevCount);



#endif 

