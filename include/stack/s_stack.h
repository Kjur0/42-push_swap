/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:40:15 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 17:40:34 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

/// @brief stack
typedef struct s_stack
{
	t_list	*list; ///< linked list
	size_t	size; ///< stack size
}	t_stack;

#endif
