#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//================CAC HAM FIND ID PROJECT VÀ FIND NAME PROJECT=====================
int findProjectbyName(char proName[], Project ListPro[], int ProCount);
int findProjectbyID(char proID[], Project ListPro[], int ProCount);

int isDevInProject(Project ListPro[], char devID[], char proID[],int ProCount); //====> HÀM XÁC NHẬN DEV ĐÓ CÓ TRONG LIST MEMBERS CỦA PROJECT KO 
//===================CAC HAM PROJECT CO BAN ====================
void addnewProject(Project ListPro[], int *ProCount);
bool assignProjecttoDev(Project ListPro[], int ProCount,Developer ListDev[], int DevCount, char IdDev[]);
void displayProject(Project ListPro[], int ProCount, char proID[]);
void displayAllProject(Project ListPro[], int ProCount);
//==================CAC HAM ĐƯA RA LỰA CHỌN CƠ BẢN========================

int LuaChon_1or2();
int LuaChon_assignProjecttoDev(Project ListPro[], int ProCount);

#endif