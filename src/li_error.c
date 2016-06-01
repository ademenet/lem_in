/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:39:36 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/01 18:51:18 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		li_errorempty(char *line)
{
	if (line[0] == '\0')
	{
		write(2, "Error: empty line.\n", 19);
		exit(-1);
	}
}

void		li_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

void		li_errormsg(char *msg)
{
	perror(msg);
	exit(-1);
}
