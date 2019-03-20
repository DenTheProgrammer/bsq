/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_head.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:22:24 by ubyrd             #+#    #+#             */
/*   Updated: 2019/03/20 20:33:43 by ubyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_HEAD_H
# define SQUARE_HEAD_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define ERR_MAP "map error\n"

# define BUF_SIZE 1310720

typedef struct			s_field
{
	char	**field;
	int		size_x;
	int		size_y;
	char	e;
	char	o;
	char	f;
}						t_field;

typedef struct			s_bsq
{
	int		size;
	int		cord_x;
	int		cord_y;
}						t_bsq;

typedef unsigned short	t_short;

/*
** utils.c
*/
void					ft_putchar(char c);
int						ft_strlen(char *str, char sep);
int						ft_regnum(int num);
int						ft_atoi(char *str);
void					fieldfree(t_field *field);

/*
** taketab.c
*/
int						take_info(char *buf, t_field *field);
int						check_field_stdin(char *buf, t_field *fild);
int						check_field(int f, t_field *fild);
int						takecheck_field_stdin(t_field *field, char *buf);
int						takecheck_field(char *file, int argc, t_field *field);

/*
** putin.c
*/
t_bsq					errorbsq(void);
int						errormap(void);
void					putfield(t_field *field, t_bsq *bsq);

/*
** bsq.c
*/
t_short					min(t_short **map, int y, int x);
void					find_bsq_1(t_short ***map, t_field *field, t_bsq *bsq);
t_bsq					find_bsq(t_field *field);

#endif
