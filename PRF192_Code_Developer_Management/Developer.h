#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void addDeveloper(Developer ListDev[],int *DevCount);

void inputID(char id[]);

int validateID(char id[]);

void displaydev();



#endif