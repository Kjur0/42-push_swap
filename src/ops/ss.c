/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 16:35:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>
#include <bench.h>

/** @brief swap a/b
 *
 * swap a & swap b at the same time
 *
 * @internal
 * @see sa()
 * @see sb()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 */
int	ss(t_list **a, t_list **b, t_op_counts *opc)
{
	if (swap(a))
		return (1);
	if (swap(b))
	{
		swap(a);
		return (1);
	}
	opc->ss++;
	ft_putendl_fd("ss", 1);
	return (0);
}
