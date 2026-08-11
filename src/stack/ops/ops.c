/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:09:28 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:17:40 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

/** SWAP
 *
 * swap two first elements of a given stack
 *
 * @internal helper for: sa(), sb(), ss()
 * @author kjurkows
 * @param stack stack to swap inside
 * @retval 0 success
 * @retval 1 error
 */
int	swap(t_stack *stack)
{
	t_list	*head;

	if (stack->size < 2)
		return (1);
	head = stack->list;
	stack->list = head->next;
	head->next = stack->list->next;
	stack->list->next = head;
	return (0);
}

/** PUSH
 *
 * push first element of a given stack to the top of another one
 *
 * @internal helper for: pa(), pb()
 * @author kjurkows
 * @param to	destination stack
 * @param from	source stack
 * @retval 0 success
 * @retval 1 error
 */
int	push(t_stack *to, t_stack *from)
{
	t_list	*node;

	if (from->size < 1)
		return (1);
	node = from->list;
	from->list = node->next;
	node->next = to->list;
	to->list = node;
	from->size--;
	to->size++;
	return (0);
}

/** ROTATE
 *
 * shift up all elements of a given stack by one
 *
 * The first element becomes the last one.
 *
 * @internal helper for: ra(), rb(), rr()
 * @author kjurkows
 * @param stack	stack to rotate
 * @retval 0 success
 * @retval 1 error
 */
int	rotate(t_stack *stack)
{
	t_list	*tail;

	tail = ft_lstlast(stack->list);
	if (!tail)
		return (1);
	tail->next = stack->list;
	stack->list = stack->list->next;
	tail->next->next = NULL;
	return (0);
}

/** REVERSE ROTATE
 *
 * shift down all elements of a given stack by one
 *
 * The last element becomes the first one.
 *
 * @internal helper for: rra(), rrb(), rrr()
 * @author kjurkows
 * @param stack stack to rotate
 * @retval 0 success
 * @retval 1 error
 */
int	rrotate(t_stack *stack)
{
	t_list	*tail;

	if (stack->size < 2)
		return (1);
	tail = stack->list;
	while (tail->next && tail->next->next)
		tail = tail->next;
	tail->next->next = stack->list;
	stack->list = tail->next;
	tail->next = NULL;
	return (0);
}
