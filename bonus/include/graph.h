/*
** graph.h for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Apr 26 15:13:22 2017 Martin Van Elslande
** Last update Sun Apr 30 19:47:41 2017 Martin Van Elslande
*/

#ifndef			GRAPH_H_
# define		GRAPH_H_

# define		SCREEN_WIDTH	1080
# define		SCREEN_HEIGHT	1080

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_sprites
{
  sfSprite		**ants;
  sfSprite		**rooms;
  sfSprite		*tunnels;
  int			nb_ants;
  int			nb_rooms;
}			t_sprites;

typedef struct          s_state
{
  int                   *ant_room;
  int                   *prev_idx;
  int                   remaining;
  int                   next;
  int                   idx;
  int			tick;
  sfVector2f            **move;
}			t_state;

void			my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);

#endif			/* !GRAPH_H_ */
