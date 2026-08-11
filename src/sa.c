/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:00:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 20:08:16 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

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
int	sa(t_list **a)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *a;
	if (!cur || !cur->next)
		return (0);
	tmp = cur->next;
	cur->next = tmp->next;
	tmp->next = cur;
	*a = tmp;
	return (1);
}
