/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/01 16:59:32 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/include/fpf_printf.h"

/*
** This structure contains our graph.
*/

struct					s_lili
{
	char				*name;
	struct s_lili		**tube;
	struct s_lili		*next;
}						t_lili;

/*
** This structure contains useful variables.
*/

struct					s_ligen
{
	int					ant;
	struct s_lili		*start;
	struct s_lili		*end;
}						t_ligen;

int						li_get_ants_nb(char *line);

/*
** ERROR
*/

void					li_error(void);
void					li_errormsg(char *msg);

#endif
