/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:35:32 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/07 01:35:34 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bench.h>
#include <stacks.h>

void	ra_count(t_list **a, t_op_counts *ops)
{
	if (ops)
		ops->ra += ra(a);
}

void	rb_count(t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->rb += rb(b);
}

void	rr_count(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->rr += rr(a, b);
}

void	rra_count(t_list **a, t_op_counts *ops)
{
	if (ops)
		ops->rra += rra(a);
}

void	rrb_count(t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->rrb += rrb(b);
}
