/*
** check_file.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:34:56 2017 Anaïs Breant
** Last update Wed Apr 12 19:55:04 2017 Anaïs Breant
*/

#include	"check_file.h"

int		check_file(char **arr)
{
  int		return_value;

  return_value = check_nbr_ants(arr[0]);
  if (return_value == -1)
    return (-1);
  return_value = check_start_end(arr);
  if (return_value == -1)
    return (-1);
  return (0);
}
