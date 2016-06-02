/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/02 19:02:51 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/include/fpf_printf.h"

/*
** This structure contains our graph: room's name (aka identifier),
** room pointer's array and next node pointer.
*/

struct					s_llst
{
	char				*name;
	struct s_llst		**tube;
	struct s_llst		*next;
}						t_llst;

/*
** This structure contains useful variables: ant's number, our start pointer,
** our end pointer and a pointer to the head list of rooms.
*/

struct					s_lemi
{
	int					ant;
	struct s_llst		*start;
	struct s_llst		*end;
	struct s_llst		*head;
}						t_lemi;

/*
** Ants structure: WIP
*/

struct					s_ant
{
	char				*id;
	struct s_llst		*loc;
}						t_ant;

enum					e_err
{
	ERROR_NB,
	ERROR_ROOM,
	ERROR_TUBE
};

/*
** LEXER-PARSER
*/

int						li_ants_get(char *line, t_lemi *data, int * err);
char					*li_room_get(char *line, int *coord_x, int *coord_y);

/*
** ERROR
*/

void					li_errorempty(char *line);
void					li_error(void);
void					li_errormsg(char *msg);

#endif
