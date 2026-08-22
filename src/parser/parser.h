/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:40:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 21:17:18 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stack/s_stack.h>
# include <stdbool.h>

//!TODO: docs
typedef enum e_algorithm
{
	ALG_NONE,
	ALG_SIMPLE,
	ALG_MEDIUM,
	ALG_COMPLEX,
	ALG_ADAPTIVE
}	t_algorithm;

//!TODO: docs
typedef struct s_options
{
	bool			bench_mode;
	t_algorithm		algorithm;
}	t_options;

//!TODO: docs
t_stack	*parse(int argc, char **argv, t_options *opts);

#endif
