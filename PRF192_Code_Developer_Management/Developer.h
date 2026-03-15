#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int demDev = 0;



//================ADDING DEVELOPER==================
void addDeveloper(Developer ListDev[],int *DevCount);



    /// DISPLAY INFORMATION
void displayDeveloper(Developer ListDev[],int DevCount,char ID[]);

void displayAllDev(Developer ListDev[],int Devcount);

 
   //DELETE DEVELOPER
void deleteDeveloper(Developer ListDev[], int *DevCount, char ID[]);

 /// UPDATE INFORMATION
void updateSalary(Developer ListDev[],int DevCount, char ID[]);

void updateName(Developer ListDev[],int DevCount,char ID[]);

void updateLanguage(Developer ListDev[],int DevCount,char ID[]);

void updateBirthday(Developer ListDev[],int DevCount,char ID[]);


    /// TOTAL EXPERIENCE
void totalExperience(Developer ListDev[],int DevCount,char ID[]);


//================HAM FIND TAM THOI ==================

#endif