/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:08:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:09:14 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief swap b
 *
 * Swap the first two elements at the top of stack **b**
 *
 * Do nothing if there is only one or no elements
 *
 * @see swap()
 * @author kjurkows
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int	sb(t_stack *b)
{
	if (swap(b))
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}
