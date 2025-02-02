/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:06:53 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:06:55 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * radix_sort - Sorts a stack using the radix sort algorithm.
 * @a: Pointer to the stack to be sorted.
 * @b: Pointer to an auxiliary stack used during sorting.
 *
 * This function sorts the stack 'a' using the radix sort algorithm.
 * It first maps the values in the stack to their respective indexes.
 * Then, it determines the maximum number of bits required to represent
 * the largest index. The sorting process involves iterating through each
 * bit position and partitioning the elements based on the current bit.
 * Elements with a 0 in the current bit position are pushed to stack 'b',
 * while elements with a 1 are rotated within stack 'a'. After processing
 * all elements for the current bit position, elements in stack 'b' are
 * pushed back to stack 'a'. This process is repeated for each bit position
 * until the stack is sorted.
 */
void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	max_bits;
	int	bit_index;

	map_values_to_indexes(a);
	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		bit_index = 0;
		while (bit_index++ < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				push(a, b, "pb");
			else
				rotate(a, "ra");
		}
		while (b->size > 0)
			push(b, a, "pa");
	}
}

/**
 * extract_values_to_array - Extracts values from a stack into an array.
 * @stack: A pointer to the stack from which values are to be extracted.
 *
 * This function allocates memory for an array of integers with the same size
 * as the stack. It then iterates through the stack, copying each value from
 * the stack into the array. If memory allocation fails, the function returns
 * NULL.
 *
 * Return: A pointer to the array of integers containing the stack values, or
 * NULL if memory allocation fails.
 */
int	*extract_values_to_array(t_stack *stack)
{
	t_node	*current;
	int		*values;
	int		i;

	values = ft_calloc(stack->size, sizeof(int));
	if (!values)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	return (values);
}

/**
 * @brief Assigns indexes to the nodes in the stack based on the 
 * given values array.
 *
 * This function iterates through each node in the stack and assigns an 
 * index to the node's value based on its position in the provided values array.
 * The index assigned is the position of the node's value in the values array.
 *
 * @param stack A pointer to the stack whose nodes' values will be indexed.
 * @param values An array of integers representing the values to be indexed.
 * @param size The size of the values array.
 */
void	assign_indexes(t_stack *stack, int *values, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == values[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

/**
 * @brief Maps the values in the stack to their corresponding indexes.
 *
 * This function takes a stack and maps its values to their corresponding
 * indexes based on their sorted order. It first extracts the values from
 * the stack into an array, sorts the array using quick sort, and then
 * assigns the sorted indexes back to the stack. Finally, it frees the
 * allocated memory for the array.
 *
 * @param stack A pointer to the stack whose values are to be mapped to indexes.
 *
 * @note If the stack is NULL or its size is 0, the function returns immediately.
 */
void	map_values_to_indexes(t_stack *stack)
{
	int	*values;

	if (!stack || stack->size == 0)
		return ;
	values = extract_values_to_array(stack);
	if (!values)
		return ;
	quick_sort_array(values, 0, stack->size - 1);
	assign_indexes(stack, values, stack->size);
	free(values);
}
