#include <gtk/gtk.h>
GtkWidget* makeTable();
GtkWidget* makeTextEntry();
GtkWidget* makecheckButtons();
GtkWidget* makeButtonBox();

void destroy(GtkWidget *widget,GdkEvent *event,gpointer data)
{
gtk_main_quit();
return ;
}

void click_button(GtkWidget *widget,gpointer *data)
{g_print("click %s ",(char *)data);
if(GTK_TOGGLE_BUTTON(widget)->active)
g_print("and state is active\n");
else g_print("and state is not active\n");
}
int main(int argc,char *argv[])
{
GtkWidget *window;
GtkWidget *table;

gtk_init(&argc,&argv);
window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(destroy),NULL);
gtk_window_set_title(GTK_WINDOW(window),"Test radio buttons");
gtk_container_set_border_width(GTK_CONTAINER(window),100);

table=makeTable();
gtk_container_add(GTK_CONTAINER(window),table);

gtk_widget_show(window);

gtk_main();
return 0;
}



GtkWidget* makeTable()
{

GtkWidget *table;
GtkWidget *checkButtons;
GtkWidget *textEntry;
GtkWidget *buttonBox;

table=gtk_table_new(2,2,FALSE);
gtk_widget_show(table);

/**/
textEntry=makeTextEntry();
gtk_table_attach(GTK_TABLE(table),textEntry,0,1,0,1,GTK_FILL|GTK_EXPAND|GTK_SHRINK,0,0,0);
gtk_widget_show(textEntry);

checkButtons=makecheckButtons();
gtk_table_attach(GTK_TABLE(table),checkButtons,1,2,0,1,GTK_FILL|GTK_EXPAND,GTK_FILL|GTK_EXPAND,10,0);
gtk_widget_show(checkButtons);

buttonBox=makeButtonBox();
gtk_table_attach(GTK_TABLE(table),buttonBox,0,2,1,2,GTK_EXPAND|GTK_FILL|GTK_SHRINK,0,5,10);
gtk_widget_show(buttonBox);

return table;
}

GtkWidget* makeTextEntry()
{
GtkWidget *vbox;
GtkWidget *label;
GtkWidget *text;

vbox=gtk_vbox_new(FALSE,5);

label=gtk_label_new("输入");
gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,0);
gtk_widget_show(label);

text=gtk_entry_new_with_max_length(15);
gtk_box_pack_start(GTK_BOX(vbox),text,FALSE,FALSE,0);
gtk_widget_show(text);

return vbox;
}


GtkWidget* makecheckButtons()
{
GtkWidget *vbox;
GtkWidget *check;

vbox=gtk_vbox_new(FALSE,0);

check=gtk_check_button_new_with_label("串口");
g_signal_connect(GTK_OBJECT(check),"clicked",GTK_SIGNAL_FUNC(click_button),"串口");
gtk_box_pack_start(GTK_BOX(vbox),check,FALSE,FALSE,0);
gtk_widget_show(check);

return vbox;
}

GtkWidget* makeButtonBox()
{
GtkWidget *hbox;
GtkWidget *button;
hbox=gtk_hbox_new(FALSE,0);
button=gtk_button_new_with_label("send");
gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,20);
gtk_widget_show(button);

button=gtk_button_new_with_label("no");
gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,60);
gtk_widget_show(button);

return hbox;

}
