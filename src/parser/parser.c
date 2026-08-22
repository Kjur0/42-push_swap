/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:40:23 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/22 22:10:14 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stack/normalize.h>

#include <libft.h>

#include <malloc.h>

//!TODO: docs
static void	options_init(t_options *opts)
{
	opts->algorithm = ALG_ADAPTIVE;
	opts->bench_mode = false;
}

//!TODO: docs
static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

//!TODO: docs
static int	parse_option(const char *arg, t_options *opts, t_stack *a)
{
	if (ft_strncmp(arg, "--simple", 8) == 0 && arg[8] == '\0')
		opts->algorithm = ALG_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 8) == 0 && arg[8] == '\0')
		opts->algorithm = ALG_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 9) == 0 && arg[9] == '\0')
		opts->algorithm = ALG_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 10) == 0 && arg[10] == '\0')
		opts->algorithm = ALG_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 7) == 0 && arg[7] == '\0')
		opts->bench_mode = 1;
	else
	{
		stack_free(a);
		return (1);
	}
	return (0);
}

//!TODO: docs
static int	parse_tokens(char *arg, t_stack	*a)
{
	char			**split;
	int				i;
	t_stack_element	*tmp;

	split = ft_split(arg, ' ');
	if (!split)
	{
		stack_free(a);
		return (1);
	}
	i = 0;
	while (split[i])
	{
		tmp = stack_new(ft_atoi(split[i++]));
		if (!tmp)
		{
			free_split(split);
			stack_free(a);
			return (1);
		}
		stack_add_back(a, tmp);
	}
	free_split(split);
	return (0);
}

//!TODO: docs
t_stack	*parse(int argc, char **argv, t_options *opts)
{
	int		i;
	t_stack	*a;

	options_init(opts);
	a = stack_init();
	if (!a)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (parse_option(argv[i], opts, a))
				return (NULL);
		}
		else if (parse_tokens(argv[i], a))
			return (NULL);
		i++;
	}
	if (normalize_stack(a))
	{
		stack_free(a);
		return (NULL);
	}
	return (a);
}
