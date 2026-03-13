#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Developer.h"
#include "Common.h"
#include "Operations.h"
#include "Project.h"

// Ham kiem tra Dev đã có trong project chưa
int isDevInProject(Project ListPro[], int proIndex, char devID[])  
{
    for(int i = 0; i < ListPro[proIndex].MemberCount; i++)
    {
        if(strcmp(ListPro[proIndex].Members[i], devID) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void assignDevToProject()
{
    char devID[7];
    char proID[7];

    printf("Enter Developer ID: ");
    scanf("%6s", devID);

    int devIndex = findDevByID(devID, ListDev, DevCount);

    if(devIndex < 0)
    {
        printf("Developer not found!\n");
        return;
    }

    printf("Enter Project ID: ");
    scanf("%6s", proID);

    int proIndex = findProjectByID(proID, ListPro, ProCount);

    if(proIndex < 0)
    {
        printf("Project not found!\n");
        return;
    }

    if(isDevInProject(ListPro, proIndex, devID))
    {
        printf("Developer already in this project!\n");
        return;
    }

    strcpy(ListPro[proIndex].Members[ListPro[proIndex].MemberCount], devID);

    ListPro[proIndex].MemberCount++;

    printf("Assign successfully!\n");
}