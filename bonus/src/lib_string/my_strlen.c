/*
** my_strlen.c for my_strlen.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:52:49 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:52:50 2017 Glenn Gabriel Irakiza
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (!(str))
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}
