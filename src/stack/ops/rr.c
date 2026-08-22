/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:42:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

/** @brief rotate a/b
 *
 * rotate a & rotate b at the same time
 *
 * @see rotate()
 * @author kjurkows
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rr(t_stack *a, t_stack *b, bool print)
{
	if (rotate(a))
		return (1);
	if (rotate(b))
	{
		rrotate(a);
		return (1);
	}
	if (print)
		ft_putendl_fd("rr", 1);
	return (0);
}
