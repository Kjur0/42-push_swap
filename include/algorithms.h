/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:02:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 15:52:53 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include <bench.h>
# include <stack/s_stack.h>

t_op_counts	simple(t_stack *a, t_stack *b);
t_op_counts	medium(t_stack *a, t_stack *b);
t_op_counts	complex(t_stack *a, t_stack *b);

#endif
