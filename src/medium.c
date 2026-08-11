/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:12:15 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 21:07:29 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms.h>
#include <stacks.h>
#include <bench.h>
#include <normalize.h>

static int	get_rank(t_list *lst)
{
	const int	val = ((t_stack_element *)lst->content)->index;
	int			rank;

	rank = 0;
	while (lst)
	{
		if (((t_stack_element *)lst->content)->index < val)
			rank++;
		lst = lst->next;
	}
	return (rank);
}

static int	get_max_pos(t_list *lst)
{
	int	max_val;
	int	max_pos;
	int	pos;
	int	val;

	max_val = ((t_stack_element *)lst->content)->index;
	max_pos = 0;
	pos = 0;
	while (lst)
	{
		val = ((t_stack_element *)lst->content)->index;
		if (val > max_val)
		{
			max_val = val;
			max_pos = pos;
		}
		lst = lst->next;
		pos++;
	}
	return (max_pos);
}

static void	phase1(t_list **a, t_list **b, t_op_counts *ops)
{
	int		i;
	int		rank;

	i = 0;
	while (*a)
	{
		rank = get_rank(*a);
		if (rank <= i)
		{
			do_pb(a, b, ops);
			do_rb(b, ops);
			i++;
		}
		else if (rank <= i + 15)
		{
			do_pb(a, b, ops);
			i++;
		}
		else
			do_ra(a, ops);
	}
}

static void	phase2(t_list **a, t_list **b, t_op_counts *ops)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = get_max_pos(*b);
		size = ft_lstsize(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				do_rb(b, ops);
		else
			while (size - pos++ > 0)
				do_rrb(b, ops);
		do_pa(a, b, ops);
	}
}

t_op_counts	medium(t_list **a, t_list **b)
{
	t_op_counts	ops;

	ops = init_op_counts();
	phase1(a, b, &ops);
	phase2(a, b, &ops);
	return (ops);
}
