/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:00:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:35:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

/** @brief swap a
 *
 * Swap the first two elements at the top of stack **a**.
 *
 * Do nothing if there is only one or no elements.
 *
 * @see swap()
 * @author kjurkows
 * @param a		stack **a**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	sa(t_stack *a, bool print)
{
	if (swap(a))
		return (1);
	if (print)
		ft_putendl_fd("sa", 1);
	return (0);
}
