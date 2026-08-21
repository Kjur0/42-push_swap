/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:02:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/06 22:48:47 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include <libft.h>
# include <bench.h>

t_op_counts	simple(t_list **a, t_list **b);
t_op_counts	medium(t_list **a, t_list **b);
t_op_counts	complex(t_list **a, t_list **b);

#endif
