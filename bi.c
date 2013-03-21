#include <gtk/gtk.h>
#include <stdio.h>
#include <cairo.h>
#include <time.h>
GtkWidget *FileSelection;
GtkWidget *makeMenu();
static char buffer[256];
void OpenFile(GtkWidget *widget,gpointer *data);
void button_event(GtkWidget *widget,gpointer *data);
static gboolean
on_expose_event(GtkWidget *widget,
GdkEventExpose *event,
gpointer data)
{
cairo_t *cr;

cr = gdk_cairo_create(widget->window);

cairo_move_to(cr, 30, 30);
cairo_show_text(cr, buffer);

cairo_destroy(cr);

return FALSE;
}
static gboolean
time_handler(GtkWidget *widget)
{
if (widget->window == NULL) return FALSE;

time_t curtime;
struct tm *loctime;

curtime = time(NULL);
loctime = localtime(&curtime);
strftime(buffer, 256, "%T", loctime);

gtk_widget_queue_draw(widget);
return TRUE;
}

void destroy( GtkWidget *widget, gpointer data ) 
{ 
gtk_main_quit(); 
}
int main( int argc, char *argv[])
{

  GtkWidget *window;
  GtkWidget *send;
  GtkWidget *close;
  GtkWidget *label;
  GtkWidget *fixed;
  GtkWidget *open;
GtkWidget *done;
  GtkWidget *combo;
GtkWidget *table;
GtkWidget *text_view;
  GList *glist;
GtkWidget *menu;
GtkWidget *time;
GtkWidget *menubar;
GtkWidget *rootmenu;
GtkWidget *menuitem;
GtkWidget *view;
GtkToolItem *exit;
GtkTextBuffer *buffer;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
  gtk_window_set_title(GTK_WINDOW(window), "GtkAlignment");


fixed=gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(window),fixed);




/*按钮*/
  send= gtk_button_new_with_label("send");
gtk_fixed_put(GTK_FIXED(fixed),send,800,410);
gtk_widget_set_size_request(send, 100, 50);

  close = gtk_button_new_with_label("exit");
gtk_fixed_put(GTK_FIXED(fixed),close,800,550);
gtk_widget_set_size_request(close, 100, 50);

 g_signal_connect(GTK_OBJECT(close), "clicked",
        GTK_SIGNAL_FUNC(destroy),NULL);

open=gtk_button_new_with_label("receive");
gtk_fixed_put(GTK_FIXED(fixed),open,800,480);
gtk_widget_set_size_request(open, 100, 50);
 
done=gtk_button_new_with_label("设置");
gtk_fixed_put(GTK_FIXED(fixed),done,700,260);
gtk_widget_set_size_request(done, 150, 80);
  
time= gtk_drawing_area_new();
gtk_container_add(GTK_CONTAINER (window), time);

g_signal_connect(time, "expose-event",
G_CALLBACK(on_expose_event), NULL);
g_signal_connect(window, "destroy",
G_CALLBACK(gtk_main_quit), NULL);
gtk_fixed_put(GTK_FIXED(fixed),time,600,0);
gtk_widget_set_size_request(time, 100, 130);
gtk_window_set_title(GTK_WINDOW(time), "timer");
g_timeout_add(1000, (GSourceFunc) time_handler, (gpointer) window);
gtk_widget_show(window);
time_handler(window);
/*创建组合框*/
label=gtk_label_new("串口选择");

gtk_fixed_put(GTK_FIXED(fixed),label,720,50);
gtk_widget_set_size_request(close, 70, 30);
gtk_widget_show(label);
glist=NULL;
glist=g_list_append(glist,"串口1");
glist=g_list_append(glist,"串口2");
glist=g_list_append(glist,"串口3");
combo=gtk_combo_new();
gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);
gtk_fixed_put(GTK_FIXED(fixed),combo,800,50);
gtk_widget_set_size_request(combo,70,30);

gtk_widget_show(combo);
/*创建组合框*/

label=gtk_label_new("比特选择");

gtk_fixed_put(GTK_FIXED(fixed),label,720,150);
gtk_widget_set_size_request(close, 70, 30);
gtk_widget_show(label);
glist=NULL;
glist=g_list_append(glist,"1");
glist=g_list_append(glist,"2");
glist=g_list_append(glist,"3");
combo=gtk_combo_new();
gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);
gtk_fixed_put(GTK_FIXED(fixed),combo,800,150);
gtk_widget_set_size_request(combo,70,30);

gtk_widget_show(combo);

/*文本区*/


label=gtk_label_new("接收");

gtk_fixed_put(GTK_FIXED(fixed),label,30,30);

gtk_widget_set_size_request(label, 100, 50);
gtk_widget_show(label);
text_view=gtk_text_view_new();
buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));/*获得文本框缓冲区*/
gtk_fixed_put(GTK_FIXED(fixed),text_view,60,80);
gtk_widget_set_size_request(text_view, 500,150);
gtk_widget_show(text_view);

label=gtk_label_new("发送");
gtk_fixed_put(GTK_FIXED(fixed),label,60,260);
gtk_widget_set_size_request(close, 100, 50);
gtk_widget_show(label);
text_view=gtk_text_view_new();
buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));/*获得文本框缓冲区*/
gtk_fixed_put(GTK_FIXED(fixed),text_view,60,310);
gtk_widget_set_size_request(text_view, 500,150);
gtk_widget_show(text_view);

label=gtk_label_new("错误提示");

gtk_fixed_put(GTK_FIXED(fixed),label,60,500);
gtk_widget_set_size_request(close,100, 50);
gtk_widget_show(label);
text_view=gtk_text_view_new();
buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));/*获得文本框缓冲区*/

gtk_fixed_put(GTK_FIXED(fixed),text_view,60,530);
gtk_widget_set_size_request(text_view, 500,50);
gtk_widget_show(text_view);


/*菜单*/

menubar=makeMenu();
gtk_fixed_put(GTK_FIXED(fixed),menubar,0,0);
gtk_container_add(GTK_CONTAINER(window),menubar);
gtk_widget_show(menubar);
fixed=gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(window),fixed);
gtk_widget_set_size_request(menubar,70,30);

gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

GtkWidget *makeMenu()
{

GtkWidget *menu;
GtkWidget *menubar;
GtkWidget *rootmenu;
GtkWidget *menuitem;
menu=gtk_menu_new();
menuitem=gtk_menu_item_new_with_label("open");
gtk_menu_append(GTK_MENU(menu),menuitem);
gtk_signal_connect(GTK_OBJECT(menuitem),"clicked",GTK_SIGNAL_FUNC(button_event),NULL);
gtk_widget_show(menuitem);

menuitem=gtk_menu_item_new_with_label("edit");
gtk_menu_append(GTK_MENU(menu),menuitem);
gtk_widget_show(menuitem);

menuitem=gtk_menu_item_new_with_label("help");
gtk_menu_append(GTK_MENU(menu),menuitem);
gtk_widget_show(menuitem);

rootmenu=gtk_menu_item_new_with_label("file");
gtk_widget_show(rootmenu);
gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);

menubar=gtk_menu_bar_new();
gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);/*将一列项目放在一起*/
return menubar;
}
void button_event(GtkWidget *widget,gpointer *data)
{
FileSelection=gtk_file_selection_new("select");
gtk_file_selection_set_filename(GTK_FILE_SELECTION(FileSelection),"*.txt");
gtk_signal_connect(GTK_OBJECT(GTK_FILE_SELECTION(FileSelection)),"clicked",GTK_SIGNAL_FUNC(OpenFile),NULL);
gtk_widget_show(FileSelection);
}

void OpenFile(GtkWidget *widget,gpointer *data)
{
g_print("%s/n",gtk_file_selection_get_filename(GTK_FILE_SELECTION(FileSelection)));
}









