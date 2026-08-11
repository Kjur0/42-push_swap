/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 20:08:16 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief reverse rotate a/b
 *
 * reverse rotate a & reverse rotate b at the same time
 *
 * @internal
 * @see ra()
 * @see rb()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 */
int	rrr(t_list **a, t_list **b)
{
	if (rra(a) && rrb(b))
	{
		return (1);
	}
	return (0);
}
