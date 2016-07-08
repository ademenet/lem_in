/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:38:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/08 14:42:23 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Initialize paths array with NULL pointers.
*/

void		li_mem_zero(t_path **paths, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		paths[i] = NULL;
		i++;
	}
}

/*
** Add our new path to our paths array.
*/

t_path		**li_add_path_to_paths(t_path **paths, t_path *path)
{
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
		new_paths = (t_path**)malloc(sizeof(t_path*) * (i + 2));
		li_mem_zero(new_paths, i + 2);
		i = -1;
		while (paths[++i] != NULL)
			new_paths[i] = paths[i];
		new_paths[i] = path;
	}
	return (new_paths);
}

/*
** Initiate new path by finding min weight until the end. If no solutions,
** returns 0.
*/

int			li_create_path(t_graph *data, t_path **path)
{
	t_room		*tmp;
	t_room		*tmp_nxt;
	int			ret;

	*path = li_new_path("", 0);
	tmp = data->start;
	while ((ret = li_find_min_weight(data, tmp, &tmp_nxt)))
	{
		tmp = tmp_nxt;
		if (ret == -1)
		{
			li_del_path(path);
			break ;
		}
		li_build_path(path, tmp_nxt->name);
		if (tmp != data->end)
			tmp->weight = INT_MAX;
	}
	if (ret == 0 && path)
		li_build_path(path, data->end->name);
	return (ret);
}

/*
** Returns 1 if it finds the lowest weight room. 0 if it reachs the end.
** And -1 if there isn't rooms to visit anymore.
*/

int			li_find_min_weight(t_graph *data, t_room *room, t_room **nxt)
{
	int		i;
	int		wmin;

	i = 0;
	wmin = INT_MAX;
	while (room->tube[i] != NULL)
	{
		if (room->tube[i] == data->end)
			return (0);
		else if (room->tube[i]->weight < wmin && room->tube[i] != data->start)
		{
			wmin = room->tube[i]->weight;
			*nxt = room->tube[i];
		}
		i++;
	}
	return (wmin == INT_MAX ? -1 : 1);
}

/*
** Find every single paths and returns a pointers array with list as path.
*/

t_path		**li_find_paths(t_graph *data)
{
	t_path		**paths;
	t_path		**old_paths;
	t_path		*path;
	t_room		*room;
	int			ret;

	if (!data->start)
	{
		if (data->err == 0)
			data->err = -10;
		li_error(data);
	}
	ret = 0;
	while (li_find_min_weight(data, data->start, &room) > -1)
	{
		if (li_create_path(data, &path) == 0)
		{
			old_paths = paths;
			paths = li_add_path_to_paths(old_paths, path);
			free(old_paths);
		}
	}
	return (paths);
}
