/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:00:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 16:35:50 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>
#include <bench.h>
#include "_ops.h"

/** @brief swap a
 *
 * Swap the first two elements at the top of stack **a**.
 *
 * Do nothing if there is only one or no elements.
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 */
int	sa(t_list **a, t_op_counts *opc)
{
	if (swap(a))
		return (1);
	opc->sa++;
	ft_putendl_fd("sa", 1);
	return (0);
}
