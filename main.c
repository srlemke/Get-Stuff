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
	
	GtkWidget *install_button;
	GtkWidget *choice_box;
	GtkWidget *extras0;
	GtkWidget *erase_button;
	GtkWidget *quit_button;
	GtkWidget *janela;
	GtkWidget *label;
	GtkWidget *extras1, *install_flash, *uninstall_flash;
	GtkWidget *extras2, *do_some, *dirty_think;


	///// Cria a janela mae ////////////
	janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(janela), 10, 10);
	gtk_window_set_position(GTK_WINDOW(janela), GTK_WIN_POS_CENTER);

	////// Adiciona o icone qua vai aparecer na janela e barra de tarefas/////////
	gtk_window_set_icon(GTK_WINDOW(janela), create_pixbuf("/usr/share/icons/mandriva.png"));
	
	////// Define o tipo de caixa que serao essas duas variaves
	choice_box = gtk_vbox_new(TRUE, 7);
	extras0 = gtk_hbox_new(TRUE, 7);
	extras1 = gtk_hbox_new(TRUE, 7);
	extras2 = gtk_hbox_new(TRUE, 7);
	label = gtk_label_new("Select an option or press Quit");
	////////////////////////////////////////
	
	///Titulo da janela////////////
	gtk_window_set_title(GTK_WINDOW(janela), "Mandriva 2011 Helfer");
	///////////////
	
	/////// Adiciona a janela mae, a caixa quit box ///////
	gtk_container_add(GTK_CONTAINER(choice_box), label);
	gtk_container_add(GTK_CONTAINER(janela), choice_box);
	/////// Adiciona a janela quit_box a janela choice_box //////
	gtk_container_add(GTK_CONTAINER(choice_box), extras0);
	gtk_container_add(GTK_CONTAINER(choice_box), extras1);
	gtk_container_add(GTK_CONTAINER(choice_box), extras2);

	///// Cria os botoes/////////////////
	quit_button = gtk_button_new_with_label("Quit");
	gtk_box_pack_start (GTK_BOX (choice_box), quit_button, FALSE, FALSE, 0);
	
	install_button = gtk_button_new_with_label("Install Skype");
	gtk_box_pack_start (GTK_BOX (extras0), install_button, TRUE, TRUE, 15);

	erase_button = gtk_button_new_with_label("Uninstall Skype");
	gtk_box_pack_start (GTK_BOX (extras0), erase_button, TRUE, TRUE, 15);

	install_flash = gtk_button_new_with_label("Install FlashPlugin");
	gtk_box_pack_start (GTK_BOX (extras1), install_flash, TRUE, TRUE, 15);
	
	uninstall_flash = gtk_button_new_with_label("Uninstall FlashPlugin");
	gtk_box_pack_start (GTK_BOX (extras1), uninstall_flash, TRUE, TRUE, 15);
	
	do_some = gtk_button_new_with_label("Do some");
	gtk_box_pack_start (GTK_BOX (extras2), do_some, TRUE, TRUE, 15);
	
	dirty_think = gtk_button_new_with_label("dirty think...");
	gtk_box_pack_start (GTK_BOX (extras2), dirty_think, TRUE, TRUE, 15);
	
	///// Fim da criacao dos botoes///////////

	//////// Mostra a janela mae e todas as caixas nela//////
	gtk_widget_show_all(janela);
	////////////
	
	//////////// Funcoes aos botoes quando clicados///////////
	g_signal_connect(install_button, "clicked", 	
			G_CALLBACK(install), NULL);

	g_signal_connect(erase_button, "clicked", 
			G_CALLBACK(erase), NULL);

	g_signal_connect(quit_button, "clicked",
			G_CALLBACK(gtk_main_quit), G_OBJECT(janela));
	//////////////////////////////////////////////////////////////

	////Se o cara clicar no 'fechar' da janela ///////////////////
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
