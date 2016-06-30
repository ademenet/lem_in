/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 09:50:17 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/30 11:05:18 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Create new path node. It stocks the room's name and an int for further
** ant identification.
*/

t_path		*li_new_path(char *name, int ant_id)
{
	t_path		*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->name = name;
	path->ant_id = ant_id;
	path->next = NULL;
	path->prev = NULL;
	return (path);
}

/*
** Add a new node to path's list.
*/

void		li_add_path(t_path **list, t_path *new)
{
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
}

/*
** Assemble new room with others rooms to generate a path.
*/

void		li_build_path(t_path **path, char *name)
{
	t_path		*new;

	new = li_new_path(name, 0);
	li_add_path(path, new);
}

/*
** Delete the path if it does'nt end on a solution.
*/

void		li_del_path(t_path **path)
{
	t_path	*del;
	t_path	*to_del;

	del = *path;
	while (del)
	{
		to_del = del;
		del = del->next;
		free(to_del);
	}
}
