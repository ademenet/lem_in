/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/09 14:46:15 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Here we assign weight.
*/

int					li_weight(t_graph *data, t_room *cur)
{
	int				i;

	if (cur == data->start)
		return (1);
	cur->weight = 0;
	i = 0;
	while (cur->tube[i])
	{
		cur->tube[i]->weight = cur->weight + 1;
	}
	return (0);
}

	t_room			*cur;
	cur = data->end;
