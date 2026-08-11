/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:05:56 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:14:02 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include <stack.h>

/** SWAP
 *
 * swap two first elements of a given stack
 *
 * @internal helper for: sa(), sb(), ss()
 * @author kjurkows
 * @param stack stack to push to
 * @retval 0 success
 * @retval 1 error
 */
int	swap(t_stack *stack);
/** PUSH
 *
 * push first element of a given stack to the top of another one
 *
 * @internal helper for: pa(), pb()
 * @author kjurkows
 * @param to	destination stack
 * @param from	source stack
 * @retval 0 success
 * @retval 1 error
 */
int	push(t_stack *to, t_stack *from);
/** ROTATE
 *
 * shift up all elements of a given stack by one
 *
 * The first element becomes the last one.
 *
 * @internal helper for: ra(), rb(), rr()
 * @author kjurkows
 * @param stack	stack to rotate
 * @retval 0 success
 * @retval 1 error
 */
int	rotate(t_stack *stack);
/** REVERSE ROTATE
 *
 * shift down all elements of a given stack by one
 *
 * The last element becomes the first one.
 *
 * @internal helper for: rra(), rrb(), rrr()
 * @author kjurkows
 * @param stack stack to rotate
 * @retval 0 success
 * @retval 1 error
 */
int	rrotate(t_stack *stack);

#endif
