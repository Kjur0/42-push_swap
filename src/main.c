/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:48:45 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 23:23:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!TODO: fix

#include <stdlib.h>
#include <libft.h>
#include <stack.h>
#include <algorithms.h>
#include <disorder.h>
#include <bench.h>
#include "parser/parser.h"
#include <ft_printf.h>

// static t_algorithm	select_algorithm(t_algorithm requested, double disorder)
// {
// 	if (disorder == 0)
// 		return (ALG_NONE);
// 	if (requested != ALG_ADAPTIVE)
// 		return (requested);
// 	if (disorder < 0.2)
// 		return (ALG_SIMPLE);
// 	if (disorder < 0.5)
// 		return (ALG_MEDIUM);
// 	return (ALG_COMPLEX);
// }

// static t_op_counts	run_algorithm(t_algorithm algorithm, t_stack *a,
// t_stack *b)
// {
// 	if (algorithm == ALG_NONE)
// 		return (init_op_counts());
// 	else if (algorithm == ALG_SIMPLE)
// 		return (simple(a, b));
// 	else if (algorithm == ALG_MEDIUM)
// 		return (medium(a, b));
// 	else if (algorithm == ALG_COMPLEX)
// 		return (complex(a, b));
// 	return (init_op_counts());
// }

// static int	process_stack(t_stack *a, t_stack *b, t_options *options)
// {
// 	t_bench		bench;
// 	double		disorder;
// 	t_algorithm	algorithm;
// 	t_op_counts	ops;

// 	disorder = calculate_disorder(a);
// 	algorithm = select_algorithm(options->algorithm, disorder);
// 	ops = run_algorithm(algorithm, a, b);
// 	bench.disorder = disorder;
// 	if (algorithm == ALG_NONE)
// 		bench.strategy = get_strategy(algorithm, disorder);
// 	else
// 		bench.strategy = get_strategy(options->algorithm, disorder);
// 	bench.total_ops = total_op_count(&ops);
// 	bench.ops = ops;
// 	if (options->bench_mode)
// 		print_bench(&bench);
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_options	options;

	a = parse(argc, argv, &options);
	b = stack_init();
	if (!a || !b)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	complex(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
