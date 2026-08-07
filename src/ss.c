/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/07 02:47:24 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
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
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}
