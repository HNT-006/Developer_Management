//===================SaveDevToFile======================//
#include<stdio.h>
#include"common.h"
void SaveDevtofile(){

FILE*fp = fopen("developers.txt","w");
if (fp=NULL){
	printf ("can not created file\n");
	return ;
}
for (int i ; i<DevCount;i++){
	fprintf (fp,"%s %s %s %s %.2lf\n",ListDev[i].ID,ListDev[i].Name,ListDev[i].BirthDate,ListDev[i].Language,ListDev[i].Salary);
	
}
fclose(fp); 
 printf("Saved developers successfully!\n");
}


// =============== LoadingDevToFile=================//

#include<stdio.h>
#include"common.h"
void LoadingDevToFlie(){
	FILE*fp=fopen("developers.txt","w");
	if (fp=NULL){
		printf ("no date file found \n");
		return;
	}
	DevCount = 0;
	while(DevCount<MAX_DEV&&fscanf(fp,"%s %s %s %s %.2lf",ListDev[DevCount].ID,ListDev[DevCount].Name,ListDev[DevCount].BirthDate,ListDev[DevCount].Language,&ListDev[DevCount].Salary)!=EOF);


{

	DevCount++;
	
}
}

//================SaveProJectToFile==================//

#include <stdio.h>
#include "common.h"
void SaveProToFile(){
	FILE* fp =fopen("projects.txt","w");
	if(fp=NULL){
		printf ("can not created file /n");
		return;
	}
	for(int i;i<ProCount;i++){
		fprintf (fp,"%s %s %s %s %.2lf",ListPro[i].IDPro, ListPro[i].NamePro, ListPro[i].Duration, ListPro[i].StartDate );
	}
	fclose(fp);
	printf ("Save project successfully!\n");
}
//==================LoadingProJectToFlie===============//
#include<stdio.h>
#include"common.h"
void LoadingProToFile(){
	FILE*fp=fopen("project.txt","w");
	if (fp=NULL){
		printf ("can not file found /n");
		return;
	}
	while (ProCount<MAX_PRO&&fscanf(fp,"%s %s %s %s %.2lf",ListPro[ProCount].IDPro, ListPro[ProCount].NamePro, ListPro[ProCount].Duration, &ListDev[ProCount].BirthDate)!=EOF)
	{
		ProCount++;
	}
}






























