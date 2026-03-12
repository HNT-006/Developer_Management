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
Developer developers[MAX_DEV];
Project projects[MAX_PRO];
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
 	    	    			    printf("Add new Developer\n");
 	    	    			// Gan tieptuc cho ContinueOrNot
								tieptuc = ContinueOrNot();
							} while (tieptuc);
							break;
						}
						
						case 2: { // Update Developer --> Xuat ra menu cua Update Dev Options
							
							break;
						}
						
						case 3: {   //Delete Developer  --> Co Ham se nhap sau
							printf("Delete A Dev\n");
							printf("Delete Successfully\n");
							pauseSystem();
							break;
						}
						
						case 4: { //Display -> mot he thong khac nua
							
							break;
						}
						
						case 5: { // Find Developer 
							pauseSystem();
							break;
						}
						
						case 6: { // Thoat Khoi subMenu_DEV
						    printf("Goodbye ^v^ \n");
							maintain1 = false;
							pauseSystem();
							break;
						}
						
						default: {
							printf("Your choice is invalide. Bro\n");
							printf("You should enter again\n");
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
					
				}while (maintain2);
				
				break;
			}
			
			case 3:{
				maintain = false;
				break;
			}
			
			default: {
				printf("Your choice is invalid\n");
				printf("Please enter again\n");
				pauseSystem();
				break;
			}
		}
	}while (maintain);

	return 0;
}