/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/04 14:18:22 by alain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_display_debug(t_graph *data, t_room *start)
{
	// DBfct
	t_room 			*tmp;

	tmp = start;
	while (tmp)
	{
		printf("name: %10s, weight: %5d\n", tmp->name, tmp->weight);
		// sleep(1);
		tmp = tmp->next;
	}
}

void				li_display_initial_list(t_graph *data, t_room *start)
{
	t_room 			*tmp;

	tmp = start;
	while (tmp)
	{
		printf("[%5s]", tmp->name);
		if (tmp->next != NULL)
			printf(">");
		tmp = tmp->next;
	}
	printf("\n");
}

void truc(t_path *path) {
	t_path *f = path;
	printf("=============\n");
	while (f)
	{
		printf("name: %8s | ant_id: %2d\n", f->name, f->ant_id);
		f = f->next;
	}
	printf("=============\n");
}

void				li_display_path(t_path **path)
{
	t_path			*f;
	int				i;

	i = 0;
	f = path[i];
	while (path[i] != NULL)
	{
		printf("------------\nChemin %d\n------------\n", i);
		f = path[i];
		while (f)
		{
			printf("name: %8s | ant_id: %2d\n", f->name, f->ant_id);
			f = f->next;
		}
		i++;
		// sleep(1);
	}
}

void				li_check_valid(t_graph *data)
{
	if (data->start == NULL || data->end == NULL ||
		data->start->tube == NULL || data->end->tube == NULL)
		li_error();
}

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
		li_error();
}

// Yaura un malloc pour data
int					main(void)
{
	t_graph			data;
	t_path			**paths;

	paths = NULL;
	li_new_graph(&data);
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
	// while (1);
	return (0);
}
