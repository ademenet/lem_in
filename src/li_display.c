/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:20:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/28 19:45:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_display_lap(t_path *path)
{
	t_path			*cur;

	cur = path;
	while (cur)
	{
		if (cur->ant_id != 0)
		{
			ft_printf("L%d-%s", cur->ant_id, cur->name);
			if (cur->next != NULL)
				ft_printf(" ");
		}
		cur = cur->next;
	}
	ft_printf("\n");
}

int					li_go(t_path *path)
{
	t_path			*cur;

	cur = path;
	while (cur)
	{
		cur->ant_id
		cur = cur->next;
	}
	return (1);
}

void				li_display(t_path *path, int ants)
{
	while ()
	{
		li_display_lap(path);
	}
}
