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

	if(libfaad()){
		printf("3 - Uninstall faad audio codec(disables DI aac playbacks on clementine)\n");
	}else{
		printf("3 - Install faad audio codec(enables DI aac playbacks on clementine)\n");
	}

	printf("Any other key to exit.\n");
}

int operations()
{
	int choose = 0;
	menu();

	scanf("%d", &choose);

	if(choose != 1 && choose != 2 && choose != 3){
		printf ("Bye bye.\n");
		return 0;
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

	if(choose == 3){
		if(libfaad()){
			uninstall_libfaad();
		}else{
			install_libfaad();
		}
	}
	printf ("Done!\n");

	operations();
	
	return 0;
}

int main()
{
	if(geteuid() != 0){
		printf ("Run as root\n");
	}else{
		operations();
	}
	return 0;
}
