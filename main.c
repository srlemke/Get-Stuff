#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include <gtk/gtk.h>

int info_message(char *message)
{
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(NULL,
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, "%s", message);

	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_hide(dialog);
	return 0;
}
/*
int uninstall_info(GtkWidget *widget, gpointer)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK,
			"Just uninstalled all old versions.");
	gtk_window_set_title(GTK_WINDOW(dialog), "Information");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	return 0;
}

int install_info(GtkWidget *widget, gpointer)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK,
			"Installation in progress, wait...");
	gtk_window_set_title(GTK_WINDOW(dialog), "Information");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	return 0;
}

int medias_info(GtkWidget *widget, gpointer window)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK,
			"You are on a 64bit system, please enable 32bits medias.\n" 
			"After, i will download and extract skype to the correct place\n"
			"it may take some time buy i will tell you when it's done\n");
	gtk_window_set_title(GTK_WINDOW(dialog), "Information");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	return 0;
}
*/
int main(int argc, char **argv)
{
	GtkBuilder *builder;
	GtkWidget  *window;
	GError     *error = NULL;

	// Init GTK+
	gtk_init( &argc, &argv );

	// Create new GtkBuilder object

	//
	builder = gtk_builder_new();
	// Load UI from file. If error occurs, report it and quit application.
	//      * Replace "tut.glade" with your saved project. //
	if( ! gtk_builder_add_from_file( builder, "interface.glade", &error ) )
	{
		g_warning( "%s", error->message );
		g_free( error );
		return( 1 );
	}

	// Get main window pointer from UI //
	window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );

	// Connect signals //
	gtk_builder_connect_signals( builder, NULL );

	// Destroy builder, since we don't need it anymore //
	g_object_unref( G_OBJECT( builder ) );

	// Show window. All other widgets are automatically shown by GtkBuilder //
	gtk_widget_show( window );

	// Start main loop //
	gtk_main();
	return 0;
}
