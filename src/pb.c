/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:03:17 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/06 20:35:18 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

/** @brief push b
 * 
 * Take the first element at the top of a and put it at the top of b.
 * 
 * Do nothing if a is empty.
 * 
 * @internal
 * @author ppalamio
 * @param a 
 * @param b 
 */
void	pb(t_list *a, t_list *b)
{
	t_list	*node;

	if (!a || !a->next)
		return ;
	node = a->next;
	a->next = node->next;
	node->next = b->next;
	b->next = node;
}
