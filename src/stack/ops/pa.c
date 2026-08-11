/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:01:44 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 17:10:19 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief push a
 *
 * Take the first element at the top of **b** and put it at the top of **a**.
 *
 * Do nothing if **b** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}
