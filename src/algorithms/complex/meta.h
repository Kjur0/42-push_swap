/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:18:19 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 22:01:11 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_H
# define META_H

# include <stack/s_stack.h>

# include <stddef.h>
# include <stdbool.h>

//!TODO: docs
typedef struct s_meta
{
	t_stack_element		*target; ///< best target
	size_t				idx; ///< index
	size_t				cost; ///< cost
	bool				median; ///< above median
}	t_meta;

//!TODO: docs
t_stack_element	*recalculate_meta1(t_stack *a, t_stack *b);
//!TODO: docs
t_stack_element	*recalculate_meta2(t_stack *a, t_stack *b);
//!TODO: docs
t_stack_element	*recalculate_meta3(t_stack *a);

#endif
