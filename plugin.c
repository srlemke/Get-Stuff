#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"

int libfaad()
{
	if(arch()){
		FILE *libfaad = fopen("/usr/lib64/libfaad.so.2.0.0", "r");
		return (libfaad != 0);
	}else{
		FILE *libfaad = fopen("/usr/lib/libfaad.so.2.0.0", "r");
		return (libfaad != 0);
	}
}

void medias()
{
	system ("urpmi.removemedia codecs");

	if(arch()){
		system ("urpmi.addmedia codecs http://mirror.yandex.ru/mandriva/plf/cooker/free/binary/x86_64/");
	}else{
		system ("urpmi.addmedia codecs http://mirror.yandex.ru/mandriva/plf/cooker/free/binary/i586/");
	}
}

int install_libfaad()
{
	medias();
	if(arch()){
		system ("urpmi gstreamer0.10-faad lib64faad2_2-2.7");
	}else{

		system ("urpmi gstreamer0.10-faad libfaad2_2-2.7");
	}
	return 0;
}

int uninstall_libfaad()
{
	if(arch()){
		system ("urpmi.removemedia codecs; urpme gstreamer0.10-faad lib64faad2_2");
	}else{
		system ("urpmi.removemedia codecs; urpme gstreamer0.10-faad libfaad2_2");
	}
	return 0;
}

