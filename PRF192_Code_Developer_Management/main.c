//================KHAI BAO THU VIEN ===================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

//=================KHAI BAO HEADER FILES ==================
#include "Common.h"
#include "Operations.h"
#include "Developer.h"
#include "Project.h"
#include "ConsoleIO.h"
#include "FileHelper.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//==============KHAI BAO BIEN =====================
Developer ListDev[MAX_DEV];
Project ListPro[MAX_PRO];
int DevCount = 0;
int ProCount = 0;

//====================CONTINUE OR NOT: TIEP TUC HAY DUNG LAI===============================
//tieptuc = ContinueOrNot();

//==============MAIN====================
int main(int argc, char *argv[]) {
	loadDevelopersFromFile();
	loadProjectsFromFile();
	bool maintain = true;
	int choice;
	do {
		clearSystem();
		MAIN_MENU();
		choice = printfChoice(choice);

		switch(choice) {
			case 1: {
				int choice1;
				bool maintain1 = true;
				do {
					clearSystem();
					SubMENU_DEV();
					choice1 = printfChoice();

					switch(choice1) {
						case 1: {  // Add new  Developer  ==>CHỐT

							ADD_NEW_DEVELOPER();
							saveDevToFile();
							break;
						}

						case 2: { // Update Developer --> Xuat ra menu cua Update Dev Options
					        clearSystem();
							char devID[10];

							showDeveloperID(ListDev, DevCount);
							printfID(devID);
							clearBuffer();

							int update_choice;
							bool tieptuc = true;
							do {
								clearSystem();
								SubMENU_UPDATE();
								update_choice = printfChoice(update_choice);

								switch(update_choice) {
									case 1: {
										clearSystem();
										printf("\t================UPDATE NAME FOR DEVELOPER================\n");

										printf("UPDATE NAME IS NOT IMPLEMENTED YET\n");
										pauseSystem();
										break;
									}

									case 2: {
										clearSystem();
										printf("\t================UPDATE LANGUAGE FOR DEVELOPER================\n");
										updateLanguage(ListDev, DevCount, devID);

										pauseSystem();
										break;
									}

									case 3: {
										clearSystem();
										printf("\t================UPDATE BIRTH DATE FOR DEVELOPER================\n");
										updateLanguage(ListDev, DevCount, devID);

										pauseSystem();
										break;
									}

									case 4: {
										clearSystem();
										printf("\t================UPDATE SALARY FOR DEVELOPER================\n");
										updateSalary(ListDev, DevCount, devID);

										pauseSystem();
										break;
									}

									case 5: {
										printf("Now go out of Dev Menu\n");
										pauseSystem();
										tieptuc = false;
										break;
									}
								}
							} while(tieptuc);
							break;
						}

						case 3: {   // Delete Developer ==>CHOT
							DELETE_DEVELOPER();
							break;
						}

						case 4: { // DISPLAY DEVELOPERS ==>CHỐT
							DISPLAY_DEVELOPER();
							break;
						}
						case 5: { //=====================FIND DEVELOPER =========================
							//==> CHOT
							FIND_DEVELOPER();
							break;
						}

						case 6: { // Thoat Khoi subMenu_DEV
							clearSystem();
							printf("\nGOODBYE ^v^\n");
							maintain1 = false;
							pauseSystem();
							break;
						}

						default: {
							DEFAULT_CASE();
							break;
						}
					}
				} while (maintain1);
				break;
			}

			case 2: {
				int choice2;
				bool maintain2 = true;
				do {
					clearSystem();
					SubMENU_PROJECT();
					choice2 = printfChoice();

					switch(choice2) {
						case 1: { //========CHỐT
							ADD_NEW_PROJECT();
							saveProjectsToFile();
							break;
						}

						case 2: { //==>CHOT
							ASSIGN_PPOJECT_TO_DEV();
							saveProjectsToFile();
							break;
						}

						case 3: {
							DISPLAY_PROJECT();
							break;
						}

						case 4: {
							clearSystem();
							printf("\nBUY USER ^v^\n");
							pauseSystem();
							maintain2 = false;
							break;
						}

						default: {
							DEFAULT_CASE();
							break;
						}
					}
				} while (maintain2);

				break;
			}

			case 3: {
				clearSystem();
				printf("Saving data...\n");

				saveDevToFile();
				saveProjectsToFile();

				printf("SEE YOU LATER ^v^\n");
				pauseSystem();

				maintain = false;
				break;
				break;
			}

			default: {
				DEFAULT_CASE();
				continue;
			}
		}
	} while (maintain);

	return 0;
}