/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:19:36 by ubyrd             #+#    #+#             */
/*   Updated: 2019/03/20 16:35:25 by ubyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square_head.h"

t_bsq			errorbsq(void)
{
	t_bsq		err;

	err.size = -1;
	write(2, ERR_MAP, 10);
	return (err);
}

int				errormap(void)
{
	write(2, ERR_MAP, 10);
	return (1);
}

void			putfield(t_field *field, t_bsq *bsq)
{
	int		y;
	int		x;

	y = 0;
	while (y < field->size_y)
	{
		x = 0;
		while (x < field->size_x)
		{
			if (y <= bsq->cord_y && y > bsq->cord_y - bsq->size
				&& x <= bsq->cord_x && x > bsq->cord_x - bsq->size)
				ft_putchar(field->f);
			else
				ft_putchar(field->field[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
