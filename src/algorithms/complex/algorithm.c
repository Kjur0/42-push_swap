/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:01:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:05:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms.h>

#include "meta.h"

#include <stack.h>

//!TODO: docs
void	small_sort(t_stack *a)
{
	t_stack_element	*max;
	t_stack_element	*cur;

	cur = a->list;
	max = cur;
	while (cur)
	{
		if (max->n_val < cur->n_val)
			max = cur;
		cur = cur->next;
	}
	if (a->size < 2 || a->size > 3)
		return ;
	if (a->size == 3 && a->list == max)
		ra(a, true);
	else if (a->size == 3 && a->list->next == max)
		rra(a, true);
	if (a->list->n_val > a->list->next->n_val)
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

void	print_stacks(t_stack *a, t_stack *b);

//!TODO: docs
void	complex(t_stack *a, t_stack *b)
{
	t_stack_element	*cur;

	print_stacks(a, b);
	if (a->size > 3)
		pb(a, b, true);
	if (a->size > 3)
		pb(a, b, true);
	if (a->size > 3)
		stage1(a, b);
	print_stacks(a, b);
	small_sort(a);
	print_stacks(a, b);
	if (b->size > 0)
		stage2(a, b);
	print_stacks(a, b);
	cur = recalculate_meta3(a);
	while (a->list != cur)
	{
		if (((t_meta *)cur->meta)->median)
			ra(a, true);
		else
			rra(a, true);
	}
	print_stacks(a, b);
}
