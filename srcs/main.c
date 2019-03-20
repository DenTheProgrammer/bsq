/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:46:01 by ubyrd             #+#    #+#             */
/*   Updated: 2019/03/20 20:25:22 by ubyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square_head.h"

int				main(int argc, char **argv)
{
	t_field			field;
	t_bsq			bsq;
	int				i;

	i = 0;
	while (++i < argc || argc == 1)
	{
		if (takecheck_field(argv[i], argc, &field))
		{
			if (argc == 1)
				return (0);
			continue ;
		}
		bsq = find_bsq(&field);
		if (bsq.size == -1)
		{
			fieldfree(&field);
			continue ;
		}
		putfield(&field, &bsq);
		fieldfree(&field);
		if (argc == 1)
			return (0);
	}
	return (0);
}
