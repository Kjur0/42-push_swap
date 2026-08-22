/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:42:40 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

/** @brief rotate b
 *
 * Shift up all elements of stack **b** by one.
 *
 * The first element becomes the last one.
 *
 * @see rotate()
 * @author kjurkows
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rb(t_stack *b, bool print)
{
	if (rotate(b))
		return (1);
	if (print)
		ft_putendl_fd("rb", 1);
	return (0);
}
