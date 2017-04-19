/*
** my_string.h for my_string.h in /home/gaby/projet_Epitech/PSU/PSU_2016_tetris/include
**
** Made by Glenn Gabriel Irakiza
** Login   <glenn-gabriel.irakiza@epitech.eu>
**
** Started on  Sun Mar 12 12:04:03 2017 Glenn Gabriel Irakiza
** Last update Wed Apr 19 18:35:16 2017 Glenn Gabriel Irakiza
*/

#ifndef	MY_STRING_H_
# define MY_STRING_H_

# include	<stdlib.h>

void		my_swap_char(char *, char *);
void		my_putchar(int, char);
void		my_free_array(char **);
void		my_showtab(char **);
void		my_revstr(char *);
void		my_putstr(int, char *);

char		*get_next_line(int);
char		*my_epur_str(char *);
char		*my_epurnchar_str(char *, char);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
char		*my_strncpy(char *, char *, int);
char		*my_strndup(char *, int);
char		*my_strndup_end_free(char *, int, int);
char		*my_strndup_end(char *, int, int);
char		*my_cpyname(char *);
char		*my_strcat(char *, char *, int);
char		*to_wordtab_to_str(char **, int, int);

char		**my_tab_cpy(char **);
char		**my_strnchar_to_wordtab(char *, char);
char		**my_str_to_wordtab(char *);
char		**my_str_to_wordtab_hyphen(char *);

int		my_strlen_char(char **);
int		my_strlen_tab(char **);
int		my_nb_words(char *);
int		my_nb_words_char(char *, char, int);
int		my_strlen(char *);
int		my_strncmp_name(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_strcmp(char *, char *);
int		my_isnum(char *);
int		my_getnbr(char *);

# endif /* !MY_STRING_H_ */
