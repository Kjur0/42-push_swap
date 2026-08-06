/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:01:44 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/06 20:35:16 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief push a
 * 
 * Take the first element at the top of b and put it at the top of a.
 * 
 * Do nothing if b is empty.
 * 
 * @internal
 * @author ppalamio
 * @param a	the start of the stack A
 * @param b	the start of the stack B
 */
void	pa(t_list *a, t_list *b)
{
	t_list	*node;

	if (!b || !b->next)
		return ;
	node = b->next;
	b->next = node->next;
	node->next = a->next;
	a->next = node;
}
