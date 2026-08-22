/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:35:45 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 19:59:35 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bench.h>
#include <stack.h>

void	do_rrr(t_stack *a, t_stack *b, t_op_counts *ops)
{
	if (ops && !rrr(a, b, true))
		ops->rrr++;
}
