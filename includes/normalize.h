/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:10:09 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 17:48:31 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

typedef struct s_stack_element
{
	int	number;
	int	index;

}	t_stack_element;

void	normalize_stack(t_list *stack);
