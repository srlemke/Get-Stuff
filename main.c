#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include "common.h"


//Taskbar icon//
GdkPixbuf *create_pixbuf(const gchar * filename)
{
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if(!pixbuf) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}

	return pixbuf;
}

int main( int argc, char **argv)
{
//	int choose = 0;

	gtk_init(&argc, &argv);
	
	GtkWidget *janela, *label;
	GtkWidget *choice_box;
	GtkWidget *extras0, *install_skype_button, *uninstall_skype_button;
	GtkWidget *extras1, *install_flash_button, *uninstall_flash_button;
	GtkWidget *extras2, *install_codecs_button, *uninstall_codecs_button;

	GtkWidget *quit_button;

	///// The master window ////////////
	janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(janela), 10, 10);
	gtk_window_set_position(GTK_WINDOW(janela), GTK_WIN_POS_CENTER);

	////// Adds icon to systemtray and window-decoration/////////
	gtk_window_set_icon(GTK_WINDOW(janela), create_pixbuf("/usr/share/icons/mandriva.png"));
	
	////// Define the type of box for this variables
	choice_box = gtk_vbox_new(TRUE, 7);
	extras0 = gtk_hbox_new(TRUE, 7);
	extras1 = gtk_hbox_new(TRUE, 7);
	extras2 = gtk_hbox_new(TRUE, 7);
	label = gtk_label_new("Select an option or press Quit");
	////////////////////////////////////////
	
	///Window Title////////////
	gtk_window_set_title(GTK_WINDOW(janela), "Mandriva 2011 Stuff Installer");
	///////////////
	
	/////// Adds label to choice_box and choice_box do master_window ///////
	gtk_container_add(GTK_CONTAINER(choice_box), label);
	gtk_container_add(GTK_CONTAINER(janela), choice_box);

	/////// Adds horizontal boxes with buttons to the choice_box //////
	gtk_container_add(GTK_CONTAINER(choice_box), extras0);
	gtk_container_add(GTK_CONTAINER(choice_box), extras1);
	gtk_container_add(GTK_CONTAINER(choice_box), extras2);
//	gtk_container_add(GTK_CONTAINER(choice_box), quit_button);

	///// Create the buttons/////////////////
	quit_button = gtk_button_new_with_label("Quit");
	gtk_box_pack_start (GTK_BOX (choice_box), quit_button, FALSE, FALSE, 0);
	
	install_skype_button = gtk_button_new_with_label("Install Skype");
	gtk_box_pack_start (GTK_BOX (extras0), install_skype_button, TRUE, TRUE, 15);

	uninstall_skype_button = gtk_button_new_with_label("Uninstall Skype");
	gtk_box_pack_start (GTK_BOX (extras0), uninstall_skype_button, TRUE, TRUE, 15);

	install_flash_button = gtk_button_new_with_label("Install Flash");
	gtk_box_pack_start (GTK_BOX (extras1), install_flash_button, TRUE, TRUE, 15);
	
	uninstall_flash_button = gtk_button_new_with_label("Uninstall Flash");
	gtk_box_pack_start (GTK_BOX (extras1), uninstall_flash_button, TRUE, TRUE, 15);

	install_codecs_button = gtk_button_new_with_label("Install Codecs");
	gtk_box_pack_start (GTK_BOX (extras2), install_codecs_button, TRUE, TRUE, 15);
	
	uninstall_codecs_button = gtk_button_new_with_label("Uninstall Codecs");
	gtk_box_pack_start (GTK_BOX (extras2), uninstall_codecs_button, TRUE, TRUE, 15);
	///// end of button creation///////////

	//////// Show the master_window and all its babies//////
	gtk_widget_show_all(janela);
	////////////
	
	//////////// Funtions to buttons when they are clicked///////////
	g_signal_connect(install_skype_button, "clicked", 	
			G_CALLBACK(install_skype), NULL);

	g_signal_connect(uninstall_skype_button, "clicked", 
			G_CALLBACK(uninstall_skype), NULL);

	g_signal_connect(install_flash_button, "clicked", 	
			G_CALLBACK(install_flash), NULL);

	g_signal_connect(uninstall_flash_button, "clicked", 
			G_CALLBACK(uninstall_flash), NULL);

	g_signal_connect(quit_button, "clicked",
			G_CALLBACK(gtk_main_quit), G_OBJECT(janela));
	//////////////////////////////////////////////////////////////

	////The main window(eg. kwin) close button ///////////////////
	g_signal_connect_swapped(G_OBJECT(janela), "destroy",
			G_CALLBACK(gtk_main_quit), NULL);
	////////////////////////////////////////////////////////////////

	gtk_main();

/*	if(geteuid() != 0){
		printf ("Run as root\n");
	}else{
		printf ("1 - to Erase\n");
		printf ("2 - to Install\n");
		scanf ("%d", &choose);

		switch (choose){
			case 1: erase(); break;
			case 2: erase(); install(); break;
		}
	}*/
	return 0;
}
