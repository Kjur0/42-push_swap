/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:27:56 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 19:51:40 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_op_counts		init_op_counts(void);
int				total_op_count(const t_op_counts *ops);
void			do_sa(t_stack *a, t_op_counts *ops);
void			do_sb(t_stack *b, t_op_counts *ops);
void			do_ss(t_stack *a, t_stack *b, t_op_counts *ops);
void			do_pa(t_stack *a, t_stack *b, t_op_counts *ops);
void			do_pb(t_stack *a, t_stack *b, t_op_counts *ops);
void			do_ra(t_stack *a, t_op_counts *ops);
void			do_rb(t_stack *b, t_op_counts *ops);
void			do_rr(t_stack *a, t_stack *b, t_op_counts *ops);
void			do_rra(t_stack *a, t_op_counts *ops);
void			do_rrb(t_stack *b, t_op_counts *ops);
void			do_rrr(t_stack *a, t_stack *b, t_op_counts *ops);

#endif
