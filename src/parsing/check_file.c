/*
** check_file.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:34:56 2017 Anaïs Breant
** Last update Thu Apr 27 14:43:20 2017 Anaïs Breant
*/

#include	<unistd.h>
#include	"check_file.h"
#include	"my_string.h"

int		check_file(char **arr)
{
  int		nbr_ants;
  int		return_value;

  if (arr == NULL)
    return (-1);
  return_value = check_nbr_ants(arr[0]);
  if (return_value == -1)
    {
      arr[0] = NULL;
      nbr_ants = 0;
      return (nbr_ants);
    }
  else
    nbr_ants = my_getnbr(arr[0]);
  arr = check_start_end(arr);
  if (arr == NULL)
    return (-1);
  return (nbr_ants);
}
