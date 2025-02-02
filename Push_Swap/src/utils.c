/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:55 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:36:06 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * @brief Frees all nodes in the stack and resets the stack.
 *
 * This function iterates through all the nodes in the stack, 
 * clears their memory using ft_bzero, and then frees the memory 
 * allocated for each node. After all nodes are freed, it resets 
 * the stack's top pointer to NULL and its size to 0.
 *
 * @param stack A pointer to the stack to be freed.
 */
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack->top;
	while (current)
	{
		tmp = current->next;
		ft_bzero(current, sizeof(t_node));
		free(current);
		current = tmp;
	}
	stack->top = NULL;
	stack->size = 0;
}

/**
 * partition - Partitions the array for quicksort.
 * @arr: The array to be partitioned.
 * @low: The starting index of the array segment to be partitioned.
 * @high: The ending index of the array segment to be partitioned.
 *
 * This function takes the last element as pivot, places the pivot element
 * at its correct position in the sorted array, and places all smaller
 * elements to the left of the pivot and all greater elements to the right
 * of the pivot.
 *
 * Return: The index of the pivot element after partitioning.
 */
int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

/**
 * @brief Sorts an array of integers using the Quick Sort algorithm.
 *
 * This function sorts the elements of the array in ascending order
 * by recursively partitioning the array and sorting the subarrays.
 *
 * @param arr The array of integers to be sorted.
 * @param low The starting index of the array to be sorted.
 * @param high The ending index of the array to be sorted.
 */
void	quick_sort_array(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort_array(arr, low, pivot_index - 1);
		quick_sort_array(arr, pivot_index + 1, high);
	}
}

/**
 * is_valid_number - Checks if a given string represents a valid number.
 * @str: The string to be checked.
 *
 * This function verifies if the input string is a valid number. A valid number
 * can optionally start with a '+' or '-' sign followed by digits. 
 * If the string is NULL or empty, or if it contains any non-digit 
 * characters (excluding the optional sign at the beginning), the function 
 * returns 0 (false). 
 * Otherwise, it returns 1 (true).
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
