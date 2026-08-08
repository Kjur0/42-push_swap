/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:43:24 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/08 11:10:46 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

#ifdef TEST

# include <ft_printf.h>

void	print_stack(const char *name, const t_list *stack)
{
	ft_printf("[STACK %s]:", name);
	while (stack)
	{
		ft_printf(" %d", *(const int *)stack->content);
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
