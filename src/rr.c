/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/07 02:47:57 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stacks.h>

/** @brief rotate a/b
 *
 * rotate a & rotate b at the same time
 *
 * @internal
 * @see ra()
 * @see rb()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 */
int	rr(t_list **a, t_list **b)
{
	if (ra(a) && rb(b))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
