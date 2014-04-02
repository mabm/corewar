/*
** main2.c for Corewar in /home/jobertomeu/Work/corewar/assembleur/gtk
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Mon Mar 31 18:12:56 2014 Joris Bertomeu
** Last update Mon Mar 31 18:38:22 2014 Joris Bertomeu
*/

# define WINDOW		sys->widgets->window
# define FRAME		sys->widgets->frame
# define VMB		sys->widgets->vm_b
# define ASMB		sys->widgets->asm_b
# define ABTB		sys->widgets->about_b
# define QB		sys->widgets->quit_b
# include <gdk/gdkkeysyms.h>
# include <gtk/gtk.h>
# include <stdlib.h>
# include <stdio.h>
# include <termios.h>
# include <pthread.h>

typedef struct	s_widgets t_widgets;
struct		s_widgets
{
  GtkWidget	*window;
  GtkWidget	*drag;
  GtkWidget	*chat_label;
  GtkWidget	*vm_b;
  GtkWidget	*asm_b;
  GtkWidget	*frame;
  GtkWidget	*about_b;
  GtkWidget	*quit_b;
  GtkWidget	*dialog;
  GtkWidget	*enter_button;
  GtkWidget	*clear;
  GtkWidget	*sw;
  GtkWidget	*icona;
  GtkWidget	*chat_entry;
  GtkWidget	*about;
};

typedef struct	s_system t_system;
struct		s_system
{
  t_widgets	*widgets;
};

void	init_window(t_system *sys)
{
  WINDOW = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(WINDOW), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(WINDOW), 400, 450);
  gtk_window_set_title(GTK_WINDOW(WINDOW), "Corewar - Assembleur");
}

void	init_frame(t_system *sys)
{
  FRAME = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(WINDOW), FRAME);
}

void	init_drag(t_system *sys)
{
  printf("En préparation\n");
}

void	init_vm_b(t_system *sys)
{
  VMB = gtk_button_new_with_label("Launch Virtual Machine");
  gtk_widget_set_size_request(VMB, 200, 50);
  gtk_fixed_put(GTK_FIXED(FRAME), VMB, 100, 50);
}

void	init_asm_b(t_system *sys)
{
  ASMB = gtk_button_new_with_label("Launch Assembly");
  gtk_widget_set_size_request(ASMB, 200, 50);
  gtk_fixed_put(GTK_FIXED(FRAME), ASMB, 100, 150);
}

void	init_about_b(t_system *sys)
{
  ABTB = gtk_button_new_with_label("About");
  gtk_widget_set_size_request(ABTB, 200, 50);
  gtk_fixed_put(GTK_FIXED(FRAME), ABTB, 100, 250);
}

void	init_quit_b(t_system *sys)
{
  QB = gtk_button_new_with_label("Quit");
  gtk_widget_set_size_request(QB, 200, 50);
  gtk_fixed_put(GTK_FIXED(FRAME), QB, 100, 350);
}

void	init_var(t_system *sys, int ac, char **argv)
{
  init_window(sys);
  init_frame(sys);
  init_vm_b(sys);
  init_asm_b(sys);
  init_about_b(sys);
  init_quit_b(sys);
}

void	quit()
{
  printf("Good bye !\n");
  exit(0);
}

int	main(int ac, char *argv[])
{
  t_system	*sys;

  sys = malloc(sizeof(*sys));
  sys->widgets = malloc(sizeof(*sys->widgets));
  gtk_init(&ac, &argv);
  init_var(sys, ac, argv);
  gtk_widget_show_all(WINDOW);
  g_signal_connect(WINDOW, "destroy", G_CALLBACK (quit), NULL);

  gtk_main();
  return (0);
}
