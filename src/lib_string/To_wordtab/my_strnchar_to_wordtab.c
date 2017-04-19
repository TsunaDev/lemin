/*
** my_strnchar_to_wordtab.c for my_strnchar_to_wordtab.c in /home/gaby/projet_Epitech/PSU/minishell2/PSU_2016_minishell2
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Wed Apr  5 16:13:59 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 12:27:19 2017 Glenn Gabriel Irakiza
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my_string.h"

int		my_nb_words_char(char *str, char cmp, int i)
{
  int		b;

  b = 0;
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

static void	my_epur_tab(char ***arr)
{
  char		*tmp;
  int		y;

  y = 0;
  while ((*arr)[y] != NULL)
    {
      tmp = my_epur_str((*arr)[y]);
      if (tmp == NULL)
	exit (84);
      free((*arr)[y]);
      (*arr)[y] = tmp;
      y++;
    }
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
	exit(84);
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
    exit(84);
  tab = my_tab_create(tab, str, cmp, size);
  my_epur_tab(&tab);
  return (tab);
}
