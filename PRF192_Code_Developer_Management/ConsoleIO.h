#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include "Common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

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
void titile();


void MAIN_MENU();
void SubMENU_DEV();
void SubMENU_PROJECT();
void SubMENU_UPDATE();
void SubMENU_DISPLAY();
void showDeveloperID(Developer ListDev[], int DevCount);
#endif 