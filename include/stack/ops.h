/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:37:01 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:48:28 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO: re: docs

#ifndef OPS_H
# define OPS_H

# include <stack/s_stack.h>

# include <bench.h>

# include <stdbool.h>

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

/** @brief swap a
 *
 * Swap the first two elements at the top of stack **a**.
 *
 * Do nothing if there is only one or no elements.
 *
 * @see swap()
 * @author kjurkows
 * @param a		stack **a**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	sa(t_stack *a, bool print, t_bench *bench);
/** @brief swap b
 *
 * Swap the first two elements at the top of stack **b**
 *
 * Do nothing if there is only one or no elements
 *
 * @see swap()
 * @author kjurkows
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	sb(t_stack *b, bool print, t_bench *bench);
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
int	ss(t_stack *a, t_stack *b, bool print, t_bench *bench);
/** @brief push a
 *
 * Take the first element at the top of **b** and put it at the top of **a**.
 *
 * Do nothing if **b** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	pa(t_stack *a, t_stack *b, bool print, t_bench *bench);
/** @brief push b
 *
 * Take the first element at the top of **a** and put it at the top of **b**.
 *
 * Do nothing if **a** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	pb(t_stack *a, t_stack *b, bool print, t_bench *bench);
/** @brief rotate a
 *
 * Shift up all elements of stack **a** by one.
 *
 * The first element becomes the last one.
 *
 * @see rotate()
 * @author kjurkows
 * @param a		stack **a**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	ra(t_stack *a, bool print, t_bench *bench);
/** @brief rotate b
 *
 * Shift up all elements of stack **b** by one.
 *
 * The first element becomes the last one.
 *
 * @see rotate()
 * @author kjurkows
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rb(t_stack *b, bool print, t_bench *bench);
/** @brief rotate a/b
 *
 * rotate a & rotate b at the same time
 *
 * @see rotate()
 * @author kjurkows
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rr(t_stack *a, t_stack *b, bool print, t_bench *bench);
/** @brief reverse rotate a
 *
 * Shift down all elements of stack **a** by one.
 *
 * The last element becomes the first one.
 *
 * @see rrotate()
 * @author kjurkows
 * @param a		stack **a**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rra(t_stack *a, bool print, t_bench *bench);
/** @brief reverse rotate b
 *
 * Shift down all elements of stack **b** by one.
 *
 * The last element becomes the first one.
 *
 * @see rrotate()
 * @author kjurkows
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rrb(t_stack *b, bool print, t_bench *bench);
/** @brief reverse rotate a/b
 *
 * reverse rotate a & reverse rotate b at the same time
 *
 * @see rrotate()
 * @author kjurkows
 * @param a		stack **a**
 * @param b		stack **b**
 * @param print	whether it should print the operation to `STDOUT`
 * @retval 0 success
 * @retval 1 error
 */
int	rrr(t_stack *a, t_stack *b, bool print, t_bench *bench);

#endif
