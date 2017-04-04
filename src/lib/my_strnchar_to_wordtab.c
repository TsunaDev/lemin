/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/gaby/projet_Epitech/Perso/str_to_wordtab
** 
** Made by Irakiz_g
** Login   <glenn-gabriel.irakiza@epitech.eu@epitech.net>
** 
** Started on  Thu Dec 29 19:04:04 2016 Irakiz_g
** Last update Tue Apr  4 14:39:26 2017 Glenn Gabriel Irakiza
*/

#include	<stdio.h>
#include	<stdlib.h>
//#include	"my_string.h"

int		my_nb_words_env(char *str, char cmp, int i)
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

int		nb_char_in_words_env(char *str, int pos, char cmp)
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

char		**my_strnchar_to_wordtab(char *str, char cmp)
{
  char		**tab;
  int		size;
  int		i[3];

  i[0] = 0;
  i[1] = 0;
  size = my_nb_words_env(str, cmp, i[0]);
  tab = malloc(sizeof(char *) * (size + 1));
  if (tab == NULL)
    return (NULL);
  while (i[1] < size)
    {
      i[2] = 0;
      tab[i[1]] = malloc(sizeof(char) *
			 (nb_char_in_words_env(str, i[0], cmp) + 1));
      if (tab[i[1]] == NULL)
	return (NULL);
      while (str[i[0]] != cmp && str[i[0]] != '\0')
	tab[i[1]][i[2]++] = str[i[0]++];
      tab[i[1]][i[2]] = '\0';
      i[0] += 1;
      i[1]++;
    }
  tab[i[1]] = NULL;
  return (tab);
}
