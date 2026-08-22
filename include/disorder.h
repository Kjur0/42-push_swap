/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:31:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:23:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO:modulatize

#ifndef DISORDER_H
# define DISORDER_H

# include <stack/s_stack.h>

/** @brief calculate disorder metric
 *
 * disorder metric is a scale from 0 to 1:
 * where 0 means the stack is sorted, and 1 means the stack is unsorted
 *
 * @author kjurkows
 * @param a stack **a**
 * @return disorder metric of a stack
 */
double	calculate_disorder(t_stack *a);

#endif
