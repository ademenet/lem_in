/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:08:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/07/08 14:54:54 by ademenet         ###   ########.fr       */
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
	if (ft_strlen(line) != 0)
	{
		if (line[0] == '-')
			return (-1);
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i]))
				i++;
			else
				return (-2);
		}
		nb = ft_atoi(line);
		if (nb > INT_MAX)
			return (-3);
		data->ant = (int)nb;
		return (1);
	}
	else
		return (-11);
}

/*
** Sharp means two things: comments (if there is only one then text) or
** commands (two sharps then start or end).
*/

void				li_sharp_handler(char *line, int *com)
{
	if (ft_strcmp("##start", line) == 0 && *com == 0)
		*com = 1;
	else if (ft_strcmp("##end", line) == 0 && *com == 0)
		*com = 2;
}

/*
** Our main parsing function. Loops on standard input and analyse each line.
** It continues to loop and display what we read even if informations are
** wrong.
*/

t_graph				li_parsing(t_graph *data)
{
	int				com;
	char			*line;

	com = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if (line[0] == '#')
			li_sharp_handler(line, &com);
		else if (data->err == 0)
			data->err = li_ants_get(line, data);
		else if (data->err == 1)
			data->err = li_room_get(line, data, &com);
		else if (data->err == 2)
			data->err = li_tube_get(line, data);
		free(line);
	}
	free(line);
	ft_printf("\n");
	return (*data);
}
