/*
** my_draw_line.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin/bonus
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr 30 03:04:52 2017 Martin Van Elslande
** Last update Sun Apr 30 03:43:37 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	"graph.h"

void	my_draw_line_2(t_my_framebuffer *framebuffer, int *arr, sfColor color)
{
  int	stock;
  int	i;

  i = 1;
  stock = arr[3] / 2;
  while (i <= arr[3])
    {
      arr[1] += arr[5];
      stock += arr[2];
      if (stock > arr[3])
	{
	  stock -= arr[3];
	  arr[0] += arr[4];
	}
      my_put_pixel(framebuffer, arr[0], arr[1], color);
      i++;
    }
}

void	my_draw_line_1(t_my_framebuffer *framebuffer, int *arr, sfColor color)
{
  int	i;
  int	stock;

  i = 1;
  stock = arr[2] / 2;
  while (i <= arr[2])
    {
      arr[0] += arr[4];
      stock += arr[3];
      if (stock > arr[2])
	{
	  stock -= arr[2];
	  arr[1] += arr[5];
	}
      my_put_pixel(framebuffer, arr[0], arr[1], color);
      i++;
    }
}

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int   arr[6];

  if (from.x < framebuffer->width && from.y < framebuffer-> height &&
      to.x < framebuffer->width && to.y < framebuffer-> height)
    {
      arr[0] = from.x;
      arr[1] = from.y;
      arr[2] = to.x - from.x;
      arr[3] = to.y - from.y;
      arr[4] = (arr[2] > 0) ? 1 : (-1);
      arr[5] = (arr[3] > 0) ? 1 : (-1);
      if (arr[2] < 0)
	arr[2] *= (-1);
      if (arr[3] < 0)
	arr[3] *= (-1);
      my_put_pixel(framebuffer, arr[0], arr[1], color);
      if (arr[2] > arr[3])
	my_draw_line_1(framebuffer, arr, color);
      else
	my_draw_line_2(framebuffer, arr, color);
    }
}
