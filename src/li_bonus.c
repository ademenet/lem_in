/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 14:19:07 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/18 15:19:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** "Hey! You are doing wrong. Let me help you."
*/

void				li_bonus_error(void)
{
	ft_printf("Sypnosis: ./lem-in [-v -c -s] < [some maps]\n");
	ft_printf("\t[-v] for verbose error mode,\n\t[-s] for turns count,\n\t");
	ft_printf("[-c] for colors.\n");
}

/*
** Manage which bonus to display.
*/

void				li_bonuses_management(t_graph *data, char arg)
{
	if (arg == 'v')
		data->bonus[0] = 1;
	else if (arg == 'c')
		data->bonus[1] = 1;
	else if (arg == 's')
		data->bonus[2] = 1;
}

/*
** Display bonus or alert message.
*/

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
				li_bonus_error();
			i--;
		}
	}
}

/*
** Display statistics.
*/

void				li_display_stats(t_graph *data)
{
	static char		*pluriel = "ont";
	static char		*singulier = "a";
	char			*verb;

	if (data->ant <= 1)
		verb = singulier;
	else
		verb = pluriel;
	ft_printf("\033[1m%d\033[0m fourmis %s atteint la salle ", data->ant, verb);
	ft_printf("\033[1m%s\033[0m en ", data->end->name);
	ft_printf("\033[1m%d\033[0m tours.\n", data->plays - 1);
}
