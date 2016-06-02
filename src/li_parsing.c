/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:08:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/02 10:40:44 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Here, we parse, we check, to be sure that our datas are fine. Nor empty line
** nor improper datas will be tolerated.
*/

/*
** The first line correspond to ants number, it should be an positive integer.
** Otherwise, we'll consider it as an error.
*/

int			li_get_ants_nb(char *line)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (line)
	{
		if (line[0] == '-')
			li_error();
		while (line[i] != '\0')
			ft_isdigit(line[i]) ? i++ : li_error();
		nb = ft_atoi(line);
		if (nb > INT_MAX || nb < INT_MIN)
			li_error();
	}
	return ((int)nb);
}

/*
** The rooms are defined as it: name coord_x coord_y.
*/

char		*li_get_room(char *line, int *coord_x, int *coord_y)
{
	char	**split_line;
	int		len;

	split_line = ft_strsplit(line, ' ');
	len = 0;
	while (split_line[len])
		len++;
	if (len != 3)
		li_error();
	if (split_line[0][0] == '#' || split_line[0][0] == 'L')
		li_error();
	*coord_x = li_get_ants_nb(split_line[1]);
	*coord_y = li_get_ants_nb(split_line[2]);
	free(split_line[1]);
	free(split_line[2]);
	free(split_line);
	return (split_line[0]);
}

/*
** Rooms are linked with tubes, tubes are given as follows: name1-name2.
*/



// t_lili		*li_lstnew(t_lili *room)
// {
// 	if (room)
// 	{
//
// 	}
// 	return ()
// }

// t_lili		**li_new_malloc(t_lili **tube, t_lili *room)
// {
// 	t_lili	**tmp;

// 	if (tube)
// 	{
// 		tmp = tube;
// 		tube = (t_lili**)malloc(sizeof(tmp) + sizeof(t_lili*));
// 		free(tmp);
// 	}
// 	return (tube);
// }

// void		li_readline(char *line)
// {
// 	int		i;
//
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[0] == '#')
// 		{
// 			if (line[1] == '#')
// 			{
// 				puts("Coucou");
// 				i++;
// 			}
// 			i++;
// 		}
// 		i++;
// 	}
// }

// void		li_parsing()
// {
// 	int		ret;
// 	int		line_nb;
// 	char	*line;

// 	while ((ret = get_next_line(1, &line)) != 0)
// 	{
// 		line_nb += ret;
// 		ft_errorempty(line);
// 		if (line_nb == 1)
// 			li_get_ants_nb(line);
// 		puts(line);
// 	}
// }
