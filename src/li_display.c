/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:20:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/29 11:34:40 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_display_lap(t_path *path, int ants)
{
	t_path			*cur;

	cur = path->next;
	while (cur)
	{
		if (cur->ant_id > 0 && cur->ant_id <= ants)
		{
			ft_printf("L%d-%s", cur->ant_id, cur->name);
			if (cur->next != NULL)
				ft_printf(" ");
		}
		cur = cur->next;
	}
	ft_printf("\n");
}

void				li_ants_crawling(t_path *cur)
{
	while (cur)
	{
		if (cur->prev != NULL)
			cur->ant_id = cur->prev->ant_id;
		// if (cur == path)
		// 	cur->ant_id = cur->ant_id + 1;
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
		li_display_lap(path, ants);
		path->ant_id += 1;
		cur = end;
	}
}
