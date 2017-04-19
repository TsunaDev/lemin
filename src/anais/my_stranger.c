/*
** my_stranger.c for my_srtanger.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/anais
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Wed Apr 19 13:25:26 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 14:15:30 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

int		stranger_room(char **arr, char c, int limit, int y)
{
  int		cmp[2];
  int		nb_words;

  cmp[0] = 1;
  cmp[1] = 1;
  while (arr[y] != NULL)
    {
      if (arr[y][0] != '\0')
	{
	  nb_words = my_nb_words_char(arr[y], c, 0);
	  if (c == ' ')
	    {
	      cmp[0] = my_strcmp(arr[y], "##start");
	      cmp[1] = my_strcmp(arr[y], "##end");
	    }
	  if (nb_words != limit && cmp[0] != 0 && cmp[1] != 0)
	    return (y);
	}
      y++;
    }
  return (-1);
}

void		my_stranger(char **arr)
{
  int		y;

  y = stranger_room(arr, ' ', 3, 1);
  if (y == -1)
    return ;
  y = stranger_room(arr, '-', 2, y);
  if (y == -1)
    return ;
  printf("2 : %s - %d\n", arr[y], y);
}
