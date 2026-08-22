/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 19:57:05 by kjurkows          #+#    #+#             */
/*   Updated: 2026/08/22 22:39:31 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack/normalize.h>

#include <libft.h>

#include <malloc.h>

static size_t	partition(int *arr, size_t low, size_t high)
{
	const int	pivot = arr[high];
	size_t		i;
	size_t		j;
	int			tmp;

	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
		}
		j++;
	}
	tmp = arr[i];
	arr[i] = arr[high];
	arr[high] = tmp;
	return (i);
}

static void	ft_sort(int *arr, size_t low, size_t high)
{
	size_t	pivot;

	if (low >= high || low < 0)
		return ;
	pivot = partition(arr, low, high);
	if (pivot != 0)
		ft_sort(arr, low, pivot - 1);
	ft_sort(arr, pivot + 1, high);
}

static bool	find_repeat(int *arr, size_t size)
{
	size_t	i;

	i = 1;
	while (i < size)
	{
		if (arr[i - 1] == arr[i])
			return (true);
		i++;
	}
	return (false);
}

static size_t	ft_find(int	*arr, size_t size, int val)
{
	size_t	low;
	size_t	high;
	size_t	middle;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		middle = low + (high - low) / 2;
		if (arr[middle] < val)
			low = middle + 1;
		else if (arr[middle] > val)
			high = middle - 1;
		else
			return (middle);
	}
	return (size);
}

int	normalize_stack(t_stack *stack)
{
	int				*values;
	t_stack_element	*cur;
	size_t			i;

	values = ft_calloc(stack->size, sizeof(int));
	cur = stack->list;
	i = 0;
	while (cur)
	{
		values[i++] = cur->val;
		cur = cur->next;
	}
	ft_sort(values, 0, stack->size - 1);
	i = 0;
	if (find_repeat(values, stack->size))
		return (1);
	cur = stack->list;
	while (cur)
	{
		cur->n_val = ft_find(values, stack->size, cur->val);
		cur = cur->next;
	}
	free(values);
	return (0);
}
