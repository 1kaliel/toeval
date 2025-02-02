/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:06:18 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:25:34 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack structure.
 * @operation: String representing the operation name to be printed.
 *
 * This function swaps the positions of the top two elements in the stack.
 * If the stack has fewer than two elements or is NULL, 
 * the function does nothing.
 * After swapping, it prints the operation name.
 */
void	swap(t_stack *stack, char *operation)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	ft_printf("%s\n", operation);
}

/**
 * push - Moves the top element from the source stack to the destination stack.
 * @src: Pointer to the source stack.
 * @dest: Pointer to the destination stack.
 * @operation: String representing the operation to be printed.
 *
 * This function removes the top element from the source stack and pushes it
 * onto the top of the destination stack. If the source stack is empty or NULL,
 * the function does nothing. After performing the push operation, it prints
 * the operation string.
 */
void	push(t_stack *src, t_stack *dest, char *operation)
{
	t_node	*temp;

	if (!src || src->size == 0)
		return ;
	temp = src->top;
	src->top = temp->next;
	src->size--;
	temp->next = dest->top;
	dest->top = temp;
	dest->size++;
	ft_printf("%s\n", operation);
}

/**
 * rotate - Rotates the elements of a stack upwards.
 * @stack: Pointer to the stack to be rotated.
 * @operation: String representing the operation name to be printed.
 *
 * This function moves the top element of the stack to the bottom,
 * effectively rotating all elements upwards by one position. If the
 * stack has fewer than two elements, the function does nothing.
 * After rotating, the function prints the operation name.
 */
void	rotate(t_stack *stack, char *operation)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("%s\n", operation);
}

/**
 * reverse_rotate - Moves the last element of the stack to the top.
 * @stack: A pointer to the stack structure.
 * @operation: A string representing the operation name to be printed.
 *
 * This function performs a reverse rotation on the stack. It moves the last
 * element of the stack to the top and prints the operation name. If the stack
 * is NULL or has fewer than 2 elements, the function does nothing.
 */
void	reverse_rotate(t_stack *stack, char *operation)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	ft_printf("%s\n", operation);
}
