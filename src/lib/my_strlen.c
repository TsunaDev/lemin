/*
** my_strlen.c for my_strlen.c in /home/gaby/projet_Epitech/CPE/CPE_2016_corewar/asm_corewar/lib_string
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Sat Mar 25 16:36:59 2017 Glenn Gabriel Irakiza
** Last update Tue Apr  4 17:17:55 2017 anaisbrnt
*/

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
