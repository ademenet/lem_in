/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:08:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/06 14:31:25 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Here, we parse, we check, to be sure that our datas are fine. Nor empty line
** nor improper datas will be tolerated.
*/

/*
** The first line corresponds to ants number, it should be an positive integer.
** Otherwise, we'll consider it as an error.
*/

int					li_ants_get(char *line, t_graph *data)
{
	int				i;
	long			nb;

	i = 0;
	nb = 0;
	if (line)
	{
		if (line[0] == '-')
			return (-1);
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i]))
				i++;
			else
				return (-1) ;
		}
		nb = ft_atoi(line);
		if (nb > INT_MAX)
			return (-1);
	}
	data->ant = (int)nb;
	return (1);
}

/*
** Sharp means two things: comments (if there is only one then text) or
** commands (two sharps then start or end).
*/

int					li_sharp_handler(char *line)
{
	if (ft_strcmp("##start", line) == 0)
		return (1);
	else if (ft_strcmp("##end", line) == 0 )
		return (2);
	else
		return (0);
}

/*
** Our main parsing function. Loops on standard input and analyse each line.
** It continues to loop and display what we read even if informations are
** wrong.
*/

t_graph				li_parsing(t_graph *data)
{
	int				err;
	int				com;
	char			*line;

	err = 0;
	com = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if (err == -1)
			li_error();
		else if (line[0] == '#')
			com = li_sharp_handler(line);
		else if (err == 0)
			err = li_ants_get(line, data);
		else if (err == 1)
			err = li_room_get(line, data, &com);
		else if (err == 2)
			err = li_tube_get(line, data);
	}
	return (*data);
}
