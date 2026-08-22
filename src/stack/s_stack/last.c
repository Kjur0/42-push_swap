/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:39:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:18:06 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/s_stack.h>

//!TODO: docs
t_stack_element	*stack_last(t_stack	*stack)
{
	t_stack_element	*cur;

	cur = stack->list;
	if (!cur)
		return (cur);
	while (cur->next)
		cur = cur->next;
	return (cur);
}
