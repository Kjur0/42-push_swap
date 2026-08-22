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
#include <stack.h>

void	do_ra(t_stack *a, t_op_counts *ops)
{
	if (ops && !ra(a, true))
		ops->ra++;
}

void	do_rb(t_stack *b, t_op_counts *ops)
{
	if (ops && !rb(b, true))
		ops->rb++;
}

void	do_rr(t_stack *a, t_stack *b, t_op_counts *ops)
{
	if (ops && !rr(a, b, true))
		ops->rr++;
}

void	do_rra(t_stack *a, t_op_counts *ops)
{
	if (ops && !rra(a, true))
		ops->rra++;
}

void	do_rrb(t_stack *b, t_op_counts *ops)
{
	if (ops && !rrb(b, true))
		ops->rrb++;
}
