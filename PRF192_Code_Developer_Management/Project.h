#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static int demPro = 0;
//===================CAC HAM PROJECT CO BAN ====================
void addnewProject();
void assignProjecttoDev();
int LuaChon_assignProjecttoDev();
//==================CAC HAM NHAP XUAT CO BAN ========================

int LuaChon_1or2();
int findNameProject(char str[], Project ListPro[]);
int findIDProject(char str[], Project ListPro[]);
#endif