#include <stdio.h>

int install_flash64()
{
	chdir("/usr/lib64/mozilla/plugins");
	system ("wget http://fpdownload.macromedia.com/get/flashplayer/pdc/11.1.102.55/install_flash_player_11_linux.x86_64.tar.gz");
	sytem ("tar -xvf install_flash_player_11_linux.x86_64.tar.gz");
	recursive_delete("/usr/lib64/mozilla/plugins/usr/");
	return 0;
}

int install_flash32()
{
	chdir("/usr/lib/mozilla/plugins");
	system ("wget http://fpdownload.macromedia.com/get/flashplayer/pdc/11.1.102.55/install_flash_player_11_linux.i386.tar.gz");
	sytem ("tar -xvf install_flash_player_11_linux.i386.tar.gz");
	recursive_delete("/usr/lib/mozilla/plugins/usr/");
	return 0;
}

int main()
{
	wget();
	if(arch()){
		install_flash64();
	}else{
		install_flash32();
	}

	return 0;			      i
}
