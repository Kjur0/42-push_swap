/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:49:16 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:16:42 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <libft.h>

void	print_stack(const char *name, const t_list *stack);

/// @brief stack
typedef struct s_stack
{
	t_list	*list; ///< linked list
	size_t	size; ///< stack size
}	t_stack;

//# Stack operations

/** @brief swap a
 *
 * Swap the first two elements at the top of stack **a**.
 *
 * Do nothing if there is only one or no elements.
 *
 * @see swap()
 * @author kjurkows
 * @param a stack **a**
 * @retval 0 success
 * @retval 1 error
 */
int		sa(t_stack *a);
/** @brief swap b
 *
 * Swap the first two elements at the top of stack **b**
 *
 * Do nothing if there is only one or no elements
 *
 * @see swap()
 * @author kjurkows
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		sb(t_stack *b);
/** @brief swap a/b
 *
 * swap a & swap b at the same time
 *
 * @see swap()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		ss(t_stack *a, t_stack *b);
/** @brief push a
 *
 * Take the first element at the top of **b** and put it at the top of **a**.
 *
 * Do nothing if **b** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		pa(t_stack *a, t_stack *b);
/** @brief push b
 *
 * Take the first element at the top of **a** and put it at the top of **b**.
 *
 * Do nothing if **a** is empty.
 *
 * @see push()
 * @author ppalamio
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		pb(t_stack *a, t_stack *b);
/** @brief rotate a
 *
 * Shift up all elements of stack **a** by one.
 *
 * The first element becomes the last one.
 *
 * @see rotate()
 * @author kjurkows
 * @param a stack **a**
 * @retval 0 success
 * @retval 1 error
 */
int		ra(t_stack *a);
/** @brief rotate b
 *
 * Shift up all elements of stack **b** by one.
 *
 * The first element becomes the last one.
 *
 * @see rotate()
 * @author kjurkows
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		rb(t_stack *b);
/** @brief rotate a/b
 *
 * rotate a & rotate b at the same time
 *
 * @see rotate()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		rr(t_stack *a, t_stack *b);
/** @brief reverse rotate a
 *
 * Shift down all elements of stack **a** by one.
 *
 * The last element becomes the first one.
 *
 * @see rrotate()
 * @author kjurkows
 * @param a stack **a**
 * @retval 0 success
 * @retval 1 error
 */
int		rra(t_stack *a);
/** @brief reverse rotate b
 *
 * Shift down all elements of stack **b** by one.
 *
 * The last element becomes the first one.
 *
 * @see rrotate()
 * @author kjurkows
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		rrb(t_stack *b);
/** @brief reverse rotate a/b
 *
 * reverse rotate a & reverse rotate b at the same time
 *
 * @see rrotate()
 * @author kjurkows
 * @param a stack **a**
 * @param b stack **b**
 * @retval 0 success
 * @retval 1 error
 */
int		rrr(t_stack *a, t_stack *b);

#endif
