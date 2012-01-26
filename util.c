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
	remove(dirname);
	return 0;

}

int arch()
{
	struct utsname un;
	uname(&un);
	return (!strcmp(un.machine, "x86_64"));
}

//Check for wget//
void wget()
{
	FILE *wget = fopen("/usr/bin/wget","r");
	if (!wget){
		system("urpmi wget");
	}
}
