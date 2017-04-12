/*
** my_putchar.c for my_putchar.c in /home/gaby/projet_Epitech/CPE/CPE_2016_corewar/asm_corewar/lib_string
** 
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
** 
** Started on  Sat Mar 25 16:44:09 2017 Glenn Gabriel Irakiza
** Last update Sat Mar 25 16:44:57 2017 Glenn Gabriel Irakiza
*/

#include	<unistd.h>

void		my_putchar(int fd, char c)
{
  write(fd, &c, 1);
}
