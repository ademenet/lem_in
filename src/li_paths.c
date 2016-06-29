/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:38:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/29 11:43:37 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_path				*li_new_path(char *name, int ant_id)
{
	// DBfct
	t_path			*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->name = name;
	path->ant_id = ant_id;
	path->next = NULL;
	path->prev = NULL;
	return (path);
}

void			li_add_path(t_path *list, t_path *new)
{
	// DBfct
	t_path		*cur;

	if (list && new)
	{
		cur = list;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
		new->next = NULL;
	}
}

t_path				*li_build_path(t_path *path, char *name)
{
	// DBfct
	t_path			*new;

	new = li_new_path(name, 0);
	li_add_path(path, new);
	return (path);
}

t_path				*li_find_path(t_graph *data)
{
	// DBfct
	int				i;
	int				w;
	t_room			*tmp;
	t_path			*path;

	if (!data->start)
		li_error();
	tmp = data->start;
	w = tmp->weight;
	path = li_new_path("", 1);
	while (tmp->weight > 0)
	{
		i = -1;
		while (tmp->tube[++i] != NULL)
		{
			if (tmp->tube[i]->weight == w - 1)
			{
				path = li_build_path(path, tmp->tube[i]->name);
				if (tmp->tube[i] != data->end)
				{
					w = tmp->tube[i]->weight;
					tmp->tube[i]->weight = INT_MAX;
				}
				break;
			}
		}
		tmp = tmp->tube[i];
	}
	return (path);
}
