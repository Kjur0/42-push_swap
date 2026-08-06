/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:01:44 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/06 21:08:19 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief push a
 *
 * Take the first element at the top of **b** and put it at the top of **a**.
 *
 * Do nothing if **b** is empty.
 *
 * @internal
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 */
void	pa(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*b)
		return ;
	node = *b;
	*b = node->next;
	node->next = *a;
	*a = node;
}
