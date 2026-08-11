/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:11:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief reverse rotate a
 *
 * Shift down all elements of stack **a** by one.
 *
 * The last element becomes the first one.
 *
 * @see rrotate()
 * @author kjurkows
 * @param a stack **a**
 * @retval 0 success
 * @retval 1 error
 */
int	rra(t_stack *a)
{
	if (rrotate(a))
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}
