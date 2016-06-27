/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/27 15:09:46 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** This function cleans rooms without any tubes.
*/

void				li_check_for_lonely_room(t_graph *data)
{
	t_room			*cur;
	t_room			*to_del;

	cur = data->head;
	while (cur)
	{
		if (cur->tube == NULL || cur->tube[0] == cur)
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			to_del = cur;
			cur = cur->next;
			free(to_del);
		}
		else
			cur = cur->next;
	}
}

int					li_BFS(t_graph *data)
{
	data->end->weight = 0;
	data->end->prev->next = data->end->next;
	data->end->next->prev = data->end->prev;
	data->end->next = data->head;
	data->end->prev = NULL;
	data->head->prev = data->end;
	data->head = data->end;
	data->queue = data->end;
	while (data->end->next != NULL)
	{
		DBfct
		if (li_weight_child(data) != 1)
			li_error();
		if (data->head->prev != NULL)
			data->head = data->head->prev;
	}
	return (1);
}

int					li_weight_child(t_graph *data)
{
	int				i;

	i = 0;
	while (data->head->tube[i] != NULL)
	{
		DBfct
		if (data->head->tube[i]->weight == -1)
		{
			// met le poids dans la salle reliee a data->head
			data->head->tube[i]->weight = data->head->weight + 1;
			if (data->head->tube[i]->next != NULL)
			{
				// je decroche la salle pointe par data->head de son element de gauche
				data->head->tube[i]->prev->next = data->head->tube[i]->next;
				// decroche la salle de son element de droite
				data->head->tube[i]->next->prev = data->head->tube[i]->prev;
			}
			else
				data->head->tube[i]->prev->next = NULL;
			// jaccroche la salle a la fin de la file a traiter
			data->head->tube[i]->next = data->queue;
			// je raccroche la fin de file a la salle
			data->queue->prev = data->head->tube[i];
			// comme la salle a traiter est au bout a gauche prev pointe sur NULL
			data->head->tube[i]->prev = NULL;
			// je garde en memoire le dernier element pour pouvoir en ajouter ensuite
			data->queue = data->head->tube[i];
		}
		i++;
	}
	return (1);
}
