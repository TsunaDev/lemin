/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/gaby/projet_Epitech/Perso/str_to_wordtab
** 
** Made by Irakiz_g
** Login   <glenn-gabriel.irakiza@epitech.eu@epitech.net>
** 
** Started on  Thu Dec 29 19:04:04 2016 Irakiz_g
** Last update Sun Apr  9 20:32:27 2017 Glenn Gabriel Irakiza
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my_string.h"

int		my_nb_words(char *str)
{
  int		i;
  int		b;

  i = 0;
  b = 0;
  if (str == NULL)
    return (0);
  while (str[i] == ' ' || str[i] == '\t')
    i += 1;
  if (str[0] != ' ')
    b += 1;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	if (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')
	  b++;
      i++;
    }
  return (b);
}

static int	my_nb_char(char *str, int pos)
{
  int		i;
  int		b;

  i = pos;
  b = 0;
  while ((str[i] != ' ' || str[i] != '\t') && str[i] != '\0')
    {
      b++;
      i++;
    }
  return (b);
}

static int	my_cpy(char *src, char *epur, int i)
{
  int		x;

  x = 0;
  while (epur[i] == ' ' || epur[i] == '\t')
    i += 1;
  while (epur[i] != ' ' && epur[i] != '\t' && epur[i] != '\0')
    {
      src[x] = epur[i];
      x++;
      i++;
    }
  src[x] = '\0';
  i += 1;
  return (i);
}

static char	**my_tab_create(int nb_words, char **tab, char *epur)
{
  int		nb_char;
  int		i;
  int		y;

  y = 0;
  i = 0;
  while (y < nb_words)
    {
      nb_char = my_nb_char(epur, i) + 1;
      tab[y] = malloc(sizeof(char) * nb_char);
      if (tab[y] == NULL)
	exit(84);
      i = my_cpy(tab[y], epur, i);
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  char		*epur;
  int		nb_words;

  epur = my_epur_str(str);
  nb_words = my_nb_words(epur);
  if (nb_words == 0 || epur == NULL)
    return (NULL);
  tab = malloc(sizeof(char *) * (nb_words + 2));
  if (tab == NULL)
    exit(84);
  tab = my_tab_create(nb_words, tab, epur);
  free(epur);
  return (tab);
}
