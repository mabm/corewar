#ifndef        __GNL_H__
# define    __GNL_H__

#define        BUF_SIZE 5000
#define        BUF_READ 5000

typedef struct    s_var
{
  char       *buffer;
  int        i;
  int        pos;
  int        nb_read;
}        t_var;

char        *get_next_line(const int fd);

#endif        /*__GNL_H__*/
