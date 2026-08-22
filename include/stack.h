/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:49:16 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:19:38 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stack/s_stack.h>
# include <stack/ops.h>
# include <stack/normalize.h>

//!TODO: delete
void	print_stack(const char *name, const t_stack_element *stack);

#endif
