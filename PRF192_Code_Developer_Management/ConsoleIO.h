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


int readInt();
int printfChoice(); 


void MAIN_MENU();
void SubMENU_DEV();
void SubMENU_PROJECT();
void SubMENU_UPDATE();
#endif 