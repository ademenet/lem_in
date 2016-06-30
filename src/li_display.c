/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:20:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/30 15:18:47 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

// void				li_display_lap(t_path *path, t_path *end, int ants)
// {
// 	t_path			*cur;
//
// 	cur = end;
// 	while (cur != path)
// 	{
// 		if (cur->ant_id > 0 && cur->ant_id <= ants)
// 		{
// 			ft_printf("L%d-%s", cur->ant_id, cur->name);
// 			if (cur->prev != path)
// 				ft_printf(" ");
// 		}
// 		cur = cur->prev;
// 	}
// 	ft_printf("\n");
// }

void				li_ants_crawling(t_path *path, int ant)
{
	t_path			*cur;

	cur = path;
	path->ant_id = ant;
	while (cur->next != NULL)
		cur = cur->next;
	while (cur)
	{
		if (cur->prev != NULL)
			cur->ant_id = cur->prev->ant_id;
		cur = cur->prev;
	}
	path->ant_id = 0;
}

// void				li_display(t_path *path, int ants)
// {
// 	t_path			*end;
// 	t_path			*cur;
//
// 	end = path;
// 	while (end->next != NULL)
// 		end = end->next;
// 	cur = end;
// 	path->ant_id = 1;
// 	while (end->ant_id != ants)
// 	{
// 		li_ants_crawling(cur);
// 		li_display_lap(path, end, ants);
// 		path->ant_id += 1;
// 		cur = end;
// 	}
// }

int					li_display(t_path **paths)
{
	t_path			*end;
	int				i;
	int				ret;

	i = 0;
	while (paths[i] != NULL)
	{
		end = paths[i];
		while (end->next != NULL)
			end = end->next;
		while (end->prev != NULL)
		{
			if (end->ant_id > 0)
			{
				ret = ft_printf("L%d-%s", end->ant_id, end->name);
				if (end->prev != paths[i])
					ft_printf(" ");
			}
			end = end->prev;
		}
		i++;
	}
	ft_printf("\n");
	return (ret);
}

void				li_determine(t_graph *data, t_path **paths)
{
	int				i;
	int				ant;

	ant = 0;
	while (li_display(paths) > 0)
	{
		if (ant < data->ant)
		{
			ant++;
			li_ants_crawling(paths[0], ant);
		}
		else
			li_ants_crawling(paths[0], 0);
		i = 1;
		while (paths[i] != NULL)
		{
			if (li_path_len(paths[i]) - li_path_len(paths[0]) < data->ant - (ant + 1))
			{
				li_ants_crawling(paths[i], ++ant);
			}
			else
				li_ants_crawling(paths[i], 0);
			i++;
		}
	}
}
