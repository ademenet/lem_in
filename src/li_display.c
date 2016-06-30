/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:20:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/30 17:21:07 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_path				*li_reach_the_end(t_path *path)
{
	t_path			*end;

	end = path;
	while (end->next != NULL)
		end = end->next;
	return (end);
}

void				li_ants_crawling(t_path *path, int ant)
{
	t_path			*cur;

	cur = li_reach_the_end(path);
	path->ant_id = ant;
	while (cur)
	{
		if (cur->prev != NULL)
			cur->ant_id = cur->prev->ant_id;
		cur = cur->prev;
	}
	path->ant_id = 0;
}

int					li_display(t_path **paths)
{
	t_path			*end;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	while (paths[i] != NULL)
	{
		end = li_reach_the_end(paths[i]);
		while (end->prev != NULL)
		{
			if (end->ant_id > 0)
			{
				ret++;
				ft_printf("L%d-%s ", end->ant_id, end->name);
				// if (end->prev)
				// 	ft_printf(" ");
			}
			end = end->prev;
		}
		i++;
		// if (ret)
		// 	ft_printf(" ");
	}
	if (ret)
		ft_printf("\n");
	return (ret);
}

void				li_determine(t_graph *data, t_path **paths)
{
	int				i;
	int				ant;
	int				ret;

	ant = 0;
	ret = 1;
	while (ret)
	{
		ant++ < data->ant ? li_ants_crawling(paths[0], ant) :
			li_ants_crawling(paths[0], 0);
		i = 1;
		while (paths[i] != NULL)
		{
			(li_path_len(paths[i]) - li_path_len(paths[0])) <
				(data->ant - (ant + 1)) ?
				li_ants_crawling(paths[i], ++ant) :
				li_ants_crawling(paths[i], 0);
			i++;
		}
		ret = li_display(paths);
	}
}
