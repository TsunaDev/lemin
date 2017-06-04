/*
** sprites.c for lem-in in /home/tsuna/Epitech/projects/prog_elem/lemin/CPE_2016_Lemin/bonus
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Sun Apr 30 20:44:09 2017 Martin Van Elslande
** Last update Sun Apr 30 21:34:48 2017 Martin Van Elslande
*/

#include		<stdlib.h>
#include		<SFML/Graphics.h>
#include		"lemin.h"
#include		"graph.h"

sfSprite                *set_sprite(char *file, sfIntRect *area,
                                    sfVector2f *scale)
{
  sfSprite              *sprite;
  sfTexture             *texture;

  sprite = sfSprite_create();
  texture = sfTexture_createFromFile(file, NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  if (area)
    sfSprite_setTextureRect(sprite, *area);
  if (scale)
    sfSprite_scale(sprite, *scale);
  return (sprite);
}

void                    set_color_and_positions(t_room **rooms,
                                                sfSprite **rooms_s,
                                                int nb_rooms, int i)
{
  rooms[i]->x *= (5.0f + ((float)nb_rooms / 5.0f));
  rooms[i]->y *= (5.0f + ((float)nb_rooms / 5.0f));
  rooms[i]->x += 100.0f;
  rooms[i]->y += 100.0f;
  if (rooms[i]->new_name == 1)
    sfSprite_setColor(rooms_s[i], sfGreen);
  else if (rooms[i]->new_name == 0)
    sfSprite_setColor(rooms_s[i], sfRed);
}

int                     set_rooms_texture_and_pos(t_room **rooms,
						  sfSprite **rooms_s,
						  int nb_rooms)
{
  int                   i;
  sfVector2f            *scale;
  sfVector2f            pos;
  sfVector2f            center;

  i = 0;
  scale = malloc(sizeof(sfVector2f));
  if (!scale)
    return (84);
  scale->x = 0.1f;
  scale->y = 0.1f;
  center.x = 200.0f;
  center.y = 200.0f;
  while (i < nb_rooms)
    {
      rooms_s[i] = set_sprite("room.png", NULL, scale);
      set_color_and_positions(rooms, rooms_s, nb_rooms, i);
      sfSprite_setOrigin(rooms_s[i], center);
      pos.x = rooms[i]->x;
      pos.y = rooms[i]->y;
      sfSprite_setPosition(rooms_s[i], pos);
      i++;
    }
  return (0);
}

void                    set_ants_texture(sfSprite **ants, int nb_ants,
					 t_room **rooms)
{
  int                   i;
  sfVector2f            *scale;
  sfVector2f            pos;
  int                   start;
  sfVector2f            center;

  i = 0;
  start = get_actual_room(0, rooms);
  scale = malloc(sizeof(sfVector2f));
  pos.x = rooms[start]->x;
  pos.y = rooms[start]->y;
  scale->x = 0.06f;
  scale->y = 0.06f;
  center.x = 212.5f;
  center.y = 300.0f;
  while (i < nb_ants)
    {
      ants[i] = set_sprite("ant.png", NULL, scale);
      sfSprite_setRotation(ants[i], 0);
      sfSprite_setPosition(ants[i], pos);
      sfSprite_setOrigin(ants[i], center);
      i++;
    }
}

void                    set_tunnels(t_my_framebuffer *framebuffer,
                                    t_room **rooms, t_sprites *sprites,
                                    int **tun_array)
{
  int                   i;
  int                   idx1;
  int                   idx2;
  sfVector2i            pos_a;
  sfVector2i            pos_b;
  sfTexture             *texture;

  i = 1;
  sprites->tunnels = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprites->tunnels, texture, sfTrue);
  while (i < tun_array[0][0] + 1)
    {
      idx1 = get_actual_room(tun_array[i][0], rooms);
      idx2 = get_actual_room(tun_array[i][1], rooms);
      pos_a.x = rooms[idx1]->x;
      pos_a.y = rooms[idx1]->y;
      pos_b.x = rooms[idx2]->x;
      pos_b.y = rooms[idx2]->y;
      my_draw_line(framebuffer, pos_a, pos_b, sfRed);
      i++;
    }
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}
