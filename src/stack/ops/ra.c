/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:12:23 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief rotate a
 *
 * Shift up all elements of stack **a** by one.
 *
 * The first element becomes the last one.
 *
 * @see rotate()
 * @author kjurkows
 * @param a stack **a**
 * @retval 0 success
 * @retval 1 error
 */
int	ra(t_stack *a)
{
	if (rotate(a))
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}
