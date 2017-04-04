/*
** open_file.c for open_file.c in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by anaisbrnt
** Login   <anais.breant@epitech.eu>
**
** Started on  Tue Apr  4 17:12:19 2017 anaisbrnt
** Last update Tue Apr  4 14:43:01 2017 Glenn Gabriel Irakiza
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	"lib.h"
#include	"get_next_line.h"

char		**open_file(char *name_file)
{
  char		**arr;
  char		*gnl;
  char		*cat;
  int		fd;

  fd = open(name_file, O_RDONLY);
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

int		main(int ac, char **av)
{
  char		**arr;

  arr = open_file(av[1]);
  for (int i = 0; arr[i] != NULL; i++)
    printf("%s\n", arr[i]);
  for (int i = 0; arr[i] != NULL; i++)
    free(arr[i]);
  free(arr);
  return (0);
}
