/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:05:33 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/07 01:05:36 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bench.h>
#include <stacks.h>

void	sa_count(t_list **a, t_op_counts *ops)
{
	if (ops)
		ops->sa += sa(a);
}

void	sb_count(t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->sb += sb(b);
}

void	ss_count(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->ss += ss(a, b);
}

void	pa_count(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->pa += pa(a, b);
}

void	pb_count(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
		ops->pb += pb(a, b);
}
