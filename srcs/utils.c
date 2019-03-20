/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:44:30 by ubyrd             #+#    #+#             */
/*   Updated: 2019/03/20 16:32:14 by ubyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square_head.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				ft_strlen(char *str, char sep)
{
	int		i;

	i = 0;
	while (str[i] != sep)
		i++;
	return (i);
}

int				ft_regnum(int num)
{
	int		i;
	int		mult;

	mult = 10;
	i = 1;
	while (num / mult != 0)
	{
		mult *= 10;
		i++;
	}
	return (i);
}

int				ft_atoi(char *str)
{
	int		i;
	int		num;
	int		sign;

	if (str == '\0')
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = (10 * num) + (str[i++] - '0');
	return (num * sign);
}

void			fieldfree(t_field *field)
{
	register int	j;

	if (!field || !field->field)
		return ;
	j = 0;
	while (field->field[j] && j < field->size_y + 1)
		free(field->field[j++]);
	free(field->field);
}
