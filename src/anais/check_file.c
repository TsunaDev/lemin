/*
** check_file.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:34:56 2017 Anaïs Breant
** Last update Tue Apr 18 12:59:29 2017 Anaïs Breant
*/

#include	<unistd.h>
#include	"check_file.h"

char		**check_file(char **arr)
{
  int		return_value;

  return_value = check_nbr_ants(arr[0]);
  if (return_value == -1)
    return (NULL);
  arr = check_start_end(arr);
  if (arr == NULL)
    return (NULL);
  return (arr);
}
