/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/03 15:57:08 by ademenet         ###   ########.fr       */
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

struct					s_room
{
	char				*name;
	int					weight;
	struct s_room		**tube;
	struct s_room		*next;
}						t_room;

/*
** This structure contains useful variables: ant's number, our start pointer,
** our end pointer, a pointer to the head list of rooms and bonus.
*/

struct					s_graph
{
	int					ant;
	struct s_room		*start;
	struct s_room		*end;
	struct s_room		*head;
	char				bonus[6];
}						t_graph;

/*
** Ants structure: WIP
*/

struct					s_ant
{
	char				*id;
	struct s_room		*loc;
}						t_ant;

/*
** Enum for verbose error handler:
*/

enum					e_err
{
	ERROR_NB,
	ERROR_ROOM,
	ERROR_TUBE
};

/*
** PARSER
*/

int						li_ants_get(char *line, t_graph *data, int * err);
char					*li_room_get(char *line, int *coord_x, int *coord_y);

/*
** GRAPH
*/

void					li_new_graph(t_graph *data);

/*
** ERROR
*/

void					li_errorempty(char *line);
void					li_error(void);
void					li_errormsg(char *msg);

#endif
