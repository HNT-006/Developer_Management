//================KHAI BAO THU VIEN ===================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//=================KHAI BAO HEADER FILES ==================
#include "Common.h"
#include "Operations.h"
#include "Developer.h"
#include "Project.h"
#include "ConsoleIO.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//==============KHAI BAO BIEN =====================
Developer ListDev[MAX_DEV];
Project ListPro[MAX_PRO];
int DevCount = 0;
int ProCount = 0;

//==============MAIN====================
int main(int argc, char *argv[]) {
	bool maintain = true;
	int choice;
       do{
       	clearSystem();
		MAIN_MENU();
	    choice = printfChoice(choice);
	    
	    switch(choice){
	    	case 1:{
	    		int choice1;
	    		bool maintain1 = true;
	    	    do{
	    	    	clearSystem();
	    	    	SubMENU_DEV();
	    	    	choice1 = printfChoice();
	    	    	
	    	    	switch(choice1){
	    	    		case 1: {  // Add new  Developer 
 	    	    			
 	    	    			bool tieptuc = true;
							do{
								clearSystem();
								printf("\t================ADD NEW DEVELOPER================\n");
								addDeveloper(ListDev, &DevCount);
 	    	    			    printf("\t================Add new Developer Successfully================\n\n");
 	    	    			// Gan tieptuc cho ContinueOrNot
								tieptuc = ContinueOrNot();
							} while (tieptuc);
							break;
						}
						
						case 2: { // Update Developer --> Xuat ra menu cua Update Dev Options
						    bool tieptuc = true;
						    int update_choice;
							do{
								clearSystem();
								SubMENU_UPDATE();
								update_choice = printfChoice(update_choice);
								
								switch(update_choice){
									case 1: {
										printf("\t================UPDATE NAME FOR DEVELOPER================\n");
										
										printf("Update Name Developer Successfully\n");
										pauseSystem();
										break;
									}

									case 2: {
										printf("Update Programming Lanaguage Developer Successfully\n");
										pauseSystem();
										break;
									}
									
									case 3: {
										printf("Update the Birth day for Developer Successfully\n");
										pauseSystem();
										break;
									}
									
									case 4: {
										printf("Update Salary for Developer Successfully\n");
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
							}while(tieptuc);
							break;
						}
						
						case 3: {   //Delete Developer  --> Co Ham se nhap sau
							printf("Delete A Dev\n");
							printf("Delete Successfully\n");
							pauseSystem();
							break;
						}
						
//	printf("\t=============DISPLAY SERVICES=============\n");
//	printf("1. Display Developer\n");
//	printf("2. Display all Developer in List Developer\n");
//	printf("3. Exit\n");
						case 4: { //Display -> mot he thong khac nua
						    bool tieptuc = true;
							do{
								clearSystem();
								SubMENU_DISPLAY();
								int choice = printfChoice(choice);
								clearBuffer();
								switch(choice){
									case 1:{
										char ID[7];
										printfID(ID);
										//NHAP XONG ID
										printf("%-10s %-20s %-15s %-25s %-10s\n",
                                                        "ID", 
														"NAME DEVELOPER", 
														"BIRTH DATE",
														"PROGRAMMING LANGUAGE", 
														"SALARY");
										displayDeveloper(ListDev, DevCount, ID);
										break;
									}
									
									case 2:{
										printf("%-10s %-20s %-15s %-25s %-10s\n",
                                                        "ID", 
														"NAME DEVELOPER", 
														"BIRTH DATE",
														"PROGRAMMING LANGUAGE", 
														"SALARY");
										displayAllDev(ListDev, DevCount);
										break;
									}
								}
 	    	    			// Gan tieptuc cho ContinueOrNot
								tieptuc = ContinueOrNot();
							} while (tieptuc);
						    
							break;
						}
						
						case 5: { // Find Developer 
							pauseSystem();
							break;
						}
						
						case 6: { // Thoat Khoi subMenu_DEV
						    printf("Goodbye ^v^\n");
							maintain1 = false;
							pauseSystem();
							break;
						}
						
						default: {
							printf("Your choice is invalide \"_- !!\n");
							printf("You should enter again -3- \n");
							pauseSystem();
							continue;
							break;
						}
					}
				}while (maintain1);
				break;
			}
			
			case 2:{
//	printf("\t=============PROJECT SERVICES=============\n");
//	printf("1. Add new Project\n");
//	printf("2. Assign Project to Developer\n");
//	printf("3. Display (Project or List Project)\n");
//	printf("4. Exit\n");
                int choice2;
				bool maintain2 = true;
				do{
					clearSystem();
					SubMENU_PROJECT();
					choice2 = printfChoice();
					
					switch(choice2){
						case 1:{
							bool tieptuc = true;
							do{
								clearSystem();
 	    	    			    printf("Add new Project\n");
 	    	    			// Gan tieptuc cho ContinueOrNot
								tieptuc = ContinueOrNot();
							} while (tieptuc);
							break;
						}
						
						case 2:{
							printf("Assign Project\n");
							pauseSystem();
							break;
						}
						
						case 3:{ 

						    printf("Display\n");
							pauseSystem();
							break;
						}
						
						case 4:{
							printf("Bye User ^v^\n");
							pauseSystem();
							break;
						}
						
						default: {
							printf("Your choice is invalide \"_- !!\n");
							printf("You should enter again -3- \n");
							pauseSystem();
							continue;
							break;
						}
					}
				}while (maintain2);
				
				break;
			}
			
			case 3:{
				printf("See you later ^v^\n");
				pauseSystem();
				maintain = false;
				break;
			}
			
			default: {
				printf("Your choice is invalide \"_- !!\n");
				printf("You should enter again -3- \n");
				pauseSystem();
				continue;
				break;
			}
		}
	}while (maintain);

	return 0;
}