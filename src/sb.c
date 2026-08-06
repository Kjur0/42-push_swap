/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:08:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/06 20:23:13 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief swap b
 *
 * Swap the first two elements at the top of stack **b**
 *
 * Do nothing if there is only one or no elements
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
void	sb(t_list **b)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *b;
	if (!cur || !cur->next)
		return ;
	tmp = cur->next;
	cur->next = tmp->next;
	tmp->next = tmp;
	*b = tmp;
}
