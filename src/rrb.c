/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 20:08:16 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief reverse rotate b
 *
 * Shift down all elements of stack **b** by one.
 *
 * The last element becomes the first one.
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
int	rrb(t_list **b)
{
	t_list	*cur;
	t_list	*last;

	cur = *b;
	if (!cur || !cur->next)
		return (0);
	while (cur->next && cur->next->next)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *b;
	*b = last;
	return (1);
}
