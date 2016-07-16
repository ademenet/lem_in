/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:19:07 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/16 14:27:25 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Display all the unique paths that we found.
*/

void				li_display_path(t_path **path)
{
	t_path			*f;
	int				i;

	i = 0;
	f = path[i];
	while (path[i] != NULL)
	{
		ft_printf("------------\nChemin %d\n------------\n", i);
		f = path[i];
		while (f)
		{
			ft_printf("name: %8s | ant_id: %2d\n", f->name, f->ant_id);
			f = f->next;
		}
		i++;
	}
}

void				li_bonuses_management(t_graph *data, char arg)
{
	if (arg == 'v')
		data->bonus[0] = 1;
	else if (arg == 'c')
		data->bonus[1] = 1;
	else if (arg == 's')
		data->bonus[2] = 1;
}

void				li_bonuses(int argc, char **argv, t_graph *data)
{
	int				i;
	int				j;

	if (argc > 1)
	{
		i = argc - 1;
		while (i > 0)
		{
			j = -1;
			if (argv[i][0] == '-')
			{
				while (argv[i][++j] != '\0')
					li_bonuses_management(data, argv[i][j]);
			}
			else
				ft_printf("Wrong arguments for bonuses, use: -v, -c or -s.\n");
			i--;
		}
	}
}

/*
** Display statistics.
*/

void				li_display_stats(t_graph *data)
{
	ft_printf("\033[1m%d\033[0m fourmis ont atteint la salle ", data->ant);
	ft_printf("##end en \033[1m%d\033[0m tours.\n", data->plays);
}
