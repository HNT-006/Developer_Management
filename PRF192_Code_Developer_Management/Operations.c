#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "Operations.h"
#include "Common.h"

void swap(dev *a, dev *b)
{
	dev tmp=*a;
	*a=*b;
	*b=tmp;
}

int partition(dev list[], int l, int r)
{
	char pivot[20];
	strcpy(pivot,list[r].ID);
	int i=l-1;
	for (int j=l;j<r;j++)
	{
		if (strcmp(list[j].ID,pivot)<0)
		{
			i++;
			swap(&list[i],&list[j]);
			/*  co the lam cach truc tiep, khong can thong qua ham swap va pointer
			dev tmp=list[i];
			list[i]=list[j];
			list[j]=tmp;	
			*/		
		}
	}
	i+=1;
	swap(&list[i],&list[r]);
	/* co the lam truc tiep , khong can thong qua ham swap va pointer
	dev tmp=list[i];
	list[i]=list[j];
	list[j]=tmp;
	*/	  
	return i;
}

void quicksort(dev list[],int l, int r)
{
    if (l>=r) return;
	
    int p=partition(list,l,r);
    
    quicksort(list,l,p-1);
    quicksort(list,p+1,r);
}



