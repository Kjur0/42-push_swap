/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:10:00 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** @brief swap a/b
 *
 * swap a & swap b at the same time
 *
 * @see swap()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int	ss(t_stack *a, t_stack *b)
{
	if (swap(a))
		return (1);
	if (swap(b))
	{
		swap(a);
		return (1);
	}
	ft_putendl_fd("ss", 1);
	return (0);
}
