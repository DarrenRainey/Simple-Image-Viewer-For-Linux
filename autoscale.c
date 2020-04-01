// test.c
// Tested with:
//
//  $ cc -O2 `pkg-config --cflags gtk+-3.0` \
//       -o test test.c \
//       `pkg-config --libs gtk+-3.0`
//  $ ./test pic.jpg
//
#include <gtk/gtk.h>

int main ( int argc, char **argv )
{
  GtkWidget *window;
  GtkWidget *image;

  gtk_init ( &argc, &argv );

  window = gtk_window_new ( GTK_WINDOW_TOPLEVEL );
  image  = gtk_image_new_from_file ( argv[1] );

  // g_signal_connect() and G_OBJECT, not gtk_ and GTK_!
  g_signal_connect ( G_OBJECT ( window ), "destroy",
                     gtk_main_quit, NULL );

  gtk_container_add ( GTK_CONTAINER ( window ), image );

  // Here we go...
  gtk_window_set_decorated( GTK_WINDOW( window ), 0 ); // turn decoration off.
  gtk_window_maximize ( GTK_WINDOW( window ) );        // maximize window.

  gtk_widget_show_all ( window );

  gtk_main();

  return 0;
}
