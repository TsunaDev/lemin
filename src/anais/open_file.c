/*
** open_file.c for open_file.c in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by anaisbrnt
** Login   <anais.breant@epitech.eu>
**
** Started on  Tue Apr  4 17:12:19 2017 anaisbrnt
** Last update Mon Apr 10 14:27:35 2017 Glenn Gabriel Irakiza
*/

#include	<unistd.h>
#include	"my_string.h"
#include	"get_next_line.h"

char		**open_file(int fd)
{
  char		**arr;
  char		*gnl;
  char		*cat;

  if (fd == -1)
    return (NULL);
  gnl = get_next_line(fd);
  if (!gnl)
    return (NULL);
  cat = my_strcat(gnl, NULL, 0);
  while (gnl != NULL)
    {
      free(gnl);
      gnl = get_next_line(fd);
      cat = my_strcat(cat, "\n", 1);
      cat = my_strcat(cat, gnl, 1);
    }
  close(fd);
  arr = my_strnchar_to_wordtab(cat, '\n');
  free(cat);
  return (arr);
}
