#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int getNextDevID();

//================ADDING DEVELOPER==================
void addDeveloper(Developer ListDev[],int *DevCount);



    /// DISPLAY INFORMATION
void displayDeveloper(Developer ListDev[],int DevCount,char devID[]);

void displayAllDev(Developer ListDev[],int Devcount);

 
   //DELETE DEVELOPER
void deleteDeveloper(Developer ListDev[], int *DevCount, char ID[]);

 /// UPDATE INFORMATION
void updateSalary(Developer ListDev[],int DevCount, char devID[]);

void updateLanguage(Developer ListDev[],int DevCount,char devID[]);

void updateBirthdate(Developer ListDev[],int DevCount,char devID[]);


    /// TOTAL EXPERIENCE
void totalExperience(Developer ListDev[],int DevCount,char devID[],Project LisPro[], char proID[]);

//================HAM FIND TAM THOI ==================

#endif