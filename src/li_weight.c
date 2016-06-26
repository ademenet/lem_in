/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:05:42 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/26 21:57:07 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

/*
** Here we assign weight.
*/

int					li_weight_recursive(t_graph *data, t_room *cur, int weight)
{
	static int		depth = 1;
	int				i;

	DBfct
	if (cur == data->start )
		return (0);
	i = 0;
	while (cur->tube[i] != NULL)
	{
		if (cur->tube[i]->weight == -1)
		{
			cur->tube[i]->weight = weight;
		}
		i++;
	}
	depth++;
	i = 0;
	return (1);
}

/*
** This function cleans rooms without any tubes.
*/

void				li_check_for_lonely_room(t_graph *data)
{
	t_room			*cur;
	t_room			*to_del;

	cur = data->head;
	while (cur)
	{
		if (cur->tube == NULL)
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			to_del = cur;
			cur = cur->next;
			free(to_del);
		}
		else
			cur = cur->next;
	}
}

fonction pour marquer les

int					li_BFS(t_graph *data)
{

}

poids a 0
mettre salle end au debut de la liste.
tq pointeur tete de lecture list non nulle
	tq list de pointeur

Procedure BFS(Graphe G, Noeud Origine)
{
   File aTraiter
   profondeur[Origine] = 0
   Marquer Origine comme visite
   aTraiter.enfiler(Origine)

   Tant que aTraiter.nonVide()
   {
      Noeud N = aTraiter.defiler()

      Afficher : N.nom + " voit la video a l'heure " + profondeur[N]

      Pour chaque voisin V de N
         Si V non visite
            profondeur[V] = profondeur[N] + 1
            Marquer V comme visite
            aTraiter.enfiler(V)
   }
}

int					li_weight(t_graph *data)
{
	int				weight;
	t_room			*cur;

	data->end->weight = 0;
	cur = data->end;
	cur->weight = 0;
	weight = 1;
	while ()
	{
		weight++;
	}

	t_room	*tmp;
	tmp = data->head;
	while (tmp)
	{
		printf("weight de %s : [%d]\n", tmp->name, tmp->weight);
		tmp = tmp->next;
	}

	return (1);
}

int weight = 0
salle de debut: start
