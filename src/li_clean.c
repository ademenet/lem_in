/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:37:37 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/29 14:09:14 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_clean_everything(t_graph *data, t_path *path)
{
	t_room			*del;
	t_room			*to_del;
	t_path			*delpath;
	t_path			*to_delpath;

	del = data->queue;
	delpath = path;
	while (del)
	{
		to_del = del;
		del = del->next;
		free(to_del->name);
		free(to_del->tube);
		free(to_del);
	}
	while (delpath)
	{
		to_delpath = delpath;
		delpath = delpath->next;
		free(to_delpath);
	}
}

void				li_clean_one_elem(t_room *to_del)
{
	free(to_del->name);
	free(to_del->tube);
	free(to_del);
}
