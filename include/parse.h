/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:19:32 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/08 15:24:20 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <bench.h>
# include <libft.h>

typedef enum e_algorithm
{
	ALG_NONE,
	ALG_SIMPLE,
	ALG_MEDIUM,
	ALG_COMPLEX,
	ALG_ADAPTIVE
}	t_algorithm;

typedef struct s_options
{
	int				bench_mode;
	t_algorithm		algorithm;
}	t_options;

int				parse(int argc, char **argv, t_options *options,
					t_list **a);
const char		*get_strategy(t_algorithm selected, double disorder);
void			print_bench(const t_bench *bench);

#endif
