#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <webkit2/webkit2.h>

struct VirgilWindow {
  GtkWidget *window;
  GtkWidget *web;
};

/*
Initialize base window.
*/
void init(struct VirgilWindow *vwindow) {
  GtkWidget *window;
  GtkWidget *web;

  web = webkit_web_view_new();
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
  gtk_window_set_title(GTK_WINDOW(window), "Virgil");

  gtk_container_add(GTK_CONTAINER(window), web);

  webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web), "https://duckduckgo.com");

  vwindow->window = window;
  vwindow->web = web;
}

/*
Render Virgil window
*/
int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  struct VirgilWindow main;

  init(&main);

  gtk_widget_show_all(main.window);
  gtk_main();

  return 0;
}