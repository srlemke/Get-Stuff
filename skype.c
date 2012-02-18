#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include "common.h"

#define VERSION "2.2.0.35"

//return already installed or not
int skype()
{
	FILE *skype = fopen("/usr/bin/skype", "r");
	return (skype != 0);
}

int uninstall_skype()
{
	unlink ("/opt/skype_static-"VERSION".tar.bz2");

	if (chdir("/opt/skype_static-"VERSION) == 0){
		recursive_delete("/opt/skype_static-"VERSION);
		unlink ("/usr/bin/skype");
		unlink ("/usr/share/applications/skype.desktop");
		unlink ("/usr/share/icons/skype.png");
	}
	info_message("Skype sucesfully uninstalled!\n");
	return 0;
}

int install_skype()
{
	//int tmp;
	if(skype()){
		return 0;
	}else{
			info_message("First i will uninstall old versions of skype that\n maybe already installed.");
			uninstall_skype();
		if (arch()){// if arch is 64bit
			info_message("You are on a 64bit system, on the next screen i need\nyou to enable the Main32 and Main32 Updates medias, i'm a smart software and i could do it myself, but i like you to know everything whats being done here.");

			system ("edit-urpm-sources.pl --expert"); //tel user to enable 32bit medias
			system ("urpmi libxscrnsaver1 libxv1 libxrender1 libxrandr2 libfreetype6 libfontconfig1 libglib2.0_0");
		}

		
		unlink ("/opt/skype_static-"VERSION".tar.bz2");

		wget();
		chdir ("/opt");
		system ("wget http://download.skype.com/linux/skype_static-"VERSION".tar.bz2");
			info_message("The installation is in progress... Downloading the skype tar.bz2 file...\n");
		system ("tar -jxvf /opt/skype_static-"VERSION".tar.bz2");

		symlink ("/opt/skype_static-"VERSION"/skype", "/usr/bin/skype");
		symlink ("/opt/skype_static-"VERSION"/skype.desktop", "/usr/share/applications/skype.desktop");
		symlink ("/opt/skype_static-"VERSION"/icons/SkypeBlue_48x48.png", "/usr/share/icons/skype.png");
			info_message("Done, skype installed\n");
		return 0;
	}
}
