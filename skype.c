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

int uninstall_skype(int i)
{
	if(!skype()){
		if(i == 0){
			return 0;
		}else{
			if(!skype()){
				info_message("Nothing to uninstall.");
			}else{
				info_message("Deinstallation Complete.");
			}
		}
		return 0;
	}else{
		system("urpme skype"); //Just in case//

		unlink ("/opt/skype_static-"VERSION".tar.bz2");
		if (chdir("/opt/skype_static-"VERSION) == 0){
			recursive_delete("/opt/skype_static-"VERSION);
			unlink ("/usr/bin/skype");
			unlink ("/usr/share/applications/skype.desktop");
			unlink ("/usr/share/icons/skype.png");
		}
		info_message("Deinstallation complete!\n");
		return 0;
	}
}

int spawn(char *cmd){

	char *myargv[5];
	GError *error = NULL;
	GPid pid;	

	myargv[0] = "/bin/sh";
	myargv[1] = "-c";
	myargv[2] = cmd;
	myargv[3] = NULL;

	g_spawn_async(NULL, myargv, NULL, G_SPAWN_DO_NOT_REAP_CHILD,
			NULL, NULL, &pid, &error);
	return 0;
}

int install_skype(){

	if(skype()){
		info_message("Skype is already installed.");
		return 0;
	}else{
		uninstall_skype(0);
		if (arch()){

			info_message("You are on a 64bit system, on the next screen i need\nyou to enable the Main32 and Main32 Update medias.");
			spawn("edit-urpm-sources.pl --expert");
			info_message("Time to install some extra dependencies, only needed on 64bit systems");
			spawn("urpmi libxscrnsaver1 libxv1 libxrender1 libxrandr2 libfreetype6 libfontconfig1 libglib2.0_0  libgthread2.0_0 libsm6 libxi6");
		}
		info_message("Press ok to start skype download, this may take a while and depends on your bandwitch speed. Go grab some coffee. Press ok and wait this window close.");

		unlink ("/opt/skype_static-"VERSION".tar.bz2");

		wget();
		chdir ("/opt");

		system ("wget http://download.skype.com/linux/skype_static-"VERSION".tar.bz2");
		system ("tar -jxvf /opt/skype_static-"VERSION".tar.bz2");

		symlink ("/opt/skype_static-"VERSION"/skype", "/usr/bin/skype");
		symlink ("/opt/skype_static-"VERSION"/skype.desktop", "/usr/share/applications/skype.desktop");
		symlink ("/opt/skype_static-"VERSION"/icons/SkypeBlue_48x48.png", "/usr/share/icons/skype.png");
		info_message("Installation Done! :]\n");
		return 0;
	}
}
