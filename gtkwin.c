#include<gtk/gtk.h> /*调用gtk_init来完成对gtk库的初始化*/

void hello(GtkWidget *widget,gpointer *data)/*定义回调函数，单击系统时自动调用*/
{
g_print("button clicked and data = %s\n",(char *)data);

}
void destroy(GtkWidget *widget,gpointer *data)/*定义回调函数，关闭系统时自动调用*/
{
gtk_main_quit();
}

int main(int argc,char **argv)
{
/*定义指向控件的指针*/
GtkWidget *window;
GtkWidget *button;

gtk_init(&argc,&argv);/*定位和打开图形显示，并对颜色，信号等进行初始化，在命令行输入的函数由该函数传入GTK+*/

/*创建窗口，并设置到关闭窗口时要回调的函数*/
window=gtk_window_new(GTK_WINDOW_TOPLEVEL);/*建立窗口*/
g_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(destroy),NULL);

gtk_container_border_width(GTK_CONTAINER(window),200);/*设置边框大小*/

button=gtk_button_new_with_label("Hello World");/*创建按钮，并设置当单击按钮时，要执行的回调函数*/
g_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(hello),"I am from button");
/*将按钮加入到窗口中*/
gtk_container_add(GTK_CONTAINER(window),button);
/*显示*/
gtk_widget_show(button);
gtk_widget_show(window);
/*处理*/
gtk_main();
return 0;
}
