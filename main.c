#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

void menu()
{
	printf ("Insert a number to: \n");
	if(skype()){
		printf("1 - Uninstall Skype\n");
	}else{
		printf("1 - Install Skype\n");
	}
	
	if(flash()){
		printf("2 - Uninstall Flash\n");
	}else{
		printf("2 - Install Flash\n");
	}
}

int main()
{
	int choose = 0;
	menu();

	scanf("%d", &choose);
	if(choose != 1 || choose != 2){
		printf ("Invalid number\n");
		menu();
	}

	if(choose == 1){
		if(skype()){
			uninstall_skype();
		}else{
			install_skype();
		}
	}
	
	if(choose == 2){
		if(flash()){
			uninstall_flash();
		}else{
			install_flash();
		}
	}
	return 1;
}

