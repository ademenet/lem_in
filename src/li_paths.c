/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:38:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/29 19:22:33 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_path		*li_new_path(char *name, int ant_id)
{
	DBfct
	t_path		*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->name = name;
	path->ant_id = ant_id;
	path->next = NULL;
	path->prev = NULL;
	DBfctf
	return (path);
}

void		li_add_path(t_path **list, t_path *new)
{
	DBfct
	t_path		*cur;

	if (*list && new)
	{
		cur = *list;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
		new->next = NULL;
	}
	DBfctf
}

void		li_build_path(t_path **path, char *name)
{
	DBfct
	t_path		*new;

	new = li_new_path(name, 0);
	li_add_path(path, new);
	DBfctf
}

/*
** Returns the room with the lowest weight. Otherwise if there is no solutions,
** that is to say, returns NULL.
*/

t_room		*li_find_min_weight(t_graph *data, t_room *room)
{
	int		i;
	int		wmin;
	int		err;
	t_room	*room_min;

	i = 0;
	room_min = room->tube[i];
	wmin = room->tube[i]->weight;
	err = 1;
	while (room->tube[++i] != NULL)
	{
		if (room->tube[i]->weight < wmin && room->tube[i] != data->start)
		{
			wmin = room->tube[i]->weight;
			room_min = room->tube[i];
			err++;
		}
	}
	if (li_have_explored_all_paths(data, room->tube) == 1)
		return (NULL);
	return (room_min);
}

// ATTENTION FREE *path si plus de chemins.

/*
** Initiate new path by finding min weight until the end. If no solutions,
** returns 0.
*/

int			li_create_path(t_graph *data, t_path **path)
{
	DBfct
	t_room		*tmp;

	*path = li_new_path("", 1);
	tmp = data->start;
	while (tmp->weight > 0)
	{
		if (li_have_explored_all_paths(data, tmp->tube) == 0)
			return(0);
		else
			tmp = li_find_min_weight(data, tmp);
		li_build_path(path, tmp->name);
	printf("name = %s\n", tmp->name);
		if (tmp != data->end)
			tmp->weight = INT_MAX;
	}
	DBfctf
	return (1);
}

t_path		**li_add_path_to_paths(t_path **paths, t_path *path)
{
	DBfct
	int			i;
	t_path		**new_paths;

	i = -1;
	if (paths == NULL)
	{

		new_paths = (t_path**)malloc(sizeof(t_path*) * 2);
		new_paths[0] = path;
		new_paths[1] = NULL;
	}
	else
	{
		while (paths[++i] != NULL)
			;
		new_paths = (t_path**)malloc(sizeof(t_path*) * i + 2);
		new_paths[i + 1] = NULL;
		i = -1;
		while (paths[++i] != NULL)
			new_paths[i] = paths[i];
		new_paths[i] = path;
	truc(path);
		free(paths);
	}
	DBfctf
	return (new_paths);
}

/*
** Returns 1 if there are some rooms to visit. Otherwise, returns 0. It stops
** the search for potentials unique paths.
*/

int			li_have_explored_all_paths(t_graph *data, t_room **tube)
{
	int		i;

	i = 0;
	while (tube[i] != NULL)
	{
		if (tube[i]->weight != INT_MAX && (tube[i] != data->start ||
			tube[i] != data->end))
			return (1);
	}
	return (0);
}

/*
** Find every single paths and returns a pointers array.
*/

t_path		**li_find_paths(t_graph *data)
{
	DBfct
	t_path		**paths;
	t_path		*path;
	int			ret;

	if (!data->start)
		li_error();
	ret = 0;
	while (li_have_explored_all_paths(data, data->start->tube) == 1)
	{
		if (li_create_path(data, &path))
			paths = li_add_path_to_paths(paths, path);

		sleep(1);
		printf("\n\n");
	li_display_path(paths);
		printf("\n\n");

	}
	DBfctf
	return (paths);
}
