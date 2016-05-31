/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/31 13:14:17 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef			t_liroom;
typedef			t_litube;

struct			s_liroom
{
	char		*name;
	int			coord[2];
	t_liroom	*next;
}

struct			s_litube
{
	t_liroom	*r1;
	t_liroom	*r2;
	t_litube	*next;
}

#endif
