/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/10 17:47:32 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_dispdeb(t_graph *data)
{
	t_room *tmp;
	int i = 0;
	tmp = data->head;

	printf("----------------\n");
	while (tmp)
	{
		printf("%s\n", tmp->name);
		while (tmp->tube[i] != NULL)
		{
			printf("\t->%s\n", tmp->tube[i]->name);
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
}

int					li_check_valid(t_graph *data)
{
	if (data->start == NULL || data->end == NULL)
		return (1);
	return (0);
}

// Yaura un malloc pour data
int					main(void)
{
	t_graph			data;

	li_new_graph(&data);
	data = li_parsing(&data);
	if (li_check_valid(&data))
		li_error();

	// tests
	li_weight(&data);

	return (0);
}
