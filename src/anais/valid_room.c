/*
** valid_room.c for valid_room.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Tue Apr 18 08:49:42 2017 Glenn Gabriel Irakiza
** Last update Tue Apr 18 09:31:30 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

static int	my_arg_valid(char *str)
{
  int		isnum;
  char		**arr;
  int		y;

  y = 1;
  arr = my_str_to_wordtab(str);
  while (arr[y] != NULL)
    {
      isnum = my_isnum(arr[y]);
      if (isnum != 0)
	{
	  my_free_array(arr);
	  return (1);
	}
      y++;
    }
  my_free_array(arr);
  return (0);
}

static int	pos_error_room(char **arr)
{
  int		nb_words;
  int		err;
  int		y;

  y = 0;
  err = 0;
  while (arr[y] != NULL)
    {
      nb_words = my_nb_words(arr[y]);
      if (nb_words == 3)
	{
	  err = my_arg_valid(arr[y]);
	  if (err == 1)
	    return (y);
	}
      y++;
    }
  return (-1);
}

int		my_valid_room(char **arr)
{
  int		pos_error;
  int		y;

  y = 0;
  pos_error = pos_error_room(arr);
  if (pos_error != -1)
    {
      while (y != pos_error)
	{
	  printf("%d, %d\n", pos_error, y);
	  y++;
	}
    }
  my_showtab(arr);
  return (0);
}
