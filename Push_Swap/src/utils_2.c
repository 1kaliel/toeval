/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:36 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:34:34 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * move_smallest_to_top - Moves the smallest element in the stack to the top.
 * @stack: Pointer to the stack structure.
 * @index: Index of the smallest element in the stack.
 *
 * This function moves the smallest element in the stack to the top by either
 * rotating or reverse rotating the stack. If the index of the smallest element
 * is in the first half of the stack, it rotates the stack until the element
 * is at the top. If the index is in the second half, it reverse rotates the
 * stack until the element is at the top.
 */
void	move_smallest_to_top(t_stack *stack, int index)
{
	int	i;

	if (index <= stack->size / 2)
	{
		i = 0;
		while (i < index)
		{
			rotate(stack, "ra");
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack->size - index)
		{
			reverse_rotate(stack, "rra");
			i++;
		}
	}
}

/**
 * @brief Pushes the smallest element from stack 'a' to stack 'b'.
 *
 * This function finds the smallest element in stack 'a', moves it to the top
 * of the stack, and then pushes it onto stack 'b'.
 *
 * @param a Pointer to the source stack.
 * @param b Pointer to the destination stack.
 */
void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	smallest_index;

	smallest_index = find_smallest_index(a);
	move_smallest_to_top(a, smallest_index);
	push(a, b, "pb");
}

/**
 * find_smallest_index - Finds the index of the smallest value in a stack.
 * @stack: Pointer to the stack structure.
 *
 * This function iterates through the stack to find the smallest value and
 * returns the index of that value. The stack is assumed to be implemented
 * as a linked list with each node containing an integer value.
 *
 * Return: The index of the smallest value in the stack.
 */
int	find_smallest_index(t_stack *stack)
{
	t_node	*current;
	int		smallest;
	int		index;
	int		i;

	current = stack->top;
	smallest = current->value;
	index = 0;
	i = 0;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			index = i;
		}
		current = current->next;
		i++;
	}
	return (index);
}

/**
 * push_bottom - Adds a new node with the given value to the 
 * bottom of the stack.
 * @stack: A pointer to the stack where the new node will be added.
 * @value: The value to be stored in the new node.
 *
 * This function allocates memory for a new node, assigns the given value to it,
 * and adds it to the bottom of the stack. If the stack is empty, the new node
 * becomes the top of the stack. Otherwise, it traverses the stack to find the
 * last node and appends the new node to it. The size of the stack is 
 * incremented by one.
 */
void	push_bottom(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

/**
 * @brief Frees a dynamically allocated array of strings.
 *
 * This function takes a null-terminated array of strings (char pointers) and
 * frees each string in the array, then frees the array itself.
 *
 * @param split A null-terminated array of strings to be freed.
 */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
