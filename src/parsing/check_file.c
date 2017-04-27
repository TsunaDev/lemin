/*
** check_file.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:34:56 2017 Anaïs Breant
** Last update Thu Apr 27 13:18:46 2017 Glenn Gabriel Irakiza
*/

#include	<unistd.h>
#include	"check_file.h"
#include	"my_string.h"

static int	my_change_arr(char **arr)
{
  int		y;
  int		isnum;
  int		i;

  y = 0;
  i = 0;
  if (arr[y] == NULL)
    return (84);
  isnum = my_isnum(arr[y]);
  if (isnum != 0 && (arr[y][0] == '#' && arr[y][1] != '#'))
    {
      while (isnum == 1)
	{
	  y++;
	  isnum = my_isnum(arr[y]);
	  if (isnum != 0 && (arr[y][0] == '#' && arr[y][1] != '#'))
	    free(arr[y]);
	  else
	    isnum =0;
	}
    }
  while (arr[y] != NULL)
    {
      arr[i] = arr[y];
      i++;
      y++;
    }
  return (0);
}

int		check_file(char **arr)
{
  int		nbr_ants;
  int		return_value;

  if (arr == NULL)
    return (-1);
  my_change_arr(arr);
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
