#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

#define VERSION "2.2.0.35"

int uninstall_skype()
{
	chdir ("/opt");
	unlink ("skype_static-"VERSION);

	if (chdir("/opt/skype_static-"VERSION) == 0){

		recursive_delete("/opt/skype_static-"VERSION);

		unlink ("/usr/bin/skype");
		unlink ("/usr/share/applications/skype.desktop");
		unlink ("/usr/share/icons/skype.png");
	}
	return 0;
}

int install_skype()
{
	uninstall_skype();

	if ((arch() == 1)){// if arch is 64bit
		system ("edit-urpm-sources.pl --expert"); //tel user to enable 32bit medias
		system ("urpmi libxscrnsaver1 libxv1 libxrender1 libXrandr2 libfreetype6 libfontconfig1 libglib2.0_0");
	}

	chdir ("/opt");
	unlink ("skype_static-"VERSION".tar.bz2");
	
	wget();
	system ("wget http://download.skype.com/linux/skype_static-"VERSION".tar.bz2");
	system ("tar -jxvf /opt/skype_static-"VERSION".tar.bz2");

	symlink ("/opt/skype_static-"VERSION"/skype", "/usr/bin/skype");
	symlink ("/opt/skype_static-"VERSION"/skype.desktop", "/usr/share/applications/skype.desktop");
	symlink ("/opt/skype_static-"VERSION"/icons/SkypeBlue_48x48.png", "/usr/share/icons/skype.png");

	return 0;
}
