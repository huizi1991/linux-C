#include <gtk/gtk.h>
#include<glib.h>
void delete_handle(GtkWidget *widget,GdkEvent *event,gpointer data)
{
gtk_main_quit();
return ;
}

int main(int argc,char *argv[])
{
GtkWidget *window=NULL;
GtkWidget *box1;
GtkWidget *menu;
GtkWidget *menubar;
GtkWidget *rootmenu;
GtkWidget *menuitem;
GtkWidget *box2;
GtkWidget *button;
GtkWidget *separator;
GSList *group;
gtk_init(&argc,&argv);
window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_signal_connect(GTK_OBJECT(window),"delete_event",GTK_SIGNAL_FUNC(delete_handle),NULL);
gtk_window_set_title(GTK_WINDOW(window),"Test radio buttons");
gtk_container_set_border_width(GTK_CONTAINER(window),100);


/*box1*/


box1=gtk_vbox_new(FALSE,0);
gtk_container_add(GTK_CONTAINER(window),box1);

/*按钮*/

button=gtk_radio_button_new_with_label(NULL,"send");
group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
gtk_box_pack_start(GTK_BOX(box1),button,FALSE,FALSE,0);
gtk_widget_show(button);
button=gtk_radio_button_new_with_label(NULL,"cancel");
group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button),TRUE);
gtk_box_pack_start(GTK_BOX(box1),button,FALSE,FALSE,0);

gtk_widget_show(button);
gtk_widget_show(box1);
/*box2*/

box2=gtk_vbox_new(FALSE,0);
gtk_container_add(GTK_CONTAINER(window),box2);
button=gtk_radio_button_new_with_label(NULL,"send");
group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
gtk_box_pack_start(GTK_BOX(box2),button,FALSE,FALSE,0);
gtk_widget_show(button);
button=gtk_radio_button_new_with_label(NULL,"cancel");
group=gtk_radio_button_group(GTK_RADIO_BUTTON(button));
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button),TRUE);
gtk_box_pack_start(GTK_BOX(box2),button,FALSE,FALSE,0);

gtk_widget_show(button);
gtk_widget_show(box2);


gtk_widget_show(window);
gtk_main();
return(0);
}
