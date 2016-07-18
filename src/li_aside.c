/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_aside.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:40:15 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/18 15:12:37 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_weight_child2(t_graph *data)
{
	int				i;

	i = -1;
	while (data->head->tube[++i] != NULL)
	{
		if (data->head->tube[i]->weight == -1)
		{
			data->head->tube[i]->weight = data->head->weight + 1;
			if (data->head->tube[i]->next != NULL &&
				data->head->tube[i]->prev != NULL)
				data->head->tube[i]->next->prev = data->head->tube[i]->prev;
			else
				data->head->tube[i]->prev->next = NULL;
			if (data->head->tube[i]->prev != NULL &&
				data->head->tube[i]->next != NULL)
				data->head->tube[i]->prev->next = data->head->tube[i]->next;
			else
				data->head->tube[i]->prev->next = NULL;
			data->head->tube[i]->next = data->queue;
			data->queue->prev = data->head->tube[i];
			data->head->tube[i]->prev = NULL;
			data->queue = data->head->tube[i];
		}
	}
}

void				li_one_tube(t_graph *data)
{
	int				ant;

	ant = 1;
	while (ant <= data->ant)
	{
		li_display2(data, ant, data->end->name);
		ant++;
	}
	ft_printf("\n");
	if (data->bonus[2] == 1)
	{
		data->plays = 2;
		li_display_stats(data);
	}
}

int					li_path_len(t_path *path)
{
	int				len;

	len = 0;
	while (path)
	{
		len++;
		path = path->next;
	}
	return (0);
}

int					li_array_len(void **tab)
{
	int				len;

	len = -1;
	while (tab[++len] != NULL)
		;
	return (len);
}
