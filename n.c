#include <gtk/gtk.h>

int main( int argc, char *argv[])
{

  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *toolbar;
  GtkWidget *text_view;
  GtkWidget *statusbar;
  GtkToolItem *exit;
  GtkTextBuffer *buffer;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
  gtk_window_set_title(GTK_WINDOW(window), "lines & cols");

  
 text_view=gtk_text_view_new();/*创建文本框构件*/
buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));/*获得文本框缓冲区*/
gtk_container_add(GTK_CONTAINER(window),text_view);
gtk_widget_show(text_view);

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
