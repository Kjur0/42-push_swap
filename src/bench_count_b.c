/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:35:32 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 19:59:13 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bench.h>
#include <stacks.h>

void	do_ra(t_list **a, t_op_counts *ops)
{
	if (ops)
	{
		if(ra(a))
		{
			ops->ra++;
			ft_putendl_fd("ra", 1);
		}
	}
}

void	do_rb(t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if(rb(b))
		{
			ops->rb++;
			ft_putendl_fd("rb", 1);
		}
	}
}

void	do_rr(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if(rr(a, b))
		{
			ops->rr++;
			ft_putendl_fd("rr", 1);
		}
	}
}

void	do_rra(t_list **a, t_op_counts *ops)
{
	if (ops)
	{
		if(rra(a))
		{
			ops->rra++;
			ft_putendl_fd("rra", 1);
		}
	}
}

void	do_rrb(t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if(rrb(b))
		{
			ops->rrb++;
			ft_putendl_fd("rrb", 1);
		}
	}
}
