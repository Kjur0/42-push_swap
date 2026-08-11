/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:05:56 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/11 16:01:16 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include <libft.h>

int	swap(t_list **stack);
int	push(t_list **to, t_list **from);
int	rotate(t_list **stack);
int	rrotate(t_list **stack);

#endif
