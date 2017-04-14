/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Thu Apr 13 14:53:02 2017 Anaïs Breant
*/

#include	"check_file.h"
#include	"my_string.h"

int		my_pars(char **arr)
{
  int		cpt;
  int		ants;
  int		return_value;

  return_value = check_file(arr);
  if (return_value == -1)
    return (-1);
  arr = skip_bad_line(arr);
  cpt = 0;
  while (arr[cpt] != NULL)
    {
      printf("%s\n", arr[cpt]);
      cpt++;
    }
    /*ants = my_getnbr(arr[0]);
  printf("%d\n", ants);
  my_recup_room(arr);*/
  return (0);
}
