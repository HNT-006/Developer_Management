
#include "Operations.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*========================= findDevByName function =========================*/
// Trả về: index nếu tìm thấy | -1 nếu không tìm thấy | -2 nếu Name không hợp lệ
int findDevByName(char Name[], Developer ListDev[], int DevCount)
{
    // Kiểm tra format tên
    if (!validateName(Name))
    {
        return -2; // Name không hợp lệ
    }

    for (int i = 0; i < DevCount; i++)
    {
        if (strcmp(ListDev[i].Name, Name) == 0)
        {
            return i; // Tìm thấy, trả về vị trí
        }
    }

    return -1; // Không tìm thấy
}


/*========================= findDevByID function =========================*/
// Trả về: index nếu tìm thấy | -1 nếu không tìm thấy | -2 nếu ID không hợp lệ
int findDevbyID(Developer ListDev[], int DevCount, char ID[]){
	if (!validateID(ID)){
		return -1;
	} 
	
	for (int i = 0; i < DevCount; i++){
		if (strcmp(ID, ListDev[i].ID) == 0) return i;
	}
	
	return -1;
}
/*========================= validateID function =========================*/


int validateID(char ID[]) {
    if (strlen(ID) != 6)
        return 0;

    // Check first 3 characters
    if (ID[0] != 'D' || ID[1] != 'E' || ID[2] != 'V')
        return 0;

    // Check last 3 characters are digits
    if (!isdigit(ID[3]) || 
        !isdigit(ID[4]) || 
        !isdigit(ID[5]))
        return 0;

    return 1;
}

bool validateName(char name[]) {
    int length = strlen(name);
    int spaceCount = 0;

    if (length == 0) return false;

    for (int i = 0; i < length; i++) {
        if (name[i] == ' ') {
            spaceCount++;
        }
    }

    if (spaceCount >= 1) {
        return true;
    }

    return false;
}