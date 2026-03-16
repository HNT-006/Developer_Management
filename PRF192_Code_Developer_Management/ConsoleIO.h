#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include "Common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
//===========SYSTEM FUNCTIONS ============
void clearSystem();
void pauseSystem();
void clearBuffer();

//===========CAC HAM CHECK YES/NO ===========
bool ContinueOrNot();
void toLowerCase(char *str);

//===============CAC HAM NHAP XUAT CO BAN====================
int readInt();
int printfChoice(); 

char* readString(char str[]);
void  printfID(char str[]);

//=======================IN KHUNG CHO DISPLAY==========================
void bolder();
void title_Developer();
void title_Project();



void MAIN_MENU();
void SubMENU_DEV();
void SubMENU_PROJECT();
void SubMENU_UPDATE();
void SubMENU_DISPLAY();


void showDeveloperID(Developer ListDev[], int DevCount);

//===================CAC CASE TRONG CAC MUC CHINH TRONG MAIN MENU================
void DEFAULT_CASE();
//===================CAC CASE TRONG DEVELOPER SERVICE=================
void ADD_NEW_DEVELOPER();
void UPDATE_DEVELOPER();
void DELETE_DEVELOPER();
void DISPLAY_DEVELOPER();
void FIND_DEVELOPER();

//===================CAC CASE TRONG PROJECT SERVICE=================
void ADD_NEW_PROJECT();
void ASSIGN_PPOJECT_TO_DEV();
void DISPLAY_PROJECT();
#endif 