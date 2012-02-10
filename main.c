#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include <gtk/gtk.h>

/*void menu()
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
	char choose = 0;
	menu();

	scanf("%c", &choose);

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
*/

int main(int argc, char **argv)
{
	GtkBuilder *builder;
	GtkWidget  *window;
	GError     *error = NULL;

	/* Init GTK+ */
	gtk_init( &argc, &argv );

	/* Create new GtkBuilder object */
	builder = gtk_builder_new();
	/* Load UI from file. If error occurs, report it and quit application.
	 *      * Replace "tut.glade" with your saved project. */
	if( ! gtk_builder_add_from_file( builder, "tut.glade", &error ) )
	{
		g_warning( "%s", error->message );
		g_free( error );
		return( 1 );
	}

	/* Get main window pointer from UI */
	window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );

	/* Connect signals */
	gtk_builder_connect_signals( builder, NULL );

	/* Destroy builder, since we don't need it anymore */
	g_object_unref( G_OBJECT( builder ) );

	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show( window );

	/* Start main loop */
	gtk_main();


/*	if(geteuid() != 0){
		printf ("Run as root\n");
	}else{
		operations();
		}
	}
*/	
	return 0;
}
