/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:03:17 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/06 21:08:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief push b
 *
 * Take the first element at the top of **a** and put it at the top of **b**.
 *
 * Do nothing if **a** is empty.
 *
 * @internal
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 */
void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*a)
		return ;
	node = *a;
	*a = node->next;
	node->next = *b;
	*b = node;
}
