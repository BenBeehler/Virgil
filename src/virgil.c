#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <webkit2/webkit2.h>

/*
Rudimentary Virgil window structure
*/
struct VirgilWindow {
  GtkWidget *window;
  GtkNotebook *notebook;
};

int add_browser_tab(struct VirgilWindow *vwindow) {
  GtkWidget *web;
  web = webkit_web_view_new();

  webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web), "https://duckduckgo.com");

  return gtk_notebook_append_page(vwindow->notebook, web, NULL);
}

/*
Initialize base window.
*/
void init(struct VirgilWindow *vwindow) {
  GtkWidget *window;
  GtkNotebook *notebook;

  notebook = gtk_notebook_new();
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
  gtk_window_set_title(GTK_WINDOW(window), "Virgil");

  gtk_container_add(GTK_CONTAINER(window), notebook);

  vwindow->window = window;
  vwindow->notebook = notebook;
}

/*
Render Virgil window
*/
int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  struct VirgilWindow main;

  init(&main);

  add_browser_tab(&main);
  add_browser_tab(&main);

  gtk_widget_show_all(main.window);
  gtk_main();

  return 0;
}