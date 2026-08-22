/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:02:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:48:50 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO: docs

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include <stack/s_stack.h>
# include <bench.h>

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_bench	*bench;
}	t_stacks;

void	simple(t_stack *a, t_stack *b, t_bench *bench);
void	medium(t_stack *a, t_stack *b, t_bench *bench);
void	complex(t_stack *a, t_stack *b, t_bench *bench);

#endif
