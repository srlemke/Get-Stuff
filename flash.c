#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"

int install_flash64()
{
	wget();
	chdir("/usr/lib64/mozilla/plugins");
	system ("wget http://fpdownload.macromedia.com/get/flashplayer/pdc/11.1.102.55/install_flash_player_11_linux.x86_64.tar.gz");
	system ("tar -xvf install_flash_player_11_linux.x86_64.tar.gz");
	recursive_delete("/usr/lib64/mozilla/plugins/usr/"); //directory added when unpacked flash package
	unlink ("install_flash_player_11_linux.x86_64.tar.gz");
	return 0;
}

int install_flash32()
{
	wget();
	chdir("/usr/lib/mozilla/plugins");
	system ("wget http://fpdownload.macromedia.com/get/flashplayer/pdc/11.1.102.55/install_flash_player_11_linux.i386.tar.gz");
	system ("tar -xvf install_flash_player_11_linux.i386.tar.gz");
	recursive_delete("/usr/lib/mozilla/plugins/usr/"); //directory added when unpacked flash package
	unlink ("install_flash_player_11_linux.i386.tar.gz");
	return 0;
}

int uninstall_flash()
{
	if(arch()){
		recursive_delete("/usr/lib64/mozilla/plugins/usr/");
		unlink ("/usr/lib64/mozilla/plugins/libflashplayer.so");
	}else{
		recursive_delete("/usr/lib/mozilla/plugins/usr/");
		unlink ("/usr/lib/mozilla/plugins/libflashplayer.so");
	}
	return 0;
}

int install_flash()
{
	//arch()returns true if 64bits//

	if(arch()){
		FILE *flash64 = fopen("/usr/lib64/mozilla/plugins/libflashplayer.so","r");
		if (!flash64){
			install_flash64();
		}else{
			return -1; //This i will use later to add an grayed out button in GTK interface//
		}
	}else{
		FILE *flash32 = fopen("/usr/lib/mozilla/plugins/libflashplayer.so","r");
		if (!flash32){
			install_flash32();
		}else{
			return -1;
		}
	}
	return 0;
}

int flash()
{
	if(arch()){
	        FILE *flash = fopen("/usr/lib64/mozilla/plugins/libflashplayer.so", "r");
		        return (flash != 0);
	}else{
		FILE *flash = fopen("/usr/lib/mozilla/plugins/libflashplayer.so", "r");
			return (flash != 0);
	}
}
