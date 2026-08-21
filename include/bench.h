/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:27:56 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/07 01:41:55 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include <libft.h>

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
void			sa_count(t_list **a, t_op_counts *ops);
void			sb_count(t_list **b, t_op_counts *ops);
void			ss_count(t_list **a, t_list **b, t_op_counts *ops);
void			pa_count(t_list **a, t_list **b, t_op_counts *ops);
void			pb_count(t_list **a, t_list **b, t_op_counts *ops);
void			ra_count(t_list **a, t_op_counts *ops);
void			rb_count(t_list **b, t_op_counts *ops);
void			rr_count(t_list **a, t_list **b, t_op_counts *ops);
void			rra_count(t_list **a, t_op_counts *ops);
void			rrb_count(t_list **b, t_op_counts *ops);
void			rrr_count(t_list **a, t_list **b, t_op_counts *ops);

#endif
