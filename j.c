#include<gtk/gtk.h>
GtkWidget *FileSelection;
void OpenFile(GtkWidget *widget,gpointer *data);
void button_event(GtkWidget *widget,gpointer *data);
int main(int argc,char *argv[])
{
GtkWidget *window;
GtkWidget *button;

gtk_init(&argc,&argv);
window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
button=gtk_button_new_with_label("open");
gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(button_event),NULL);
gtk_container_add(GTK_CONTAINER(window),button);
gtk_widget_show(button);
gtk_widget_show(window);
gtk_main();
}
void button_event(GtkWidget *widget,gpointer *data)
{
FileSelection=gtk_file_selection_new("select");
gtk_file_selection_set_filename(GTK_FILE_SELECTION(FileSelection),"*.c");
gtk_signal_connect(GTK_OBJECT(GTK_FILE_SELECTION(FileSelection)),"clicked",GTK_SIGNAL_FUNC(OpenFile),NULL);
gtk_widget_show(FileSelection);
}

void OpenFile(GtkWidget *widget,gpointer *data)
{
g_print("%s/n",gtk_file_selection_get_filename(GTK_FILE_SELECTION(FileSelection)));
}
