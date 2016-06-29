/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:37:37 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/29 13:21:24 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				li_clean_element()
{

}

void				li_clean_one_elem(t_room *to_del)
{
	free(to_del->name);
	free(to_del->tube);
	free(to_del);
}
