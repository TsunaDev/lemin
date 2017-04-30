/*
** graph.h for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Apr 26 15:13:22 2017 Martin Van Elslande
** Last update Sun Apr 30 21:33:10 2017 Martin Van Elslande
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

void			stop_ant(t_state *, int);
void			set_scale(sfVector2f *, float, float);
void			set_ants_texture(sfSprite **, int, t_room **);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			my_draw_line(t_my_framebuffer *, sfVector2i,
				     sfVector2i, sfColor);
void			set_tunnels(t_my_framebuffer *, t_room **,
				    t_sprites *, int **);

int			init_state(t_state *, int);
int			count_rooms(t_room **);
int			set_rooms_texture_and_pos(t_room **, sfSprite **,
						  int);

sfSprite		*set_sprite(char *, sfIntRect *, sfVector2f *);
sfRenderWindow		*window_open(int, int);

t_my_framebuffer	*my_framebuffer_create(int, int);

#endif			/* !GRAPH_H_ */
