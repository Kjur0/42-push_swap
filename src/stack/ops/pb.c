/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:03:17 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 17:42:03 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

/** @brief push b
 *
 * Take the first element at the top of **a** and put it at the top of **b**.
 *
 * Do nothing if **a** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	pb(t_stack *a, t_stack *b, bool print)
{
	if (push(b, a))
		return (1);
	if (print)
		ft_putendl_fd("pb", 1);
	return (0);
}
