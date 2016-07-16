/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:20:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/16 14:27:20 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Returns the pointer to the end of the list.
*/

t_path				*li_reach_the_end(t_path *path)
{
	t_path			*end;

	end = path;
	while (end->next != NULL)
		end = end->next;
	return (end);
}

/*
** Make ant_id steps room by room, so this is how our ants are crawling.
*/

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

/*
** Display the final result.
*/

void				li_display2(t_graph *data, int ant_id, char *name)
{
	if (data->bonus[1] == 1)
	{
		ft_printf("\033[38;5;%dmL%d-%s \033[0m", ant_id, ant_id, name);
	}
	else
		ft_printf("L%d-%s ", ant_id, name);
}

int					li_display(t_graph *data, t_path **paths)
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
				li_display2(data, end->ant_id, end->name);
			}
			end = end->prev;
		}
		i++;
	}
	if (ret)
		data->plays += ft_printf("\n");
	return (ret);
}

/*
** If we have several paths, it determines if it is useful to send ants in
** each paths or not.
*/

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
		ret = li_display(data, paths);
	}
	if (data->bonus[2] == 1)
		li_display_stats(data);
}
