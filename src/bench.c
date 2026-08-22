/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:34:58 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 21:23:09 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO: later

#include <bench.h>
#include <parse.h>

t_op_counts	init_op_counts(void)
{
	return ((t_op_counts){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
}

int	total_op_count(const t_op_counts *ops)
{
	if (!ops)
		return (0);
	return (ops->sa + ops->sb + ops->ss + ops->pa + ops->pb
		+ ops->ra + ops->rb + ops->rr + ops->rra + ops->rrb + ops->rrr);
}

const char	*get_strategy(t_algorithm selected, double disorder)
{
	if (selected == ALG_NONE)
		return ("None / already sorted");
	else if (selected == ALG_SIMPLE)
		return ("Simple / O(n^2)");
	else if (selected == ALG_MEDIUM)
		return ("Medium / O(n√n)");
	else if (selected == ALG_COMPLEX)
		return ("Complex / O(n log n)");
	else if (selected == ALG_ADAPTIVE)
	{
		if (disorder < 0.2)
			return ("Simple / O(n^2)");
		if (disorder < 0.5)
			return ("Medium / O(n√n)");
		return ("Complex / O(n log n)");
	}
	return (NULL);
}

static void	print_op_count(const char *operation, int count)
{
	ft_putstr_fd((char *)operation, 2);
	ft_putstr_fd(":\t", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\t', 2);
}

void	print_bench(const t_bench *bench)
{
	if (!bench)
		return ;
	ft_putstr_fd("[bench] disorder:\t", 2);
	ft_putnbr_fd((int)(bench->disorder * 100.0), 2);
	ft_putendl_fd("%", 2);
	ft_putstr_fd("[bench] strategy:\t", 2);
	ft_putendl_fd((char *)bench->strategy, 2);
	ft_putstr_fd("[bench] total_ops:\t", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_op_count(" sa", bench->ops.sa);
	print_op_count(" sb", bench->ops.sb);
	print_op_count(" ss", bench->ops.ss);
	print_op_count(" pa", bench->ops.pa);
	print_op_count(" pb", bench->ops.pb);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_op_count(" ra", bench->ops.ra);
	print_op_count(" rb", bench->ops.rb);
	print_op_count(" rr", bench->ops.rr);
	print_op_count("rra", bench->ops.rra);
	print_op_count("rrb", bench->ops.rrb);
	print_op_count("rrr", bench->ops.rrr);
	ft_putchar_fd('\n', 2);
}
