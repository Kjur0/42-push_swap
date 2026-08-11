/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:08:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 16:35:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>
#include <bench.h>

/** @brief swap b
 *
 * Swap the first two elements at the top of stack **b**
 *
 * Do nothing if there is only one or no elements
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
int	sb(t_list **b, t_op_counts *opc)
{
	if (swap(b))
		return (1);
	opc->sb++;
	ft_putendl_fd("sb", 1);
	return (0);
}
