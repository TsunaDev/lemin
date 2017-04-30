/*
** window.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin/bonus
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr 30 20:37:16 2017 Martin Van Elslande
** Last update Sun Apr 30 22:16:11 2017 Martin Van Elslande
*/

#include		<stdlib.h>
#include		<SFML/Graphics.h>
#include		"lemin.h"
#include		"graph.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  int                   i;
  t_my_framebuffer      *framebuffer;

  i = 0;
  framebuffer = malloc(sizeof(t_my_framebuffer));
  if (!framebuffer)
    return (NULL);
  framebuffer->width = width;
  framebuffer->height = height;
  framebuffer->pixels = malloc(width * height * 4 *
			       sizeof(framebuffer->pixels));
  if (!framebuffer->pixels)
    return (NULL);
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (framebuffer);
}

sfRenderWindow          *window_open(int width, int height)
{
  sfVideoMode           mode;
  sfRenderWindow*       window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "Lem-in",
                                 sfResize | sfClose, NULL);
  if (!window)
    return (NULL);
  return (window);
}
