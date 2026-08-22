/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:43:24 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 19:54:38 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

#ifdef TEST

# include <ft_printf.h>
# include <normalize.h>

void	print_stack(const char *name, const t_stack_element *stack)
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

void	print_stack(const char *name, const t_stack_element *stack)
{
	(void)name;
	(void)stack;
}

#endif
