/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:01:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:44:41 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms.h>

#include "meta.h"

#include <stack.h>

//!TODO: docs
void	small_sort(t_stack *a, t_bench *bench)
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
		ra(a, true, bench);
	else if (a->size == 3 && a->list->next == max)
		rra(a, true, bench);
	if (a->list->n_val > a->list->next->n_val)
		sa(a, true, bench);
}

//!TODO: docs
static void	rotate_to(t_stacks s, t_stack_element *to_a, t_stack_element *to_b)
{
	if (((t_meta *)to_a->meta)->median == ((t_meta *)to_b->meta)->median)
	{
		while (s.a->list != to_a && s.b->list != to_b)
		{
			if (((t_meta *)to_a->meta)->median)
				rr(s.a, s.b, true, s.bench);
			else
				rrr(s.a, s.b, true, s.bench);
		}
	}
	while (s.a->list != to_a)
	{
		if (((t_meta *)to_a->meta)->median)
			ra(s.a, true, s.bench);
		else
			rra(s.a, true, s.bench);
	}
	while (s.b->list != to_b)
	{
		if (((t_meta *)to_b->meta)->median)
			rb(s.b, true, s.bench);
		else
			rrb(s.b, true, s.bench);
	}
}

//!TODO: docs
void	stage1(t_stacks stacks)
{
	t_stack_element	*cur;

	while (stacks.a->size > 3)
	{
		cur = recalculate_meta1(stacks.a, stacks.b);
		rotate_to(stacks, cur, ((t_meta *)cur->meta)->target);
		pb(stacks.a, stacks.b, true, stacks.bench);
	}
}

//!TODO: docs
void	stage2(t_stacks stacks)
{
	t_stack_element	*cur;

	while (stacks.b->size > 0)
	{
		cur = recalculate_meta2(stacks.a, stacks.b);
		rotate_to(stacks, ((t_meta *)cur->meta)->target, cur);
		pa(stacks.a, stacks.b, true, stacks.bench);
	}
}

//!TODO: docs
void	complex(t_stack *a, t_stack *b, t_bench *bench)
{
	t_stacks		stacks;
	t_stack_element	*cur;

	stacks.a = a;
	stacks.b = b;
	stacks.bench = bench;
	if (a->size > 3)
		pb(a, b, true, bench);
	if (a->size > 3)
		pb(a, b, true, bench);
	if (a->size > 3)
		stage1(stacks);
	small_sort(a, bench);
	if (b->size > 0)
		stage2(stacks);
	cur = recalculate_meta3(a);
	while (a->list != cur)
	{
		if (((t_meta *)cur->meta)->median)
			ra(a, true, bench);
		else
			rra(a, true, bench);
	}
}
