/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:04:33 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 17:26:58 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <normalize.h>
#include <bench.h>

static void	sort_three(t_stack *stack, t_op_counts *ops)
{
	int	first;
	int	second;
	int	third;

	first = (((t_stack_element *)stack->list->content))->index;
	second = (((t_stack_element *)stack->list->next->content))->index;
	third = (((t_stack_element *)stack->list->next->next->content))->index;
	if (first > second && second > third)
	{
		do_sa(stack, ops);
		do_rra(stack, ops);
	}
	else if (first > second && second < third && first > third)
		do_ra(stack, ops);
	else if (first < second && second > third && first < third)
	{
		do_rra(stack, ops);
		do_sa(stack, ops);
	}
	else if (first > second && second < third && first < third)
		do_sa(stack, ops);
	else if (first < second && second > third && first > third)
		do_rra(stack, ops);
}

static void	drain_stack_b(t_stack *a, t_stack *b, t_op_counts *ops)
{
	while (b->list)
		do_pa(a, b, ops);
}

static int	get_position(t_list *stack, int target)
{
	int	pos;

	pos = 0;
	while (((t_stack_element *)stack->content)->index != target)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	rotate_to_top(t_stack *a, int pos, t_op_counts *ops)
{
	int	steps_down;

	steps_down = (int)a->size - pos;
	if (pos <= steps_down)
	{
		while (pos-- > 0)
			do_ra(a, ops);
	}
	else
	{
		while (steps_down-- > 0)
			do_rra(a, ops);
	}
}

t_op_counts	simple(t_stack *a, t_stack *b)
{
	int			target;
	t_op_counts	ops;

	ops = init_op_counts();
	if (!a || !a->list || !a->list->next)
		return (ops);
	if (a->size == 2)
	{
		if ((((t_stack_element *)a->list->content)->index)
			> (((t_stack_element *)a->list->next->content)->index))
			do_sa(a, &ops);
		return (ops);
	}
	target = 0;
	while (a->size > 3)
	{
		rotate_to_top(a, get_position(a->list, target), &ops);
		do_pb(a, b, &ops);
		target++;
	}
	sort_three(a, &ops);
	drain_stack_b(a, b, &ops);
	return (ops);
}
