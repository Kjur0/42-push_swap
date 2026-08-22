/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:40:15 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 22:09:54 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stddef.h>
# include <stdbool.h>

//!TODO: docs
typedef struct s_stack_element
{
	void					*meta;
	struct s_stack_element	*next;
	size_t					n_val; ///< normal value
	int						val; ///< value
}	t_stack_element;

/// @brief stack
typedef struct s_stack
{
	t_stack_element	*list; ///< linked list
	size_t			size; ///< stack size
}	t_stack;

//!TODO: docs
t_stack			*stack_init(void);

//!TODO: docs
void			stack_free(t_stack	*stack);

//!TODO: docs
t_stack_element	*stack_new(int val);

//!TODO: docs
void			stack_add_front(t_stack *stack, t_stack_element *el);

//!TODO: docs
void			stack_add_back(t_stack *stack, t_stack_element *el);

//!TODO: docs
t_stack_element	*stack_last(t_stack	*stack);

#endif
