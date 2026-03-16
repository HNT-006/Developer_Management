#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static int demPro = 0;
//================CAC HAM FIND ID PROJECT VÀ FIND NAME PROJECT=====================
int findProjectbyName(char proName[], Project ListPro[]);
int findProjectbyID(char proID[], Project ListPro[]);

int isDevInProject(Project ListPro[], char devID[], char proID[],int ProCount); //====> HÀM XÁC NHẬN DEV ĐÓ CÓ TRONG LIST MEMBERS CỦA PROJECT KO 
//===================CAC HAM PROJECT CO BAN ====================
void addnewProject(Project ListPro[], int *ProCount);
void assignProjecttoDev();

//==================CAC HAM ĐƯA RA LỰA CHỌN CƠ BẢN========================

int LuaChon_1or2();
int LuaChon_assignProjecttoDev();
#endif