/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:01:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 22:01:14 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms.h>

#include "meta.h"

#include <stack.h>

//!TODO: docs
void	small_sort(t_stack *a)
{
	if (a->size == 2 && a->list->n_val == 1)
		sa(a, true);
	else if (a->size == 3 && a->list->n_val == 2)
	{
		if (a->list->next->n_val == 0)
			ra(a, true);
		else
		{
			sa(a, true);
			rra(a, true);
		}
	}
	else if (a->size == 3 && a->list->next->n_val == 2)
	{
		if (a->list->n_val == 1)
			rra(a, true);
		else
		{
			sa(a, true);
			ra(a, true);
		}
	}
	else if (a->size == 3 && a->list->n_val == 1)
		sa(a, true);
}

//!TODO: docs
static void	rotate_to(t_stack *a, t_stack *b,
	t_stack_element *to_a, t_stack_element *to_b)
{
	if (((t_meta *)to_a->meta)->median == ((t_meta *)to_b->meta)->median)
	{
		while (a->list != to_a && b->list != to_b)
		{
			if (((t_meta *)to_a->meta)->median)
				rr(a, b, true);
			else
				rrr(a, b, true);
		}
	}
	while (a->list != to_a)
	{
		if (((t_meta *)to_a->meta)->median)
			ra(a, true);
		else
			rra(a, true);
	}
	while (b->list != to_b)
	{
		if (((t_meta *)to_b->meta)->median)
			rb(b, true);
		else
			rrb(b, true);
	}
}

//!TODO: docs
void	stage1(t_stack *a, t_stack *b)
{
	t_stack_element	*cur;

	while (a->size > 3)
	{
		cur = recalculate_meta1(a, b);
		rotate_to(a, b, cur, ((t_meta *)cur->meta)->target);
		pb(a, b, true);
	}
}

//!TODO: docs
void	stage2(t_stack *a, t_stack *b)
{
	t_stack_element	*cur;

	while (b->size > 0)
	{
		cur = recalculate_meta2(a, b);
		rotate_to(a, b, ((t_meta *)cur->meta)->target, cur);
		pa(a, b, true);
	}
}

//!TODO: docs
void	complex(t_stack *a, t_stack *b)
{
	t_stack_element	*cur;

	if (a->size > 3)
		pb(a, b, true);
	if (a->size > 3)
		pb(a, b, true);
	if (a->size > 3)
		stage1(a, b);
	small_sort(a);
	if (b->size > 0)
		stage2(a, b);
	cur = recalculate_meta3(a);
	while (a->list != cur)
	{
		if (((t_meta *)cur->meta)->median)
			ra(a, true);
		else
			rra(a, true);
	}
}
