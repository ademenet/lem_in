/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/09 18:53:32 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Here we assign weight.
*/

int					li_weight_recursive(t_graph *data, t_room *cur, int weight)
{
	static int		depth;
	int				i;

	if (cur == data->start && depth == 0)
		return (1);
	i = 0;
	while (cur->tube[i] != NULL)
	{
		li_weight_recursive(data, cur, weight + 1);
		if (cur->weight == -1)
			cur->weight = weight;

	}
	return (0);
}

int					li_weight(t_graph *data)
{
	int				weight;
	t_room			*cur;

	cur = data->end;
	cur->weight = 0;
	weight = 1;
	while (li_weight_recursive(data, cur, weight));
}
