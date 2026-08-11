/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppalamio <ppalamio@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:40:23 by ppalamio          #+#    #+#             */
/*   Updated: 2026/08/11 18:29:52 by ppalamio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <bench.h>
#include <normalize.h>
#include <parse.h>

static void	free_split(char **split)
{
	int	index;

	if (!split)
		return ;
	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}

static int	add_number(t_list **stack, const char *token)
{
	int		value;
	t_list	*node;
	t_stack_element *heap;

	if (!ft_isdigit(*token) && *token != '-' && *token != '+')
		return (0);
	value = ft_atoi(token);
	node = *stack;
	while (node)
	{
		if (((t_stack_element *)node->content)->number == value)
			return (0);
		node = node->next;
	}
	heap = malloc(sizeof(*heap));
	if (!heap)
		return (0);
	heap->number = value;
	heap->index = 0;
	ft_lstadd_back(stack, ft_lstnew(heap));
	return (1);
}

static int	parse_option(const char *arg, t_options *options)
{
	if (ft_strncmp(arg, "--simple", 8) == 0 && arg[8] == '\0')
		options->algorithm = ALG_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 8) == 0 && arg[8] == '\0')
		options->algorithm = ALG_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 9) == 0 && arg[9] == '\0')
		options->algorithm = ALG_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 10) == 0 && arg[10] == '\0')
		options->algorithm = ALG_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 7) == 0 && arg[7] == '\0')
		options->bench_mode = 1;
	else
		return (0);
	return (1);
}

static int	parse_tokens(char *arg, t_list **stack)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!add_number(stack, split[j]))
		{
			free_split(split);
			return (0);
		}
		j++;
	}
	free_split(split);
	return (1);
}

int	parse(int argc, char **argv, t_options *options, t_list **stack)
{
	int	index;

	options->bench_mode = 0;
	options->algorithm = ALG_ADAPTIVE;
	index = 0;
	while (++index < argc)
	{
		if (argv[index][0] == '-' && argv[index][1] == '-')
		{
			if (!parse_option(argv[index], options) || ft_lstsize(*stack) > 0)
				return (0);
		}
		else if (!parse_tokens(argv[index], stack))
			return (0);
	}
	normalize_stack(*stack);
	return (1);
}
