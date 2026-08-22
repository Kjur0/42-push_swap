/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:04:33 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 21:14:57 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <normalize.h>
#include <bench.h>

static int	get_top_value(t_list *stack)
{
	return (((t_stack_element *)stack->content)->index);
}

static int	get_min_value(t_list *stack)
{
	int		min;
	t_list	*node;

	node = stack;
	min = ((t_stack_element *)node->content)->index;
	while (node)
	{
		if (((t_stack_element *)node->content)->index < min)
			min = ((t_stack_element *)node->content)->index;
		node = node->next;
	}
	return (min);
}

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

t_op_counts	simple(t_stack *a, t_stack *b)
{
	int			min;
	size_t		size;
	t_op_counts	ops;

	ops = init_op_counts();
	if (!a || !a->list || !a->list->next)
		return (ops);
	size = a->size;
	if (size == 2)
	{
		if ((((t_stack_element *)a->list->content)->index)
			> (((t_stack_element *)a->list->next->content)->index))
			do_sa(a, &ops);
		return (ops);
	}
	while (size > 3)
	{
		min = get_min_value(a->list);
		while (get_top_value(a->list) != min)
			do_ra(a, &ops);
		do_pb(a, b, &ops);
		size--;
	}
	sort_three(a, &ops);
	drain_stack_b(a, b, &ops);
	return (ops);
}
