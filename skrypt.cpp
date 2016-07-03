#include <gtk/gtk.h>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <pthread.h>

#include "iface.h"
#include "Lock64.xpm"

#include "Keyblock1.h"
#include "Keyblock2.h"
#include "Keyblock3.h"

typedef struct {
   const char* fileName;
   int hsize, hrev, kblock, algo;
   const char* bias;
} runner_t;

int running = 0;
char procMsg[1024];

GError* gerr;
GtkBuilder* builder;
GtkWidget *w, *w2, *pbar;

static gboolean progress_timeout(gpointer data)
{
	gdk_threads_enter();
	if (running) gtk_progress_bar_pulse(GTK_PROGRESS_BAR(pbar));
	else gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar), 0.0);
	gdk_threads_leave();
	return TRUE;
}

gboolean radioIsActive(const gchar* name)
{
   w2 = GTK_WIDGET(gtk_builder_get_object(builder, name));
   return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w2));
}

void radioSetActive(const gchar* name, gboolean val)
{
   w2 = GTK_WIDGET(gtk_builder_get_object(builder, name));
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(w2), val);
}

void showMessage(const gchar* ctx, const gchar* msg)
{
   w = GTK_WIDGET(gtk_builder_get_object(builder, "mainwin"));
   GtkWidget* dialog = gtk_message_dialog_new(GTK_WINDOW(w), GTK_DIALOG_DESTROY_WITH_PARENT, 
      GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "%s\n\n%s", ctx, msg);
   gtk_dialog_run(GTK_DIALOG (dialog));
   gtk_widget_destroy(dialog);
}

void showErrorMessage(const gchar* ctx, const gchar* msg)
{
   w = GTK_WIDGET(gtk_builder_get_object(builder, "mainwin"));
   GtkWidget* dialog = gtk_message_dialog_new(GTK_WINDOW(w), GTK_DIALOG_DESTROY_WITH_PARENT, 
      GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "%s\n\n%s", ctx, msg);
   gtk_dialog_run(GTK_DIALOG (dialog));
   gtk_widget_destroy(dialog);
}

void setSensitive(const gchar* name, gboolean val)
{
   w2 = GTK_WIDGET(gtk_builder_get_object(builder, name));
   gtk_widget_set_sensitive(w2, val);
}

void* runKeyBlock(void* parm)
{
   Keyblock* kb;
   runner_t* runInfo = (runner_t*)parm;

   if (!runInfo || !runInfo->fileName || strlen(runInfo->fileName) < 1 || !runInfo->bias || strlen(runInfo->bias) < 1)
   {
      snprintf(procMsg, sizeof(procMsg), "BAD PARAMS!");
      return 0;
   }
   
   running = 1;
   
   char buf[2048];
   snprintf(buf, 2048, "%s.skrypt", runInfo->fileName);

   FILE* datf = fopen(runInfo->fileName, "r");
   if (!datf)
   {
      snprintf(procMsg, sizeof(procMsg), "BAD INPUT FILE!");
      running = 0;
      return 0;
   }
   fseek(datf, 0L, SEEK_END);
   size_t s = ftell(datf);
   fseek(datf, 0L, SEEK_SET);
   
   char* data = (char*)calloc(s, sizeof(char));
   if (!data)
   {
      snprintf(procMsg, sizeof(procMsg), "BAD MEMORY!");
      running = 0;
      return 0;
   }
   
   size_t sx = fread(data, sizeof(char), s, datf);
   if (sx != s)
   {
      snprintf(procMsg, sizeof(procMsg), "FILE SIZE PROBLEM!");
      fclose(datf);
      free(data);
      running = 0;
      return 0;
   }
   
   fclose(datf);
   
   switch(runInfo->kblock)
   {
      case 2:  kb = new Keyblock2; break;
      case 3:  kb = new Keyblock3; break;
      default: kb = new Keyblock1; break;
   }
   
   kb->coder((unsigned char*)data, s, runInfo->bias, runInfo->hsize, runInfo->hrev, runInfo->algo);   
   
   datf = fopen(buf, "w");
   if (!datf)
   {
      snprintf(procMsg, sizeof(procMsg), "BAD OUTPUT FILE!");
      free(data);
      delete kb;
      running = 0;
      return 0;
   }

   sx = fwrite(data, sizeof(char), s, datf);
   if (sx != s)
   {
      snprintf(procMsg, sizeof(procMsg), "FILE SIZE PROBLEM!");
      fclose(datf);
      free(data);
      delete kb;
      running = 0;
      return 0;
   }

   snprintf(procMsg, sizeof(procMsg), "FILE PROCESSED SUCCESSFULLY");
   
   fclose(datf);
   free(data);
   delete kb;
   
   running = 0;   
   return 0;
}

static void go_cb(GtkWidget *widget, gpointer data)
{
   int rc;
   runner_t runInfo;
   pthread_t t;

   setSensitive("go_b", FALSE);

   w2 = GTK_WIDGET(gtk_builder_get_object(builder, "filechooser"));
   runInfo.fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(w2));
   if (!runInfo.fileName || strlen(runInfo.fileName) < 1)
   {
      showErrorMessage("ERROR", "Please choose a file to process..");
      setSensitive("go_b", TRUE);
      return;
   }

   if (radioIsActive("hsize_b2")) runInfo.hsize = 120;
   else if (radioIsActive("hsize_b3")) runInfo.hsize = 160;
   else runInfo.hsize = 80;

   if (radioIsActive("hrev_b2")) runInfo.hrev = 2;
   else if (radioIsActive("hrev_b3")) runInfo.hrev = 3;
   else if (radioIsActive("hrev_b4")) runInfo.hrev = 4;
   else runInfo.hrev = 1;

   if (radioIsActive("kblock_b2")) runInfo.kblock = 2;
   else if (radioIsActive("kblock_b3")) runInfo.kblock = 3;
   else runInfo.kblock = 1;

   if (radioIsActive("algo_b2")) runInfo.algo = 2;
   else if (radioIsActive("algo_b3")) runInfo.algo = 3;
   else runInfo.algo = 1;
   
   w2 = GTK_WIDGET(gtk_builder_get_object(builder, "pcode_entry"));
   runInfo.bias = gtk_entry_get_text(GTK_ENTRY(w2));
   if (!runInfo.bias || strlen(runInfo.bias) < 1) runInfo.bias = "...---...";
		
   
   setSensitive("filechooser", FALSE);
   setSensitive("hsize_b1", FALSE);
   setSensitive("hsize_b2", FALSE);
   setSensitive("hsize_b3", FALSE);
   setSensitive("hrev_b1", FALSE);
   setSensitive("hrev_b2", FALSE);
   setSensitive("hrev_b3", FALSE);
   setSensitive("hrev_b4", FALSE);
   setSensitive("kblock_b1", FALSE);
   setSensitive("kblock_b2", FALSE);
   setSensitive("kblock_b3", FALSE);
   setSensitive("algo_b1", FALSE);
   setSensitive("algo_b2", FALSE);
   setSensitive("algo_b3", FALSE);
   setSensitive("pcode_entry", FALSE);
   
      
   rc = pthread_create(&t, 0, runKeyBlock, &runInfo);
   rc = pthread_detach(t);
   if (rc != 0)
   {
      showMessage("THREAD PROBLEM", strerror(errno));
   }
   
   usleep(200);
   while (running) {
      usleep(100);
      while(gtk_events_pending()) gtk_main_iteration();
   }
   
   showMessage("FILE PROCESSED", procMsg);


   setSensitive("filechooser", TRUE);
   setSensitive("hsize_b1", TRUE);
   setSensitive("hsize_b2", TRUE);
   setSensitive("hsize_b3", TRUE);
   setSensitive("hrev_b1", TRUE);
   setSensitive("hrev_b2", TRUE);
   setSensitive("hrev_b3", TRUE);
   setSensitive("hrev_b4", TRUE);
   setSensitive("kblock_b1", TRUE);
   setSensitive("kblock_b2", TRUE);
   setSensitive("kblock_b3", TRUE);
   setSensitive("algo_b1", TRUE);
   setSensitive("algo_b2", TRUE);
   setSensitive("algo_b3", TRUE);
   setSensitive("pcode_entry", TRUE);
   setSensitive("go_b", TRUE);
}

int main(int argc, char *argv[])
{    
   gtk_init(&argc, &argv);
   
   if(!g_thread_supported()) gdk_threads_init();
   gdk_threads_enter();

   builder = gtk_builder_new();
   gtk_builder_add_from_string(builder, iface, -1, &gerr);

   w = GTK_WIDGET(gtk_builder_get_object(builder, "mainwin"));
   g_signal_connect(w, "destroy", G_CALLBACK(gtk_main_quit), NULL);
   g_signal_connect(w, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
   gtk_window_set_default_icon(gdk_pixbuf_new_from_xpm_data(Lock64));
   
   w2 = GTK_WIDGET(gtk_builder_get_object(builder, "go_b"));
   g_signal_connect(w2, "clicked", G_CALLBACK(go_cb), NULL);
   
   pbar = GTK_WIDGET(gtk_builder_get_object(builder, "pbar"));

   g_timeout_add(100, progress_timeout, 0);

   gtk_widget_show_all(w);

   radioSetActive("hsize_b1", TRUE);
   radioSetActive("hrev_b1", TRUE);
   radioSetActive("kblock_b1", TRUE);
   radioSetActive("algo_b1", TRUE);
   
   gtk_main();
   g_object_unref(G_OBJECT(builder));
   gdk_threads_leave();
   
   return 0;
}
