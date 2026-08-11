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
#include <stacks.h>

void	do_rrr(t_list **a, t_list **b, t_op_counts *ops)
{
	if (ops)
	{
		if(rrr(a, b))
		{
			ops->rrr++;
			ft_putendl_fd("rrr", 1);
		}
	}
}
