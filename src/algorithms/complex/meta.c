/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:17:44 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 22:00:59 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"

//!TODO: move to header
void			*find_target(t_stack_element *node, t_stack *b);
void			recalculate_meta_a(t_stack *a, t_stack *b);
void			*find_landing(t_stack_element *node, t_stack *a);
void			recalculate_meta_b(t_stack *a, t_stack *b);
t_stack_element	*find_cheapest(t_stack_element *el);

//!TODO: docs
t_stack_element	*recalculate_meta1(t_stack *a, t_stack *b)
{
	recalculate_meta_a(a, b);
	recalculate_meta_b(a, b);
	return (find_cheapest(a->list));
}

//!TODO: docs
t_stack_element	*recalculate_meta2(t_stack *a, t_stack *b)
{
	recalculate_meta_a(a, b);
	recalculate_meta_b(a, b);
	return (find_cheapest(b->list));
}

//!TODO: docs
t_stack_element	*find_minimum(t_stack *a)
{
	t_stack_element	*min;
	t_stack_element	*cur;

	cur = a->list;
	min = cur;
	while (cur)
	{
		if (min->n_val > cur->n_val)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

//!TODO: docs
t_stack_element	*recalculate_meta3(t_stack *a)
{
	recalculate_meta_a(a, NULL);
	return (find_minimum(a));
}
