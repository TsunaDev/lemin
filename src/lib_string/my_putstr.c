/*
** my_putstr.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sat Apr 29 16:33:33 2017 Martin Van Elslande
** Last update Sun Apr 30 22:18:46 2017 Martin Van Elslande
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"my_string.h"

int		my_putstr(int out, char *str, ...)
{
  va_list	ap;
  int		i;
  char		*arg;

  va_start(ap, str);
  i = 0;
  while (str[i])
    {
      if (match("%d*", &str[i]))
	{
	  my_putnbr(va_arg(ap, int));
	  i++;
	}
      else if (match("%s*", &str[i]))
	{
	  arg = va_arg(ap, char *);
	  write(out, arg, my_strlen(arg));
	  i++;
	}
      else
	write(out, &str[i], 1);
      i++;
    }
  return ((out == 2) ? 84 : 0);
}
