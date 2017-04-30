/*
** my_revstr.c for my_revstr.c in /home/gaby/projet_Epitech/CPE/CPE_2016_corewar/lib/string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Wed Mar 29 13:09:27 2017 Glenn Gabriel Irakiza
** Last update Wed Mar 29 13:14:22 2017 Glenn Gabriel Irakiza
*/

#include	"my_string.h"

void		my_revstr(char *str)
{
  int		first;
  int		end;

  first = 0;
  end = (my_strlen(str) -1);
  while (first != end && end > first)
    {
      my_swap_char(&str[first], &str[end]);
      end--;
      first++;
    }
}
