/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:11:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief reverse rotate b
 *
 * Shift down all elements of stack **b** by one.
 *
 * The last element becomes the first one.
 *
 * @see rrotate()
 * @author kjurkows
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int	rrb(t_stack *b)
{
	if (rrotate(b))
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}
