/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/07 15:05:57 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Here we assign weight.
*/

t_graph					*li_weight(t_graph *data)
{
		t_room			*tmp;
		int				i;

		tmp = data->end;
		tmp->weight = 0;
		i = 0;
		while ()
		{
			tmp->tube[i]->weight = tmp->weight + 1;
		}
}
