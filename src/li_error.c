/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:39:36 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/18 14:07:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_error_msg(int err)
{
	if (err == -1)
		ft_printf(": ants number couldn't be negative.");
	else if (err == -2)
		ft_printf(": ants number should be a number.");
	else if (err == -3)
		ft_printf(": ants number is over int size.");
	else if (err == -4)
		ft_printf(": room line is not valid.");
	else if (err == -5)
		ft_printf(": room name contains minus or L.");
	else if (err == -6)
		ft_printf(": coordinates are not valid.");
	else if (err == -7)
		ft_printf(": Start or End is allready allocated.");
	else if (err == -8)
		ft_printf(": tube line is not valid.");
	else if (err == -10)
		ft_printf(": Start or End is not linked with the other rooms.");
	else if (err == -11)
		ft_printf(": first line is empty.");
}

void				li_error(t_graph *data)
{
	write(2, "Error", 5);
	if (data->bonus[0] == 1)
		li_error_msg(data->err);
	write(2, "\n", 1);
	exit(-1);
}
