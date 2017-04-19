/*
** valid_file.c for valid_file.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Tue Apr 18 08:49:42 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 20:40:58 2017 Anaïs Breant
*/

#include	"check_file.h"
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

static int	my_connect_valid(char *str)
{
  char		**connect;
  int		isnum;
  int		y;

  y = 0;
  connect = my_strnchar_to_wordtab(str, '-');
  while (connect[y] != NULL)
    {
      isnum = my_isnum(connect[y]);
      if (isnum != 0)
	{
	  my_free_array(connect);
	  return (1);
	}
      y++;
    }
  my_free_array(connect);
  return (0);
}

static int	pos_error_connect_room(char **arr)
{
  int		y;
  int		err;
  int		nb_words;

  y = 0;
  err = 0;
  while (arr[y] != NULL)
    {
      nb_words = my_nb_words_char(arr[y], '-', 0);
      if (nb_words == 2)
	{
	  err = my_connect_valid(arr[y]);
	  if (err == 1)
	    return (y);
	}
      nb_words = my_nb_words_char(arr[y], ' ', 0);
      y++;
    }
  return (-1);
}

static int	pos_error_room(char **arr)
{
  int		nb_words;
  int		rt;
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
      nb_words = my_nb_words_char(arr[y], '-', 0);
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
