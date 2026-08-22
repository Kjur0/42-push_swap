/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:35:45 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 21:23:06 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO: delete

#include <bench.h>
#include <stack.h>

void	do_rrr(t_stack *a, t_stack *b, t_op_counts *ops)
{
	if (ops && !rrr(a, b, true))
		ops->rrr++;
}
