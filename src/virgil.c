#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <webkit2/webkit2.h>

void init();

/*
Initialize base window.
*/
int main(int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *web;

  gtk_init(&argc, &argv);

  web = webkit_web_view_new();
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
  gtk_window_set_title(GTK_WINDOW(window), "Virgil");

  gtk_container_add(GTK_CONTAINER(window), web);

  webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web), "https://duckduckgo.com");

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
