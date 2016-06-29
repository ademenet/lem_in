/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:20:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/29 13:04:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_display_lap(t_path *path, t_path *end, int ants)
{
	t_path			*cur;

	cur = end;
	while (cur != path)
	{
		if (cur->ant_id > 0 && cur->ant_id <= ants)
		{
			ft_printf("L%d-%s", cur->ant_id, cur->name);
			if (cur->prev != path)
				ft_printf(" ");
		}
		cur = cur->prev;
	}
	ft_printf("\n");
}

void				li_ants_crawling(t_path *cur)
{
	while (cur)
	{
		if (cur->prev != NULL)
			cur->ant_id = cur->prev->ant_id;
		cur = cur->prev;
	}
}

void				li_display(t_path *path, int ants)
{
	t_path			*end;
	t_path			*cur;

	end = path;
	while (end->next != NULL)
		end = end->next;
	cur = end;
	path->ant_id = 1;
	while (end->ant_id != ants)
	{
		li_ants_crawling(cur);
		li_display_lap(path, end, ants);
		path->ant_id += 1;
		cur = end;
	}
}
