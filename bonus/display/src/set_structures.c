/*
** set_structures.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin/bonus
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr 30 21:23:16 2017 Martin Van Elslande
** Last update Sun Apr 30 21:31:03 2017 Martin Van Elslande
*/

#include	<SFML/Graphics.h>
#include	"lemin.h"
#include	"graph.h"

void		stop_ant(t_state *state, int i)
{
  state->move[i]->x = 0;
  state->move[i]->y = 0;
}

void		set_scale(sfVector2f *scale, float x, float y)
{
  scale->x = x;
  scale->y = y;
}

