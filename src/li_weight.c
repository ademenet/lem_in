/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/04 16:26:00 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** This function cleans rooms without any tubes.
*/

static void			li_check_for_lonely_room2(t_room *cur)
{
	if (cur->prev != NULL)
		cur->prev->next = cur->next;
	else
		cur->next->prev = NULL;
	if (cur->next != NULL)
		cur->next->prev = cur->prev;
	else
		cur->prev->next = NULL;
}

/*
** Check for rooms that are not connected with the others then delete them
** with li_clean_one_elem.
*/

void				li_check_for_lonely_room(t_graph *data)
{
	t_room			*cur;
	t_room			*to_del;

	cur = data->head;
	while (cur)
	{
		if (cur->tube == NULL)
		{
			li_check_for_lonely_room2(cur);
			to_del = cur;
			cur = cur->next;
			if (data->head == to_del)
				data->head = cur;
			li_clean_one_elem(to_del);
		}
		else
			cur = cur->next;
	}
}

/*
** Sometimes, several rooms are not part of the graph (including start room),
** so we clean them.
*/

void				li_kill_those_separatists(t_graph *data)
{
	t_room			*cur;
	t_room			*to_del;

	cur = data->end->next;
	data->end->next = NULL;
	while (cur)
	{
		to_del = cur;
		if (to_del == data->start)
			data->start = NULL;
		cur = cur->next;
		li_clean_one_elem(to_del);
	}
}

/*
** First part of weight assigning function to child rooms.
*/

int					li_weight_child(t_graph *data)
{
	if (data->head != NULL)
	{
		li_weight_child2(data);
		return (1);
	}
	return (-1);
}

/*
** The main function for our breadth first search.
*/

int					li_bfs(t_graph *data)
{
	data->end->weight = 0;
	if (data->head != data->end)
	{
		if (data->end->prev != NULL)
			data->end->prev->next = data->end->next;
		if (data->end->next != NULL)
			data->end->next->prev = data->end->prev;
		data->end->next = data->head;
		data->end->prev = NULL;
		data->head->prev = data->end;
		data->head = data->end;
	}
	data->queue = data->end;
	while (data->end->next != NULL)
	{
		if (li_weight_child(data) == -1)
			li_kill_those_separatists(data);
		if (data->head != NULL)
			data->head = data->head->prev;
	}
	return (1);
}
