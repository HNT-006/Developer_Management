#ifndef OPERATION_H
#define OPERATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void AddDev();
void DeleteDev(int id, int listDev[], int *NumDev);
int FindID(int id, int listDev[], int NumDev);
void Display(int listDev[], int NumDev);