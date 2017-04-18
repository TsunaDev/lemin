/*
** my_pars.c for my_pars.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Mon Apr 10 14:28:50 2017 Glenn Gabriel Irakiza
** Last update Tue Apr 18 13:15:51 2017 Anaïs Breant
*/

#include	"check_file.h"
#include	"my_string.h"

int		my_pars(char **arr)
{
  int		cpt;
  int		ants;
  int		return_value;

  arr = check_file(arr);
  if (arr == NULL)
    return (-1);
  arr = skip_bad_line(arr);
  cpt = 0;
  while (arr[cpt] != NULL)
    {
      if (arr[cpt][0] != '\0')
	{
	  my_putstr(1, arr[cpt]);
	  my_putstr(1, "\n");
	}
      cpt++;
    }
    /*ants = my_getnbr(arr[0]);
  printf("%d\n", ants);
  my_recup_room(arr);*/
  return (0);
}
