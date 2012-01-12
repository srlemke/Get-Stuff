#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include "common.h"


int recursive_delete(char* dirname) {
	DIR *dp;
	struct dirent *ep;

	char abs_filename[FILENAME_MAX];

	dp = opendir (dirname);
	if (dp != NULL)
	{
		while ((ep = readdir(dp)) != 0) {
			struct stat stFileInfo;

			snprintf(abs_filename, FILENAME_MAX, "%s/%s", dirname, ep->d_name);

			if (lstat(abs_filename, &stFileInfo) < 0)
				perror ( abs_filename );

			if(S_ISDIR(stFileInfo.st_mode)) {
				if(strcmp(ep->d_name, ".") && 
						strcmp(ep->d_name, "..")) {
					printf("%s directory\n",abs_filename);
					recursive_delete(abs_filename);
				}
			} else {
				printf("%s file\n",abs_filename);
				remove(abs_filename);
			}
		}
		(void) closedir (dp);
	}
	else
		perror ("Couldn't open the directory");

	remove(dirname);
	return 0;

}

void arch()
{
	struct utsname un;
	uname(&un);

	if (!strcmp(un.machine, "x86_64")){
		printf ("You are on a 64bit system, so, additional dependencies are requested (only2)\n");
		printf ("Be sure you have the Main32 media enabled! If they are, press ok:\n");
		system ("edit-urpm-sources.pl –expert");
		system ("urpmi libxscrnsaver1 libxv1 libxrender1 libXrandr2 libfreetype6 libfontconfig1 libglib2.0_0");
	}
}

