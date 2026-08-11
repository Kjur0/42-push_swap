/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:43:24 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 20:48:19 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

#ifdef TEST

# include <ft_printf.h>
# include <normalize.h>

void	print_stack(const char *name, const t_list *stack)
{
	ft_printf("[STACK %s]:", name);
	while (stack)
	{
		ft_printf(" %d:%d", ((const t_stack_element *)stack->content)->index,
			((const t_stack_element *)stack->content)->number);
		stack = stack->next;
	}
	ft_printf("\n");
}
#else

void	print_stack(const char *name, const t_list *stack)
{
	(void)name;
	(void)stack;
}

#endif
