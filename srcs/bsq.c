/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:13:07 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/20 18:14:04 by ubyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square_head.h"

t_short			min(t_short **map, int y, int x)
{
	t_short		a;
	t_short		b;
	t_short		c;

	a = map[y - 1][x];
	b = map[y - 1][x - 1];
	c = map[y][x - 1];
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void			find_bsq_1(t_short ***map, t_field *field, t_bsq *bsq)
{
	register int	y;
	register int	x;

	y = -1;
	while (++y < field->size_y + 1)
	{
		x = -1;
		while (++x < field->size_x + 1)
		{
			if (x == 0 || y == 0 || field->field[y - 1][x - 1] == field->o)
				(*map)[y][x] = 0;
			else
				(*map)[y][x] = min(*map, y, x) + 1;
			if ((*map)[y][x] > bsq->size)
			{
				bsq->size = (*map)[y][x];
				bsq->cord_x = x - 1;
				bsq->cord_y = y - 1;
			}
		}
	}
}

t_bsq			find_bsq(t_field *field)
{
	t_bsq			bsq;
	register int	y;
	t_short			**map;

	bsq.size = 0;
	bsq.cord_x = 0;
	bsq.cord_y = 0;
	if (!(map = malloc(sizeof(t_short*) * (field->size_y + 1))))
		return (errorbsq());
	y = -1;
	while (++y < field->size_y + 1)
		if (!(map[y] = malloc(sizeof(t_short) * (field->size_x + 1))))
			return (errorbsq());
	find_bsq_1(&map, field, &bsq);
	y = -1;
	while (++y < field->size_y + 1)
		free(map[y]);
	free(map);
	return (bsq);
}
