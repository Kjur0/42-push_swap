/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:49:16 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/06 21:10:15 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <libft.h>

/** @brief swap a
 *
 * Swap the first two elements at the top of stack **a**.
 *
 * Do nothing if there is only one or no elements.
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 */
void	sa(t_list **a);
/** @brief swap b
 *
 * Swap the first two elements at the top of stack **b**
 *
 * Do nothing if there is only one or no elements
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
void	sb(t_list **b);
/** @brief swap a/b
 *
 * swap a & swap b at the same time
 *
 * @internal
 * @see sa()
 * @see sb()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 */
void	ss(t_list **a, t_list **b);
/** @brief push a
 *
 * Take the first element at the top of **b** and put it at the top of **a**.
 *
 * Do nothing if **b** is empty.
 *
 * @internal
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 */
void	pa(t_list **a, t_list **b);
/** @brief push b
 *
 * Take the first element at the top of **a** and put it at the top of **b**.
 *
 * Do nothing if **a** is empty.
 *
 * @internal
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 */
void	pb(t_list **a, t_list **b);
/** @brief rotate a
 *
 * Shift up all elements of stack **a** by one.
 *
 * The first element becomes the last one.
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 */
void	ra(t_list **a);
/** @brief rotate b
 *
 * Shift up all elements of stack **b** by one.
 *
 * The first element becomes the last one.
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
void	rb(t_list **b);
/** @brief rotate a/b
 *
 * rotate a & rotate b at the same time
 *
 * @internal
 * @see ra()
 * @see rb()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 */
void	rr(t_list **a, t_list **b);
/** @brief reverse rotate a
 *
 * Shift down all elements of stack **a** by one.
 *
 * The last element becomes the first one.
 *
 * @internal
 * @author kjurkows
 * @param a stack **a**
 */
void	rra(t_list **a);
/** @brief reverse rotate b
 *
 * Shift down all elements of stack **b** by one.
 *
 * The last element becomes the first one.
 *
 * @internal
 * @author kjurkows
 * @param b stack **b**
 */
void	rrb(t_list **b);
/** @brief reverse rotate a/b
 *
 * reverse rotate a & reverse rotate b at the same time
 *
 * @internal
 * @see ra()
 * @see rb()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 */
void	rrr(t_list **a, t_list **b);

#endif
