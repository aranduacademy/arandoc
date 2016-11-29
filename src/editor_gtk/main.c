#include <gtk/gtk.h>

static void
draw_page(guint page_no){

}

static gboolean
drawingarea_ondraw(GtkWidget* widget, cairo_t* cr, gpointer data){
  GtkStyleContext* context;
  guint width, height;

  context = gtk_widget_get_style_context(widget);
  width   = gtk_widget_get_allocated_width(widget);
  height  = gtk_widget_get_allocated_height(widget);
  gtk_render_background(context,cr,0,0,width,height);
  cairo_set_source_rgb(cr,1,1,1);
  cairo_scale(cr,0.5,0.5);
  cairo_paint(cr);

  cairo_set_source_rgb(cr,0,0,0);
  cairo_move_to(cr, 10.0, 50.0);
  cairo_set_font_size(cr,23);
  cairo_select_font_face(cr,"Lato Light",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
  cairo_show_text(cr,"Exemplo de texto");
  return FALSE;
}


static void
activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window;

  GtkWidget *texteditor;
  GtkWidget *drawingarea;
  GtkWidget *box;
  GtkWidget *paned;
  GtkWidget *textview;

  // Creating our window
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Hello GNOME");

  // Creating our texteditor
  textview    = gtk_text_view_new();
  drawingarea = gtk_drawing_area_new();

  paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_paned_pack1(GTK_PANED(paned),textview,TRUE,TRUE);
  gtk_paned_pack2(GTK_PANED(paned),drawingarea,TRUE,TRUE);
  gtk_container_add(GTK_CONTAINER(window), paned);
  g_signal_connect(drawingarea,"draw",G_CALLBACK(drawingarea_ondraw),NULL);

  // Show everything
  gtk_widget_show_all(window);

}

int
main(int argc, char* argv[]){
  // Variables
  GtkApplication *app;
  int             status;

  // Creating our app
  app    = gtk_application_new("io.github.arandoc",G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  // Freeing memory
  g_object_unref(app);
  return status;
}
