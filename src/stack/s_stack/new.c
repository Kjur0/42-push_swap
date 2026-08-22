/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:25:51 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:18:08 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/s_stack.h>

#include <malloc.h>

//!TODO: docs
t_stack_element	*stack_new(int val)
{
	t_stack_element	*cur;

	cur = malloc(sizeof(t_stack_element));
	if (!cur)
		return (NULL);
	cur->meta = NULL;
	cur->n_val = 0;
	cur->val = val;
	return (cur);
}
