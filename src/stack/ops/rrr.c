/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:20:32 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/ops.h>

#include <libft.h>

/** @brief reverse rotate a/b
 *
 * reverse rotate a & reverse rotate b at the same time
 *
 * @see rrotate()
 * @author kjurkows
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rrr(t_stack *a, t_stack *b, bool print)
{
	if (rrotate(a))
		return (1);
	if (rrotate(b))
	{
		rotate(a);
		return (1);
	}
	if (print)
		ft_putendl_fd("rrr", 1);
	return (0);
}
