/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:10:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:36:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/ops.h>

#include <libft.h>

/** @brief swap a/b
 *
 * swap a & swap b at the same time
 *
 * @see swap()
 * @author kjurkows
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	ss(t_stack *a, t_stack *b, bool print, t_bench *bench)
{
	if (swap(a))
		return (1);
	if (swap(b))
	{
		swap(a);
		return (1);
	}
	if (print)
		ft_putendl_fd("ss", 1);
	if (bench)
		bench->ops.ss++;
	return (0);
}
