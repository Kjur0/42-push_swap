/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 20:08:16 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief reverse rotate a
 *
 * Shift down all elements of stack **a** by one.
 *
 * The last element becomes the first one.
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 */
int	rra(t_list **a)
{
	t_list	*cur;
	t_list	*last;

	cur = *a;
	if (!cur || !cur->next)
		return (0);
	while (cur->next && cur->next->next)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *a;
	*a = last;
	return (1);
}
