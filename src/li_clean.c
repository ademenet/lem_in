/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:37:37 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/04 16:17:07 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Free the room name, the tubes and the element itself.
*/

void				li_clean_one_elem(t_room *to_del)
{
	free(to_del->name);
	free(to_del->tube);
	free(to_del);
}

/*
** Clean the differents paths we used.
*/

void				li_clean_paths(t_path **paths)
{
	t_path			*delpath;
	t_path			*to_delpath;
	int				i;

	i = 0;
	while (paths[i] != NULL)
	{
		delpath = paths[i];
		while (delpath)
		{
			to_delpath = delpath;
			delpath = delpath->next;
			free(to_delpath);
		}
		i++;
	}
	free(paths);
}

/*
** Clean everything data points to.
*/

void				li_clean_data(t_graph *data)
{
	t_room			*del;
	t_room			*to_del;

	del = data->queue;
	while (del)
	{
		to_del = del;
		del = del->next;
		li_clean_one_elem(to_del);
	}
}
