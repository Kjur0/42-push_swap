/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:05:33 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 19:55:54 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bench.h>
#include <stacks.h>

void	do_sa(t_list **a, t_op_counts *ops)
{
	if (ops)
	{
		if (sa(a))
		{
			ops->sa++;
			ft_putendl_fd("sa", 1);
		}
	}
}

void	do_sb(t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if (sb(b))
		{
			ops->sb++;
			ft_putendl_fd("sb", 1);
		}
	}
}

void	do_ss(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if (ss(a, b))
		{
			ops->ss++;
			ft_putendl_fd("ss", 1);
		}
	}
}

void	do_pa(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if (pa(a, b))
		{
			ops->pa++;
			ft_putendl_fd("pa", 1);
		}
	}
}

void	do_pb(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if (pb(a, b))
		{
			ops->pb++;
			ft_putendl_fd("pb", 1);
		}
	}
}
