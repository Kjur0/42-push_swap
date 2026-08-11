/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:03:17 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 17:10:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief push b
 *
 * Take the first element at the top of **a** and put it at the top of **b**.
 *
 * Do nothing if **a** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		return (1);
	ft_putendl_fd("pb", 0);
	return (0);
}
