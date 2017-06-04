/*
** my_putchar.c for my_putchar.c in /home/gaby/projet_Epitech/CPE/CPE_2016_Lemin/src/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sun Apr 30 19:51:03 2017 Glenn Gabriel Irakiza
** Last update Sun Apr 30 19:51:04 2017 Glenn Gabriel Irakiza
*/

#include	<unistd.h>

void		my_putchar(int fd, char c)
{
  write(fd, &c, 1);
}
