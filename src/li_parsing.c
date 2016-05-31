/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:08:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/31 15:01:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		li_readline(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[0] == '#')
		{
			if (line[1] == '#')
			{
				\\ declenche le start ou le end
				i++;
			}
			i++;
		}
		i++;
	}
}

void		li_parsing()
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(1, &line)) != 0)
	{
		li_readline(line);
	}
}
