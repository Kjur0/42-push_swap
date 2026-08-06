/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/06 21:09:25 by kjurkows         ###   ########.fr       */
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
void	rra(t_list **a)
{
	t_list	*cur;
	t_list	*last;

	cur = *a;
	if (!cur && !cur->next)
		return ;
	while (cur->next && cur->next->next)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *a;
	*a = last;
}
