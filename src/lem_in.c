/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/16 14:20:39 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Check if start or end are linked to the rest of our graph.
*/

void				li_check_valid(t_graph *data)
{
	if (data->start == NULL || data->end == NULL ||
		data->start->tube == NULL || data->end->tube == NULL)
	{
		if (data->err == 0)
			data->err = -10;
		li_error(data);
	}
}

/*
** Check if start room is linked in a way or another to end room.
*/

void				li_check_linked(t_graph *data)
{
	t_room			*cur;
	int				ret;

	cur = data->queue;
	ret = 0;
	while (cur)
	{
		if (cur == data->end)
			ret++;
		else if (cur == data->start)
			ret++;
		cur = cur->next;
	}
	if (ret != 2)
	{
		if (data->err == 0)
			data->err = -10;
		li_error(data);
	}
}

int					main(int argc, char **argv)
{
	t_graph			data;
	t_path			**paths;

	paths = NULL;
	li_new_graph(&data);
	li_bonuses(argc, argv, &data);
	data = li_parsing(&data);
	li_check_valid(&data);
	li_check_for_lonely_room(&data);
	li_bfs(&data);
	li_check_linked(&data);
	if (data.start->weight == 1)
	{
		li_one_tube(&data);
		li_clean_data(&data);
	}
	else
	{
		paths = li_find_paths(&data);
		li_determine(&data, paths);
		li_clean_data(&data);
		li_clean_paths(paths);
	}
	return (0);
}
