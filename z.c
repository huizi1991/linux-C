#include <gtk/gtk.h>
GtkWidget *makeMenu();
GtkWidget *update_statusbar(GtkTextBuffer *buffer,
    GtkStatusbar  *statusbar);
GtkWidget *mark_set_callback(GtkTextBuffer *buffer,
    const GtkTextIter *new_location, GtkTextMark *mark,
    gpointer data);
GtkWidget *Text;
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
text=Text();
gtk_fixed_put(GTK_FIXED(fixed),text,60,80);
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
/*text*/
GtkWidget *Text()
{
 GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *toolbar;
  GtkWidget *view;
  GtkWidget *statusbar;
  GtkToolItem *exit;
  GtkTextBuffer *buffer;



  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 250, 200);
  gtk_window_set_title(GTK_WINDOW(window), "lines & cols");

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

  exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit, -1);

  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  view = gtk_text_view_new();
  gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 0);
  gtk_widget_grab_focus(view);

  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

  statusbar = gtk_statusbar_new();
  gtk_box_pack_start(GTK_BOX(vbox), statusbar, FALSE, FALSE, 0);

  g_signal_connect(G_OBJECT(exit), "clicked", 
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(buffer, "changed",
        G_CALLBACK(update_statusbar), statusbar);

  g_signal_connect_object(buffer, "mark_set", 
        G_CALLBACK(mark_set_callback), statusbar, 0);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  update_statusbar(buffer, GTK_STATUSBAR (statusbar));



  return buffer;
}

GtkWidget *update_statusbar(GtkTextBuffer *buffer,
    GtkStatusbar  *statusbar)
{
  gchar *msg;
  gint row, col;
  GtkTextIter iter;

  gtk_statusbar_pop(statusbar, 0); 

  gtk_text_buffer_get_iter_at_mark(buffer,
      &iter, gtk_text_buffer_get_insert(buffer));

  row = gtk_text_iter_get_line(&iter);
  col = gtk_text_iter_get_line_offset(&iter);

  msg = g_strdup_printf("Col %d Ln %d", col+1, row+1);

  gtk_statusbar_push(statusbar, 0, msg);

  g_free(msg);
}

GtkWidget *mark_set_callback(GtkTextBuffer *buffer,
    const GtkTextIter *new_location, GtkTextMark *mark,
    gpointer data)
{
  update_statusbar(buffer, GTK_STATUSBAR(data));
}

