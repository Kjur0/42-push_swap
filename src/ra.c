/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:12:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/07 02:47:50 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stacks.h>

/** @brief rotate a
 *
 * Shift up all elements of stack **a** by one.
 *
 * The first element becomes the last one.
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 */
int	ra(t_list **a)
{
	t_list	*first;
	t_list	*cur;

	first = *a;
	cur = *a;
	if (!cur || !cur->next)
		return (0);
	*a = cur->next;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
	ft_printf("ra\n");
	return (1);
}
