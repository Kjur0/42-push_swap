/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:12:15 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/07 01:07:23 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms.h>
#include <stacks.h>
#include <bench.h>

static int	get_rank(t_list *lst)
{
	const int	val = *(int *)lst->content;
	int			rank;

	rank = 0;
	while (lst)
	{
		if (*(int *)lst->content < val)
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

	max_val = *(int *)lst->content;
	max_pos = 0;
	pos = 0;
	while (lst)
	{
		val = *(int *)lst->content;
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
			pb_count(a, b, ops);
			rb_count(b, ops);
			i++;
		}
		else if (rank <= i + 15)
		{
			pb_count(a, b, ops);
			i++;
		}
		else
			ra_count(a, ops);
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
				rb_count(b, ops);
		else
			while (size - pos++ > 0)
				rrb_count(b, ops);
		pa_count(a, b, ops);
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
