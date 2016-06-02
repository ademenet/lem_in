/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:08:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/02 18:50:01 by ademenet         ###   ########.fr       */
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

int					li_ants_get(char *line, t_lemi *data, int * err)
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
			ft_isdigit(line[i]) ? i++ : return (-1) ;
		nb = ft_atoi(line);
		if (nb > INT_MAX || nb < INT_MIN)
			return (-1);
	}
	data->ant = (int)nb;
	return (1);
}

/*
** The rooms are defined as it: name coord_x coord_y.
*/

// Renvoit un malloc ici

int					li_room_get(char *line, t_lemi *data, int *err)
{
	char			**split_line;
	int				coord_x;
	int				coord_y;
	int				len;

	split_line = ft_strsplit(line, ' ');
	len = 0;
	while (split_line[len])
		len++;
	if (len != 3 && split_line[0][0] == 'L')
		return (-1);
	len = -1;
	while (split_line[0][++len] != '\0')
	{
		if (split_line[0][len] == '-')
			return (-1);
	}
	coord_x = li_ants_get(split_line[1]);
	coord_y = li_ants_get(split_line[2]);
	data->name = split_line[0];
	free(split_line[1]);
	free(split_line[2]);
	free(split_line);
	return (1);
}

/*
** Rooms are linked with tubes, tubes are given as follows: name1-name2.
*/

// void				*li_get_tube(char *line)
// {
// 	char			*id;
// 	int				i;
//
// 	id = ft_strchr(line, '-');
// 	while (line[i] != id)
// 		i++;
// 	ft_strncmp(line, i);
// }

/*
**
*/

t_lemi				*li_parsing(t_lemi *data)
{
	int				err;
	char			*line;

	ret = 0;
	if (get_next_line(1, &line) != 0)
		err = li_ants_get(line, &err);
	while (get_next_line(1, &line) != 0)
	{
		if (err != -1)
			li_sharp_handler(line, &err);
		else if (err = -1)
			ft_error();
		else if (err = 1)
			err = li_room_get(line, data, &err);
	}
}

/*
** Sharps mean two things: comments (if there is only one then text) or
** instruction (two sharps then start or end).
*/

int					li_sharp_handler(char *line, int *err)
{
	if (ft_strcmp(line, "##start"))
		// call function handler start
	else if (ft_strcmp(line, "##end"))
		// call function handler end
	else if (line[0] == '#')
		return (err);
}

// t_llst		*li_lstnew(t_llst *room)
// {
// 	if (room)
// 	{
//
// 	}
// 	return ()
// }

// t_llst		**li_new_malloc(t_llst **tube, t_llst *room)
// {
// 	t_llst	**tmp;

// 	if (tube)
// 	{
// 		tmp = tube;
// 		tube = (t_llst**)malloc(sizeof(tmp) + sizeof(t_llst*));
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
