/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:12:15 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/06 22:01:38 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms.h>
#include <stacks.h>

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

void	phase1(t_list **a, t_list **b)
{
	const int	size = ft_lstsize(*a);
	int			i;
	int			rank;

	i = 0;
	while (*a)
	{
		rank = get_rank(*a);
		if (rank <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (rank <= i + 15)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	phase2(t_list **a, t_list **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = get_max_pos(*b);
		size = ft_lstsize(*b);
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (size - pos++ > 0)
				rrb(b);
		pa(a, b);
	}
}

void	medium(t_list **a, t_list **b)
{
	phase1(a, b);
	phase2(a, b);
}
