/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_tube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:40:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/03 16:41:54 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_tube_copy(t_room **tube, t_room *to_link)
{
	t_room			**new_tube;
	int				i;
	int				len;

	i = -1;
	len = -1;
	while (tube[++len]);
	new_tube = (t_room**)malloc(sizeof(t_room*) * (len + 1));
	while (++i < len)
		new_tube[i] = tube[i];
	tube[len] = to_link;
	free(tube);
	return (new);
}

void				li_tube_dig(t_room *room1, t_room *room2)
{
	t_room			**new_room1;

	if (room1->tube == NULL)
	{
		room1->tube = (t_room**)malloc(sizeof(t_room*));
		room1->tube[0] = room2;
	}
	else if (room1->tube != NULL)
		room1->tube = li_tube_copy(room1->tube, room2);
}

/*
** Find the node corresponding to the name and return its adress.
*/

t_room				*li_tube_room_find(char *name, t_graph *data)
{
	t_room			*tmp;

	tmp = data->head;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

/*
** Rooms are linked with tubes, tubes are given as follows: name1-name2.
*/

int					*li_tube_get(char *line, t_graph *data)
{
	char			**split_line;
	t_room			*room1;
	t_room			*room2;
	int				len;

	split_line = ft_strsplit(line, '-');
	len = -1;
	while (split_line[++len]);
	if (len != 2)
		return (-1);
	if (((room1 = li_tube_room_find(split_line[0], data)) == NULL) &&
		((room2 = li_tube_room_find(split_line[1], data)) == NULL))
		return (-1);
	li_tube_dig(room1, room2);
	li_tube_dig(room2, room1);
	free(split_line[0]);
	free(split_line[1]);
	free(split_line);
	return (2);
}
