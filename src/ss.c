/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 20:08:13 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

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
int	ss(t_list **a, t_list **b)
{
	if (sa(a) && sb(b))
	{
		return (1);
	}
	return (0);
}
