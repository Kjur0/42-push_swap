/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:09:28 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 16:34:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

int	swap(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!head || !head->next)
		return (1);
	*stack = head->next;
	head->next = (*stack)->next;
	(*stack)->next = head;
	return (0);
}

int	push(t_list **to, t_list **from)
{
	t_list	*node;

	node = *from;
	if (!node)
		return (1);
	*from = node->next;
	node->next = *to;
	*to = node;
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*tail;

	tail = ft_lstlast(*stack);
	if (!tail)
		return (1);
	tail->next = *stack;
	*stack = (*stack)->next;
	tail->next->next = NULL;
	return (0);
}

int	rrotate(t_list **stack)
{
	t_list	*tail;

	tail = *stack;
	if (!tail)
		return (1);
	while (tail->next && tail->next->next)
		tail = tail->next;
	if (!tail->next)
		return (1);
	tail->next->next = *stack;
	*stack = tail->next;
	tail->next = NULL;
	return (0);
}
