/*
** open_file.c for open_file.c in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by anaisbrnt
** Login   <anais.breant@epitech.eu>
**
** Started on  Tue Apr  4 17:12:19 2017 anaisbrnt
** Last update Tue Apr  4 17:19:28 2017 anaisbrnt
*/

#include	<fcntl.h>

char		*open_file(char *name_file)
{
  char		*str_gnl;
  int		fd;

  fd = open(name, O_RDONLY);
  if (fd == -1)
    return (NULL);
  return ();
}
