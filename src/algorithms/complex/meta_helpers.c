/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 18:27:17 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:12:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"

#include <malloc.h>

//!TODO: docs
void	*find_target(t_stack_element *node, t_stack *b)
{
	t_stack_element	*best_target;
	t_stack_element	*cur;

	cur = b->list;
	best_target = NULL;
	while (cur)
	{
		if (cur->n_val < node->n_val && !best_target)
			best_target = cur;
		else if (cur->n_val < node->n_val && cur->n_val > best_target->n_val)
			best_target = cur;
		cur = cur->next;
	}
	if (!best_target)
	{
		cur = b->list;
		best_target = cur;
		while (cur)
		{
			if (cur->n_val > best_target->n_val)
				best_target = cur;
			cur = cur->next;
		}
	}
	return (best_target);
}

//!TODO: docs
void	recalculate_meta_a(t_stack *a, t_stack *b)
{
	t_stack_element	*cur;
	size_t			i;

	cur = a->list;
	i = 0;
	while (cur)
	{
		if (cur->meta)
			free(cur->meta);
		cur->meta = malloc(sizeof(t_meta));
		if (b)
			((t_meta *)cur->meta)->target = find_target(cur, b);
		((t_meta *)cur->meta)->median = i <= a->size / 2;
		((t_meta *)cur->meta)->idx = i++;
		if (((t_meta *)cur->meta)->median)
			((t_meta *)cur->meta)->cost = ((t_meta *)cur->meta)->idx;
		else
			((t_meta *)cur->meta)->cost = a->size - ((t_meta *)cur->meta)->idx;
		cur = cur->next;
	}
}

//!TODO: docs
void	*find_landing(t_stack_element *node, t_stack *a)
{
	t_stack_element	*best_landing;
	t_stack_element	*cur;

	cur = a->list;
	best_landing = NULL;
	while (cur)
	{
		if (cur->n_val > node->n_val && !best_landing)
			best_landing = cur;
		else if (cur->n_val > node->n_val && cur->n_val < best_landing->n_val)
			best_landing = cur;
		cur = cur->next;
	}
	if (!best_landing)
	{
		cur = a->list;
		best_landing = cur;
		while (cur)
		{
			if (cur->n_val < best_landing->n_val)
				best_landing = cur;
			cur = cur->next;
		}
	}
	return (best_landing);
}

//!TODO: docs
void	recalculate_meta_b(t_stack *a, t_stack *b)
{
	t_stack_element	*cur;
	size_t			i;

	cur = b->list;
	i = 0;
	while (cur)
	{
		if (cur->meta)
			free(cur->meta);
		cur->meta = malloc(sizeof(t_meta));
		if (a)
			((t_meta *)cur->meta)->target = find_landing(cur, a);
		((t_meta *)cur->meta)->median = i <= b->size / 2;
		((t_meta *)cur->meta)->idx = i++;
		if (((t_meta *)cur->meta)->median)
			((t_meta *)cur->meta)->cost = ((t_meta *)cur->meta)->idx;
		else
			((t_meta *)cur->meta)->cost = b->size - ((t_meta *)cur->meta)->idx;
		cur = cur->next;
	}
}

//!TODO: docs
t_stack_element	*find_cheapest(t_stack_element *el)
{
	t_stack_element	*cheapest;
	size_t			cost;
	size_t			cur_cost;

	cheapest = NULL;
	cost = __SIZE_MAX__;
	while (el)
	{
		if (((t_meta *)((t_meta *)el->meta)->target->meta)->median
			!= ((t_meta *)el->meta)->median)
			cur_cost = ((t_meta *)el->meta)->cost
				+ ((t_meta *)((t_meta *)el->meta)->target->meta)->cost;
		else if (((t_meta *)((t_meta *)el->meta)->target->meta)->cost
			> ((t_meta *)el->meta)->cost)
			cur_cost = ((t_meta *)((t_meta *)el->meta)->target->meta)->cost;
		else
			cur_cost = ((t_meta *)el->meta)->cost;
		if (cur_cost < cost)
		{
			cost = cur_cost;
			cheapest = el;
		}
		el = el->next;
	}
	return (cheapest);
}
