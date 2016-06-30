/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/30 11:14:04 by ademenet         ###   ########.fr       */
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
	while (f)
	{
		printf("name: %8s | ant_id: %2d\n", f->name, f->ant_id);
		f = f->next;
	}
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
			printf("%s\n", f->name);
			printf("name: %8s | ant_id: %2d\n", f->name, f->ant_id);
			f = f->next;
		}
		i++;
		sleep(1);
	}
}

int					li_check_valid(t_graph *data)
{
	if (data->start == NULL || data->end == NULL ||
		data->start->tube == NULL || data->end->tube == NULL)
		return (1);
	return (0);
}

// Yaura un malloc pour data
int					main(void)
{
	t_graph			data;
	t_path			**paths;

	paths = NULL;
	li_new_graph(&data);
	data = li_parsing(&data);
	if (li_check_valid(&data))
		li_error();
	li_check_for_lonely_room(&data);
	li_bfs(&data);
	if (data.start->weight == 1)
		li_one_tube(&data);
	else
		paths = li_find_paths(&data);
	li_display_path(paths);
	// li_display(paths, data.ant);
	// li_clean_everything(&data, shpath);
	// while (1);
	return (0);
}
