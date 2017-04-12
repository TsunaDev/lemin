/*
** my_putstr.c for my_putstr.c in /home/gaby/projet_Epitech/CPE/CPE_2016_corewar/asm_corewar/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sat Mar 25 16:34:29 2017 Glenn Gabriel Irakiza
** Last update Mon Apr 10 09:50:26 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_string.h"

void		my_putstr(int fd, char *str)
{
  int		len;

  if (str == NULL)
    return ;
  len = my_strlen(str);
  write(fd, str, len);
}
