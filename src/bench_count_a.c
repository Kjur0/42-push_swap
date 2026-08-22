/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:05:33 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 10:57:52 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bench.h>
#include <stack.h>

void	do_sa(t_stack *a, t_op_counts *ops)
{
	if (ops && !sa(a, true))
		ops->sa++;
}

void	do_sb(t_stack *b, t_op_counts *ops)
{
	if (ops && !sb(b, true))
		ops->sb++;
}

void	do_ss(t_stack *a, t_stack *b, t_op_counts *ops)
{
	if (ops && !ss(a, b, true))
		ops->ss++;
}

void	do_pa(t_stack *a, t_stack *b, t_op_counts *ops)
{
	if (ops && !pa(a, b, true))
		ops->pa++;
}

void	do_pb(t_stack *a, t_stack *b, t_op_counts *ops)
{
	if (ops && !pb(a, b, true))
		ops->pb++;
}
