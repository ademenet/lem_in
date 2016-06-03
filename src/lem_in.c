/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:15:12 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/03 16:56:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

// Yaura un malloc pour data
int					main(void)
{
	t_graph			data;

	li_new_graph(&data);
	data = li_parsing(&data);
	return (0);
}
