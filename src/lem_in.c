/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/06 17:59:20 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

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
	t_room			*tmp;
	tmp = data.head;
	while (tmp)
	{
		fprintf(stderr, "%s\n", tmp->name);
		tmp = tmp->next;
	}
	fprintf(stderr, "start == %s\n", data.start->name);
	fprintf(stderr, "end == %s\n", data.end->name);
	return (0);
}
