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

#include <stacks.h>
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

static void	sort_three(t_list **stack, t_op_counts *ops)
{
	int	first;
	int	second;
	int	third;

	first = (((t_stack_element *)(*stack)->content))->index;
	second = (((t_stack_element *)(*stack)->next->content))->index;
	third = (((t_stack_element *)(*stack)->next->next->content))->index;
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

static void	drain_stack_b(t_list **a, t_list **b, t_op_counts *ops)
{
	while (*b)
		do_pa(a, b, ops);
}

t_op_counts	simple(t_list **a, t_list **b)
{
	int			min;
	int			size;
	t_op_counts	ops;

	ops = init_op_counts();
	if (!a || !*a || !(*a)->next)
		return (ops);
	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((((t_stack_element *)(*a)->content)->index)
			> (((t_stack_element *)(*a)->next->content)->index))
			do_sa(a, &ops);
		return (ops);
	}
	while (size > 3)
	{
		min = get_min_value(*a);
		while (get_top_value(*a) != min)
			do_ra(a, &ops);
		do_pb(a, b, &ops);
		size--;
	}
	sort_three(a, &ops);
	drain_stack_b(a, b, &ops);
	return (ops);
}
