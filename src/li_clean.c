/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:37:37 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/03 16:17:53 by alain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_clean_everything(t_graph *data, t_path **paths)
{
	t_room			*del;
	t_room			*to_del;

	del = data->queue;
	DB("segfault2")
	while (del)
	{
		to_del = del;
		del = del->next;
		free(to_del->name);
		free(to_del->tube);
		free(to_del);
	}
	DB("segfault1")
	li_clean_paths(paths);
}

void				li_clean_paths(t_path **paths)
{
	t_path			*delpath;
	t_path			*to_delpath;
	int				i;

	i = 0;
	DB("segfault3")
	if (paths[i] != NULL)
	{
		DB("ok..")
		while (paths[i] != NULL)
		{
			DB("1")
			delpath = paths[i];
			DB("2")
			while (delpath)
			{
				DB("3")
				to_delpath = delpath;
				DB("4")
				delpath = delpath->next;
				DB("5")
				free(to_delpath);
			}
			i++;
		}
	}
	DB("segfault4")
	free(paths);
}

void				li_clean_one_elem(t_room *to_del)
{
	free(to_del->name);
	free(to_del->tube);
	free(to_del);
}
