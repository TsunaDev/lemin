/*
** check_nbr_ants.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 18:56:20 2017 Anaïs Breant
** Last update Fri Apr 21 10:46:48 2017 Anaïs Breant
*/

#include	"my_string.h"
#include	"check_file.h"

int		check_nbr_ants(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] >= '0' && str[cpt] <= '9')
	cpt++;
      else
	{
	  my_putstr(2, "Error with the number of ants\n");
	  return (-1);
	}
    }
  return (0);
}
