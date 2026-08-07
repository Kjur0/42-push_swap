/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:04:33 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/07 01:42:28 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>
#include <bench.h>

static int	get_top_value(t_list *stack)
{
	return (*((int *)stack->content));
}

static int	get_min_value(t_list *stack)
{
	int		min;
	t_list	*node;

	node = stack;
	min = *((int *)node->content);
	while (node)
	{
		if (*((int *)node->content) < min)
			min = *((int *)node->content);
		node = node->next;
	}
	return (min);
}

static void	sort_three(t_list **stack, t_op_counts *ops)
{
	int	first;
	int	second;
	int	third;

	first = *((int *)(*stack)->content);
	second = *((int *)(*stack)->next->content);
	third = *((int *)(*stack)->next->next->content);
	if (first > second && second > third)
	{
		sa_count(stack, ops);
		rra_count(stack, ops);
	}
	else if (first > second && second < third && first > third)
		ra_count(stack, ops);
	else if (first < second && second > third && first < third)
	{
		rra_count(stack, ops);
		sa_count(stack, ops);
	}
	else if (first > second && second < third && first < third)
		sa_count(stack, ops);
	else if (first < second && second > third && first > third)
		rra_count(stack, ops);
}

static void	drain_stack_b(t_list **a, t_list **b, t_op_counts *ops)
{
	while (*b)
		pa_count(a, b, ops);
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
		if (*((int *)(*a)->content) > *((int *)(*a)->next->content))
			sa_count(a, &ops);
		return (ops);
	}
	while (size > 3)
	{
		min = get_min_value(*a);
		while (get_top_value(*a) != min)
			ra_count(a, &ops);
		pb_count(a, b, &ops);
		size--;
	}
	sort_three(a, &ops);
	drain_stack_b(a, b, &ops);
	return (ops);
}
