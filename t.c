#include<gtk/gtk.h>
int main(int argc,char **argv)
{
GtkWidget *window;
GtkWidget *menu;
GtkWidget *menu1;
GtkWidget *menubar;
GtkWidget *rootmenu;
GtkWidget *menuitem;
GtkWidget *menuitem1;
gtk_init(&argc,&argv);
window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"menu demo");
g_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(gtk_main_quit),NULL);
gtk_container_border_width(GTK_CONTAINER(window),20);


/*创建菜单项*/
menu=gtk_menu_new();
menuitem=gtk_menu_item_new_with_label("new");
gtk_menu_append(GTK_MENU(menu),menuitem);
gtk_widget_show(menuitem);
menu1=gtk_menu_new();
menuitem1=gtk_menu_item_new_with_label("open");
gtk_menu_append(GTK_MENU(menu),menuitem1);
gtk_widget_show(menuitem1);



/*创建主菜单*/
rootmenu=gtk_menu_item_new_with_label("file");
gtk_widget_show(rootmenu);
gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);
gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu1);
/*将菜单添加到主菜单中*/
menubar=gtk_menu_bar_new();/*创建菜单条*/
/*将主菜单加到菜单条中*/
gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);
gtk_container_add(GTK_CONTAINER(window),menubar);
gtk_widget_show(menubar);
gtk_widget_show(window);
gtk_main();
return 0;
}


