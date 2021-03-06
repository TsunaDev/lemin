/*
** my_strnchar_to_wordtab.c for my_strnchar_to_wordtab.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string/To_wordtab
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:55:36 2017 Glenn Gabriel Irakiza
** Last update Tue May  2 11:57:28 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>
#include	"my_string.h"

int		my_nb_words_char(char *str, char cmp, int i)
{
  int		b;

  b = 0;
  if (str == NULL)
    return (0);
  if (str[0] != cmp)
    b += 1;
  while (str[i] != '\0')
    {
      if (str[i] == cmp)
	b++;
      i++;
    }
  return (b);
}

static int	nb_char_in_words_env(char *str, int pos, char cmp)
{
  int		i;
  int		b;

  i = pos;
  b = 0;
  while (str[i] != cmp && str[i] != '\0')
    {
      b++;
      i++;
    }
  return (b);
}

int		my_epur_tab(char ***arr)
{
  char		*tmp;
  int		y;
  int		i;
  int		len;

  y = 0;
  i = 0;
  while ((*arr)[y] != NULL)
    {
      tmp = my_epur_str((*arr)[y]);
      if (tmp == NULL)
	return (84);
      len = my_strlen((*arr)[y]);
      if (len != 0)
	{
	  (*arr)[i] = tmp;
	  i++;
	}
      y++;
    }
  (*arr)[i] = NULL;
  return (0);
}

static char	**my_tab_create(char **tab, char *str, char cmp, int size)
{
  int		x;
  int		y;
  int		i;

  y = 0;
  i = 0;
  while (y < size)
    {
      x = 0;
      tab[y] = malloc(sizeof(char) *
		      (nb_char_in_words_env(str, i, cmp) + 1));
      if (tab[y] == NULL)
	return (NULL);
      while (str[i] != cmp && str[i] != '\0')
	tab[y][x++] = str[i++];
      tab[y][x] = '\0';
      i += 1;
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

char		**my_strnchar_to_wordtab(char *str, char cmp)
{
  char		**tab;
  int		size;

  tab = NULL;
  if (str == NULL)
    return (NULL);
  size = my_nb_words_char(str, cmp, 0);
  tab = malloc(sizeof(char *) * (size + 1));
  if (tab == NULL)
    return (NULL);
  tab = my_tab_create(tab, str, cmp, size);
  my_epur_tab(&tab);
  return (tab);
}
