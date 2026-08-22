/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 18:24:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 22:09:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/s_stack.h>

#include <malloc.h>

//!TODO: docs
void	stack_free(t_stack	*stack)
{
	t_stack_element	*cur;
	t_stack_element	*nxt;

	if (!stack)
		return ;
	cur = stack->list;
	while (cur)
	{
		nxt = cur->next;
		if (cur->meta)
			free(cur->meta);
		free (cur);
		cur = nxt;
	}
	free(stack);
}
