/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/27 21:00:47 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** This function cleans rooms without any tubes.
*/

void				li_check_for_lonely_room(t_graph *data)
{
	DBfct
	t_room			*cur;
	t_room			*to_del;

	cur = data->head;
	while (cur)
	{
		if (cur->tube == NULL || cur->tube[0] == cur) // ajouter condition si cur->tube.len est = 1
		{
			if (cur->prev != NULL)
				cur->prev->next = cur->next;
			else
				cur->next->prev = NULL;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			else
				cur->prev->next = NULL;
			to_del = cur;
			cur = cur->next;
			if (data->head == to_del)
				data->head = cur;
			free(to_del);
		}
		else
			cur = cur->next;
	}
}

int					li_BFS(t_graph *data)
{
	DBfct
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
	while (data->end->next != NULL && li_weight_child(data))
	{
		li_display_initial_list(data, data->queue);

		// if (li_weight_child(data) != 1)
		// 	li_error();
		if (data->head->prev != NULL)
			data->head = data->head->prev;
		sleep(1);
	}
	return (1);
}

int					li_weight_child(t_graph *data)
{
	DBfct
	int				i;

	i = -1;
	while (data->head->tube[++i] != NULL)
	{
		if (data->head->tube[i]->weight == -1)
		{
			data->head->tube[i]->weight = data->head->weight + 1;
			if (data->head->tube[i]->next != NULL && data->head->tube[i]->prev != NULL)
			{
				data->head->tube[i]->next->prev = data->head->tube[i]->prev;
			}
			else
				data->head->tube[i]->prev->next = NULL;
			if (data->head->tube[i]->prev != NULL && data->head->tube[i]->next != NULL)
				data->head->tube[i]->prev->next = data->head->tube[i]->next;
			else
				data->head->tube[i]->prev->next = NULL;

			data->head->tube[i]->next = data->queue;
			data->queue->prev = data->head->tube[i];
			data->head->tube[i]->prev = NULL;
			data->queue = data->head->tube[i];
		}
	}
	return (1);
}
