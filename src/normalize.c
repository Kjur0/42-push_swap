/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:03:46 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 19:48:58 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <normalize.h>

void	normalize_stack(t_list *stack)
{
	t_list			*current;
	t_list			*other;
	t_stack_element	*value;

	current = stack;
	while (current)
	{
		other = stack;
		value = (t_stack_element *)current->content;
		value->index = 0;
		while (other)
		{
			if (((t_stack_element *)other->content)->number < value->number)
				value->index++;
			other = other->next;
		}
		current = current->next;
	}
}
