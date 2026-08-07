/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/07 02:47:54 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stacks.h>

/** @brief rotate b
 *
 * Shift up all elements of stack **b** by one.
 *
 * The first element becomes the last one.
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
int	rb(t_list **b)
{
	t_list	*first;
	t_list	*cur;

	first = *b;
	cur = *b;
	if (!cur || !cur->next)
		return (0);
	*b = cur->next;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
	ft_printf("rb\n");
	return (1);
}
