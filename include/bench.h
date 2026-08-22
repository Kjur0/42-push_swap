/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:27:56 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 23:48:16 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO: docs

#ifndef BENCH_H
# define BENCH_H

# include <libft.h>
# include <stack/s_stack.h>

typedef struct s_op_counts
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_op_counts;

typedef struct s_bench
{
	double		disorder;
	const char	*strategy;
	int			total_ops;
	t_op_counts	ops;
}	t_bench;

t_bench	bench_init(void);
void	total_op_count(t_bench *bench);

#endif
