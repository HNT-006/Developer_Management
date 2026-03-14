#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Common.h"
#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int demDev = 0;

void addDeveloper(Developer ListDev[],int *DevCount);

void inputID(char ID[]);

int validateID(char ID[]);

    /// DISPLAY INFORMATION
void displaydev(Developer ListDev[],int DevCount,char ID[]);

void displayAllDev(Developer ListDev[],int Devcount);

 
    /// UPDATE INFORMATION
void deleteDev(Developer ListDev[], int *DevCount, char ID[]);

void updateSalary(Developer ListDev[],int DevCount, char ID[]);

void updateID(Developer ListDev[],int DevCount,char ID[]);

void updateLanguage(Developer ListDev[],int DevCount,char ID[]);

void updateBirthday(Developer ListDev[],int DevCount,char ID[]);


    /// TOTAL EXPERIENCE
void totalExperience(Developer ListDev[],int DevCount,char ID[]);



#endif