/*
** main.c for main.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:24:34 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 26 17:11:57 2017 Anaïs Breant
*/

#include	"lemin.h"
#include	"my_string.h"

int		main()
{
  int		return_value;
  char		**arr;

  arr = open_file(0);
  return_value = my_pars(arr);
  if (return_value == 84)
    return (84);
  my_free_array(arr);
  return (0);
}
