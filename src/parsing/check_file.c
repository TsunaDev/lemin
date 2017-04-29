/*
** check_file.c for Lem_in in /home/anaisbrnt/EPITECH/Projet/CPE/lem_in/CPE_2016_Lemin/src/anais
**
** Made by Anaïs Breant
** Login   <anais.breant@epitech.eu>
**
** Started on  Wed Apr 12 19:34:56 2017 Anaïs Breant
** Last update Sat Apr 29 15:32:20 2017 Glenn Gabriel Irakiza
*/

#include	<unistd.h>
#include	"check_file.h"
#include	"my_string.h"

static int	my_isnum_change(char *str)
{
  int		isnum;

  isnum = my_isnum(str);
  if (isnum != 0 && str[0] == '#' && str[1] != '#')
    return (1);
  return (0);
}

static int	my_change_arr(char **arr)
{
  int		y;
  int		isnum;
  int		i;

  y = 0;
  i = 0;
  if (arr[y] == NULL)
    return (84);
  isnum = my_isnum_change(arr[y]);
  if (isnum != 0)
    while (isnum == 1)
      {
	y++;
	isnum = my_isnum_change(arr[y]);
	if (isnum != 0)
	  free(arr[y]);
      }
  while (arr[y] != NULL)
    {
      arr[i] = arr[y];
      i++;
      y++;
    }
  return (0);
}

static int	my_strcmp_rev(char *str, char *cmp)
{
  char		**ddouble;
  int		opt;
  int		bool;

  ddouble = my_strnchar_to_wordtab(cmp, '-');
  opt = my_strcmp(ddouble[0], ddouble[1]);
  my_free_array(ddouble);
  if (opt == 0)
    return (0);
  my_revstr(cmp);
  bool = my_strcmp(str, cmp);
  my_revstr(cmp);
  return (bool);
}

void		suppr_double_tun(char **arr)
{
  int		y[2];
  int		cmp;
  int		words[2];

  y[0] = 0;
  while (arr[y[0]] != NULL)
    {
      y[1] = 0;
      while (arr[y[1]] != NULL)
	{
	  words[0] = my_nb_words_char(arr[y[0]], '-', 0);
	  words[1] = my_nb_words_char(arr[y[1]], '-', 0);
	  if (words[0] == 2 && words[1] == 2 && (y[0] != y[1]))
	    {
	      cmp = my_strcmp_rev(arr[y[1]], arr[y[0]]);
	      if (cmp == 0)
		{
		  free(arr[y[0]]);
		  arr[y[0]] = my_strdup("");
		}
	    }
	  y[1]++;
	}
      y[0]++;
    }
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
