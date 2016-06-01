/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:08:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/01 17:32:42 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

// t_lili		*li_lstnew(t_lili *room)
// {
// 	if (room)
// 	{
//
// 	}
// 	return ()
// }
//
// t_lili		**li_new_malloc(t_lili **tube, t_lili *room)
// {
// 	t_lili	**tmp;
//
// 	if (tube)
// 	{
// 		tmp = tube;
// 		tube = (t_lili**)malloc(sizeof(tmp) + sizeof(t_lili*));
// 		free(tmp);
// 	}
// 	return (tube);
// }

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

// char		*li_get_room(char *line)
// {
//
// }
//
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
//
// void		li_parsing()
// {
// 	int		ret;
// 	char	*line;
//
// 	while ((ret = get_next_line(1, &line)) != 0)
// 	{
// 		puts(line);
// 	}
// }
