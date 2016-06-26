/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/26 20:07:54 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/include/fpf_printf.h"

# define DBfct fprintf(stderr, "\n%s\n", __FUNCTION__); // A EFFACER !
# define DB(text) fprintf(stderr, "%s\n", text); // A EFFACER !
# define DBint(text, integer) fprintf(stderr, "%s == [%d]\n", text, integer); // A EFFACER !

typedef struct s_room	t_room;
typedef struct s_graph	t_graph;

/*
** This structure contains our graph: room's name (aka identifier),
** room pointer's array and next node pointer.
*/

struct					s_room
{
	char				*name;
	int					weight;
	t_room				**tube;
	t_room				*next;
	t_room				*prev;
};

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
};

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
** WEIGHT
*/

int						li_weight_recursive(t_graph *data, t_room *cur,
						int weight);
int						li_weight(t_graph *data);

/*
** GRAPH
*/

void					li_new_graph(t_graph *data);

/*
** PARSING
*/

t_graph					li_parsing(t_graph *data);
int						li_sharp_handler(char *line);
int						li_ants_get(char *line, t_graph *data);

/*
** TUBE
*/

int						li_tube_get(char *line, t_graph *data);
t_room					*li_tube_room_find(char *name, t_graph *data);
void					li_tube_dig(t_room *room1, t_room *room2);
t_room					**li_tube_copy(t_room **tube, t_room *to_link);

/*
** ROOM
*/

int						li_room_get(char *line, t_graph *data, int *com);
int						li_room_check_coord(char *line);
int 					li_room_add(t_graph *data, char *name, int *com);
int						li_room_start_end(t_graph *data, int *com);

/*
** ERROR
*/

int						li_check_valid(t_graph *data);
void					li_error(void);
void					li_errormsg(char *msg);

// DEBUG A EFFACER
void					li_dispdeb(t_graph *data);

#endif
