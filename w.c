#include <gtk/gtk.h>
int main( int argc, char *argv[])
{

  GtkWidget *window;
  GtkWidget *send;
  GtkWidget *close;
  GtkWidget *label;
  GtkWidget *fixed;
  GtkWidget *open;
  GtkWidget *combo;
GtkWidget *table;
GtkWidget *text;
  GList *glist;
GtkWidget *menu;
GtkWidget *menubar;
GtkWidget *rootmenu;
GtkWidget *menuitem;
GtkWidget *vbox;
GtkWidget *toolbar;
GtkWidget *view;
GtkWidget *statusbar;
GtkToolItem *exit;
GtkTextBuffer *buffer;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 550, 400);
  gtk_window_set_title(GTK_WINDOW(window), "GtkAlignment");


fixed=gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(window),fixed);




/*按钮*/
  send= gtk_button_new_with_label("send");
gtk_fixed_put(GTK_FIXED(fixed),send,400,350);
gtk_widget_set_size_request(send, 70, 30);

  close = gtk_button_new_with_label("Close");

gtk_fixed_put(GTK_FIXED(fixed),close,400,400);
gtk_widget_set_size_request(close, 70, 30);

open=gtk_button_new_with_label("open");
gtk_fixed_put(GTK_FIXED(fixed),open,400,300);
gtk_widget_set_size_request(open, 70, 30);
  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));


/*创建组合框*/
label=gtk_label_new("串口选择");

gtk_fixed_put(GTK_FIXED(fixed),label,320,50);
gtk_widget_set_size_request(close, 70, 30);
gtk_widget_show(label);
glist=NULL;
glist=g_list_append(glist,"串口1");
glist=g_list_append(glist,"串口2");
glist=g_list_append(glist,"串口3");
combo=gtk_combo_new();
gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);
gtk_fixed_put(GTK_FIXED(fixed),combo,400,50);
gtk_widget_set_size_request(combo,70,30);

gtk_widget_show(combo);
/*创建组合框*/

label=gtk_label_new("比特选择");

gtk_fixed_put(GTK_FIXED(fixed),label,320,150);
gtk_widget_set_size_request(close, 70, 30);
gtk_widget_show(label);
glist=NULL;
glist=g_list_append(glist,"1");
glist=g_list_append(glist,"2");
glist=g_list_append(glist,"3");
combo=gtk_combo_new();
gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);
gtk_fixed_put(GTK_FIXED(fixed),combo,400,150);
gtk_widget_set_size_request(combo,70,30);

gtk_widget_show(combo);

/*文本区*/


label=gtk_label_new("接收");

gtk_fixed_put(GTK_FIXED(fixed),label,60,50);
gtk_widget_set_size_request(label, 70, 30);
gtk_widget_show(label);


gtk_fixed_put(GTK_FIXED(fixed),,60,80);
gtk_widget_set_size_request(text, 160,50);
gtk_widget_show(text);

label=gtk_label_new("发送");
gtk_fixed_put(GTK_FIXED(fixed),label,60,170);
gtk_widget_set_size_request(close, 70, 30);
gtk_widget_show(label);
text=gtk_entry_new_with_max_length(20000);
gtk_fixed_put(GTK_FIXED(fixed),text,60,200);
gtk_widget_set_size_request(text, 160,50);
gtk_widget_show(text);

label=gtk_label_new("错误提示");

gtk_fixed_put(GTK_FIXED(fixed),label,60,300);
gtk_widget_set_size_request(close, 70, 30);
gtk_widget_show(label);
text=gtk_entry_new_with_max_length(20000);

gtk_fixed_put(GTK_FIXED(fixed),text,60,350);
gtk_widget_set_size_request(text, 160,50);
gtk_widget_show(text);


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

menuitem=gtk_menu_item_new_with_label("new");
gtk_menu_append(GTK_MENU(menu),menuitem);
gtk_widget_show(menuitem);

menuitem=gtk_menu_item_new_with_label("open");
gtk_menu_append(GTK_MENU(menu),menuitem);
gtk_widget_show(menuitem);

rootmenu=gtk_menu_item_new_with_label("file");
gtk_widget_show(rootmenu);
gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);

menubar=gtk_menu_bar_new();
gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);/*将一列项目放在一起*/
return menubar;
}

