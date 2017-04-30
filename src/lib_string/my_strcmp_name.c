/*
** my_strcmp_name.c for my_strcmp_name.c in /home/gaby/projet_Epitech/CPE/CPE_2016_corewar/asm/parsing
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Wed Mar 29 13:17:33 2017 Glenn Gabriel Irakiza
** Last update Wed Mar 29 13:19:15 2017 Glenn Gabriel Irakiza
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
