/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:28:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:37:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/s_stack.h>

//!TODO: docs
void	stack_add_front(t_stack *stack, t_stack_element *el)
{
	if (!stack || !el)
		return ;
	el->next = stack->list;
	stack->list = el;
	stack->size++;
}

//!TODO: docs
void	stack_add_back(t_stack *stack, t_stack_element *el)
{
	t_stack_element	*cur;

	if (!stack || !el)
		return ;
	stack->size++;
	if (!stack->list)
	{
		stack->list = el;
		return ;
	}
	cur = stack->list;
	while (cur->next)
		cur = cur->next;
	cur->next = el;
}
