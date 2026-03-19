#include "Operations.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//===================SaveDevToFile======================//

void saveDevToFile(){

    FILE* fp = fopen("developers.txt","w");

    if (fp == NULL){
        printf("Can not create file\n");
        return;
    }

    for (int i = 0; i < DevCount; i++){
        fprintf(fp,"%s|%s|%s|%s|%lf\n", 
        ListDev[i].ID,
        ListDev[i].Name,
        ListDev[i].BirthDate,
        ListDev[i].Language,
        ListDev[i].Salary);
    }

    fclose(fp);

    printf("Saved developers successfully!\n");
}


//=================LoadingDevToFile=================

void loadDevelopersFromFile(){

    FILE* fp = fopen("developers.txt","r");

    if (fp == NULL){
        printf("No data file found\n");
        return;
    }

    DevCount = 0;

    while(DevCount < MAX_DEV &&
          fscanf(fp,"%[^|]|%[^|]|%[^|]|%[^|]|%lf\n",
          ListDev[DevCount].ID,
          ListDev[DevCount].Name,
          ListDev[DevCount].BirthDate,
          ListDev[DevCount].Language,
          &ListDev[DevCount].Salary) == 5)
    {
        DevCount++;
    }

    fclose(fp);
}


//================SaveProjectToFile==================//

//================SaveProjectsToFile==================//
// Save Projects
void saveProjectsToFile() {
    FILE* fp = fopen("projects.txt","w");
    if(fp == NULL){
        printf("Can not create file\n");
        return;
    }

    for(int i = 0; i < ProCount; i++){
        fprintf(fp,"%s|%s|%d|%s|%d",
            ListPro[i].IDPro,
            ListPro[i].NamePro,
            ListPro[i].Duration,
            ListPro[i].StartDate,
            ListPro[i].MemberCount);

        for(int j = 0; j < ListPro[i].MemberCount; j++){
            fprintf(fp,"|%s", ListPro[i].Members[j]);
        }
        fprintf(fp,"\n");
    }

    fclose(fp);
    printf("Save project successfully!\n");
}

// Load Projects
void loadProjectsFromFile() {
    FILE* fp = fopen("projects.txt","r");
    if (fp == NULL){
        printf("Can not find file\n");
        return;
    }

    ProCount = 0;
    char line[1024];

    while(ProCount < MAX_PRO && fgets(line, sizeof(line), fp)){
        Project temp;
        char* token = strtok(line, "|");
        if(!token) continue;
        strcpy(temp.IDPro, token);

        token = strtok(NULL, "|");
        if(!token) continue;
        strcpy(temp.NamePro, token);

        token = strtok(NULL, "|");
        if(!token) continue;
        temp.Duration = atoi(token);

        token = strtok(NULL, "|");
        if(!token) continue;
        strcpy(temp.StartDate, token);

        token = strtok(NULL, "|");
        if(!token) continue;
        temp.MemberCount = atoi(token);

        for(int j = 0; j < temp.MemberCount; j++){
            token = strtok(NULL, "|");
            if(!token) break;
            strcpy(temp.Members[j], token);
        }

        ListPro[ProCount++] = temp;
    }

    fclose(fp);
}
//void saveProjectsToFile(){
//
//    FILE* fp = fopen("projects.txt","w");
//
//    if(fp == NULL){
//        printf("Can not create file\n");
//        return;
//    }
//
//    for(int i = 0; i < ProCount; i++){
//        fprintf(fp,"%s|%s|%d|%s\n",
//        ListPro[i].IDPro,
//        ListPro[i].NamePro,
//        ListPro[ProCount].Duration,
//        ListPro[i].StartDate);
//    }
//
//    fclose(fp);
//
//    printf("Save project successfully!\n");
//}
//
//
////================LoadingProjectToFile===============//
//
//void  loadProjectsFromFile(){
//
//    FILE* fp = fopen("projects.txt","r");
//
//    if (fp == NULL){
//        printf("Can not find file\n");
//        return;
//    }
//
//    ProCount = 0;
//
//    while (ProCount < MAX_PRO &&
//           fscanf(fp,"%s|%s|%d|%s",
//           ListPro[ProCount].IDPro,
//           ListPro[ProCount].NamePro,
//           &ListPro[ProCount].Duration,
//           ListPro[ProCount].StartDate) == 4)
//    {
//        ProCount++;
//    }
//
//    fclose(fp);
//}