/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:31:56 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 20:46:39 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <disorder.h>
#include <normalize.h>

/** @brief calculate disorder metric
 *
 * disorder metric is a scale from 0 to 1:
 * where 0 means the stack is sorted, and 1 means the stack is unsorted
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 * @return disorder metric of a stack
 */
double	calculate_disorder(t_list **a)
{
	int			mistakes;
	int			total_pairs;
	t_list		*i;
	t_list		*j;

	mistakes = 0;
	total_pairs = 0;
	i = *a;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if(((t_stack_element *)i->content)->index > ((t_stack_element *)j->content)->index)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}
