/*
** valid_file.c for valid_file.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Tue Apr 18 08:49:42 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 16:26:42 2017 Glenn Gabriel Irakiza
*/

#include	"check_file.h"
#include	"my_string.h"

static int	cmp_error(char *str)
{
  int		isnum;
  char		**tmp;

  tmp = my_str_to_wordtab(str);
  isnum = my_strlen_char(tmp);
  if (isnum < 3 || isnum > 3)
    return (84);
  isnum = my_isnum(tmp[1]);
  if (isnum != 0)
    return (84);
  isnum = my_isnum(tmp[2]);
  if (isnum != 0)
    return (84);
  my_free_array(tmp);
  return (0);
}

int		check_after_start_end(char **arr)
{
  int		isnum;
  int		cmp[2];
  int		y;

  y = 0;
  while (arr[y] != NULL)
    {
      cmp[0] = my_strcmp(arr[y], "##start");
      cmp[1] = my_strcmp(arr[y], "##end");
      if (cmp[0] == 0 || cmp[1] == 0)
	{
	  y = skip_line_void(arr, y);
	  if (my_strlen(arr[y]) == 0)
	    return (84);
	  else
	    {
	      isnum = cmp_error(arr[y]);
	      if (isnum != 0)
		return (84);
	    }
	}
      y++;
    }
  return (0);
}

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

int		my_valid_file(char **arr)
{
  int		len;
  int		y;

  len = my_strlen_tab(arr);
  y = pos_error_room(arr);
  if (y != -1)
    {
      free(arr[y]);
      arr[y] = NULL;
      while (y != len)
	{
	  free(arr[y]);
	  y++;
	}
    }
  my_stranger(arr);
  return (0);
}
