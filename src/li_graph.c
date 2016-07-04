/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:19:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/04 17:03:14 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_new_graph(t_graph *data)
{
	data->ant = 0;
	data->start = NULL;
	data->end = NULL;
	data->head = NULL;
	data->queue = NULL;
	ft_bzero(data->bonus, 2);
}
