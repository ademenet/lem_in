/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/27 15:14:29 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_display_debug(t_graph *data)
{
	t_room 			*tmp;

	tmp = data->queue;
	printf("----------------\n");
	while (tmp)
	{
		printf("name: %10s, weight: %5d\n", tmp->name, tmp->weight);
		tmp = tmp->next;
	}
}

int					li_check_valid(t_graph *data)
{
	if (data->start == NULL || data->end == NULL)
		return (1);
	return (0);
}

// Yaura un malloc pour data
int					main(void)
{
	t_graph			data;

	li_new_graph(&data);
	data = li_parsing(&data);
	if (li_check_valid(&data))
		li_error();
	li_check_for_lonely_room(&data);
	li_BFS(&data);
	li_display_debug(&data);
	return (0);
}
