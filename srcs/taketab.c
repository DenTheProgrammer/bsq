/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taketab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:29:27 by ubyrd             #+#    #+#             */
/*   Updated: 2019/03/20 20:23:05 by ubyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square_head.h"

int				take_info(char *buf, t_field *field)
{
	int		i;

	i = ft_strlen(buf, '\n');
	if (i < 4)
		return (1);
	field->e = buf[i - 3];
	if ((field->o = buf[i - 2]) == field->e)
		return (1);
	field->f = buf[i - 1];
	if (field->f == field->e || field->f == field->o)
		return (1);
	buf[i - 3] = '\0';
	if ((field->size_y = ft_atoi(buf)) <= 0)
		return (1);
	if (ft_strlen(buf, '\0') != ft_regnum(field->size_y))
		return (1);
	if ((field->size_x = ft_strlen(&buf[i + 1], '\n')) <= 0)
		return (1);
	return (i + 1);
}

int				check_field_stdin(char *buf, t_field *fild)
{
	register int	i;
	register int	j;
	register int	k;

	i = -1;
	k = 0;
	while (++i < fild->size_y)
	{
		if (!(fild->field[i] = malloc(sizeof(int) * (fild->size_x + 2))))
			return (1);
		j = 0;
		while (buf[k] && j < fild->size_x)
		{
			fild->field[i][j++] = buf[k++];
			if (fild->field[i][j - 1] != fild->e && fild->field[i][j - 1] != fild->o)
				return (1);
		}
		fild->field[i][j] = buf[k++];
		if (fild->field[i][j] != '\n')
			return (1);
		fild->field[i][j++] = '\0';
	}
	if (i != fild->size_y || buf[k])
		return (1);
	fild->field[i] = NULL;
	return (0);
}

int				check_field(int f, t_field *fild)
{
	register int	i;
	register int	j;
	char			buf;

	i = -1;
	while (++i < fild->size_y)
	{
		if (!(fild->field[i] = malloc(sizeof(int) * (fild->size_x + 2))))
			return (1);
		if (read(f, fild->field[i], fild->size_x + 1) != fild->size_x + 1)
			return (1);
		j = -1;
		while (++j < fild->size_x)
			if (fild->field[i][j] != fild->e && fild->field[i][j] != fild->o)
				return (1);
		if (fild->field[i][j] != '\n')
			return (1);
		fild->field[i][j] = '\0';
	}
	if (i != fild->size_y || read(f, &buf, fild->size_x + 1) > 0)
		return (1);
	fild->field[i] = NULL;
	return (0);
}

int				takecheck_field_stdin(t_field *field, char *buf)
{
	register int	i;
	register int	j;

	i = 0;
	j = 1;
	while (j != 0)
	{
		j = read(0, &buf[i], BUF_SIZE);
		i = i + j;
	}
	if ((i = take_info(buf, field)) < 2)
		return (1);
	if (!(field->field = malloc(sizeof(int*) * (field->size_y + 2))))
		return (1);
	if (check_field_stdin(&buf[i], field))
		return (1);
	return (0);
}

int				takecheck_field(char *file, int argc, t_field *field)
{
	int		f;
	char	buf[BUF_SIZE];
	int		i;

	field->field = NULL;
	if (argc == 1)
	{
		if (takecheck_field_stdin(field, buf))
			return (errormap());
	}
	else
	{
		if ((f = open(file, O_RDONLY)) == -1 || (read(f, buf, BUF_SIZE)) < -1)
			return (errormap());
		if ((i = take_info(buf, field)) < 2)
			return (errormap());
		if (close(f) == -1 || (f = open(file, O_RDONLY)) == -1
			|| (read(f, buf, i)) < -1)
			return (errormap());
		if (!(field->field = malloc(sizeof(int*) * (field->size_y + 2))))
			return (errormap());
		if (check_field(f, field) || close(f) == -1)
			return (errormap());
	}
	return (0);
}
