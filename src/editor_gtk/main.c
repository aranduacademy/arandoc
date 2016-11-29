#include <gtk/gtk.h>

GtkWidget *textview;
GtkWidget *drawingarea;
GtkTextBuffer *textbuffer;

GArray* paragraphs;

static void
draw_page(guint page_no){

}

static gboolean
drawingarea_ondraw(GtkWidget* widget, cairo_t* cr, gpointer data){
  GtkStyleContext* context;
  guint width, height;
  GtkTextIter start, end;

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
  gtk_text_buffer_get_start_iter(textbuffer,&start);
  gtk_text_buffer_get_end_iter(textbuffer,&end);
  gchar* text = gtk_text_buffer_get_text(textbuffer,&start,&end,TRUE);
  //cairo_show_text(cr,"Exemplo de texto");
  cairo_show_text(cr,text);
  return FALSE;
}

static void
textbuffer_onchanged(GtkTextBuffer* textbuffer, gpointer user_data){
  gtk_widget_queue_draw(drawingarea);
}

static gboolean
textview_onkeypress(GtkWidget* widget, GdkEvent* event, gpointer user_data){
  if(event->key.keyval == GDK_KEY_Return){
    printf("%d\n",gtk_text_buffer_get_line_count(textbuffer));
  }
  return FALSE;
}

static void
activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window;

  GtkWidget *texteditor;
  GtkWidget *box;
  GtkWidget *paned;

  // Creating our window
  window = gtk_application_window_new(app);
  gtk_widget_set_size_request(window, 200, 200);
  gtk_window_set_title(GTK_WINDOW(window), "Hello GNOME");

  // Creating our texteditor
  textview    = gtk_text_view_new();
  drawingarea = gtk_drawing_area_new();

  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview),GTK_WRAP_WORD);

  paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_paned_pack1(GTK_PANED(paned),textview,TRUE,TRUE);
  gtk_paned_pack2(GTK_PANED(paned),drawingarea,TRUE,TRUE);
  gtk_container_add(GTK_CONTAINER(window), paned);


  // Events
  textbuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
  g_signal_connect(drawingarea,"draw",G_CALLBACK(drawingarea_ondraw),NULL);
  g_signal_connect(textbuffer, "changed", G_CALLBACK(textbuffer_onchanged), NULL);
  g_signal_connect(textview, "key-press-event", G_CALLBACK(textview_onkeypress), NULL);

  //paragraphs = g_array_new();

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
