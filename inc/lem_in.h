/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/30 11:24:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/include/fpf_printf.h"

# include <unistd.h>
# define DBfct fprintf(stderr, "%s\n", __FUNCTION__); // A EFFACER !
# define DBfctf fprintf(stderr, "fin de %s\n", __FUNCTION__); // A EFFACER !
# define DB(text) fprintf(stderr, "%s\n", text); // A EFFACER !
# define DBint(text, integer) fprintf(stderr, "%s == [%d]\n", text, integer); // A EFFACER !

typedef struct s_room	t_room;
typedef struct s_graph	t_graph;
typedef struct s_path	t_path;

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
** Paths are lists, where ants are integers.
*/

struct					s_path
{
	char				*name;
	int					ant_id;
	struct s_path		*next;
	struct s_path		*prev;
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
	struct s_room		*queue;
	char				bonus[6];
};


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
** DISPLAY
*/

void					li_display_lap(t_path *path, t_path *end, int ants);
void					li_ants_crawling(t_path *cur);
void					li_display(t_path *path, int ants);
int						li_path_len(t_path *path);

/*
** WEIGHT
*/

void					li_check_for_lonely_room(t_graph *data);
void					li_kill_those_separatists(t_graph *data);
int						li_bfs(t_graph *data);
int						li_weight_child(t_graph *data);
void					li_weight_child2(t_graph *data, int *i);

/*
** PATH
*/

t_path					*li_new_path(char *name, int ant_id);
void					li_add_path(t_path **list, t_path *new);
void					li_build_path(t_path **path, char *name);
void					li_del_path(t_path **path);

/*
** PATHS
*/

void					li_one_tube(t_graph *data);
t_path					**li_add_path_to_paths(t_path **paths, t_path *path);
int						li_create_path(t_graph *data, t_path **path);
int						li_find_min_weight(t_graph *data, t_room *room,
						t_room **nxt);
t_path					**li_find_paths(t_graph *data);

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

/*
** CLEAN
*/

void					li_clean_one_elem(t_room *to_del);
void					li_clean_everything(t_graph *data, t_path *path);


// DEBUG A EFFACER
void					li_display_debug(t_graph *data, t_room *start);
void					li_display_initial_list(t_graph *data, t_room *start);
void					li_display_path(t_path **path);
void 					truc(t_path *path);

#endif
