/*
** my_putnbr.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Apr 29 16:33:18 2017 Martin Van Elslande
** Last update Sun Apr 30 22:18:59 2017 Martin Van Elslande
*/

#include	<unistd.h>
#include	"my_string.h"

int	digits(int nb)
{
  if (nb > 9)
    {
      digits(nb / 10);
      my_putchar(1, nb % 10 + 48);
    }
  else
    my_putchar(1, nb + 48);
  return (0);
}

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar(1, 45);
      nb = nb * (-1);
    }
  digits(nb);
  return (0);
}
