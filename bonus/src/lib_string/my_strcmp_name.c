/*
** my_strcmp_name.c for my_strcmp_name.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:52:18 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:52:19 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

int		my_strcmp_name(char *dest, char *src)
{
  int		b;
  int		i;

  b = 0;
  i = my_strlen(dest) - 1;
  my_revstr(src);
  if (dest == NULL)
    return (-1);
  while (src[b] != '\0')
    {
      if (src[b] < dest[i])
	return (-1);
      if (src[b] > dest[i])
	return (2);
      if (src[b] == dest[i])
	{
	  b++;
	  i--;
	}
    }
  my_revstr(src);
  return (0);
}
