/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:11 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:07:12 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * @brief Sorts a stack of two elements in ascending order.
 *
 * This function checks the top two elements of the stack 'a'. 
 * If the top element is greater than the next element, it swaps them using 
 * the 'swap' function.
 *
 * @param a Pointer to the stack to be sorted.
 */
void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap(a, "sa");
}

/**
 * sort_three - Sorts a stack of three elements in ascending order.
 * @a: Pointer to the stack to be sorted.
 *
 * This function sorts a stack of exactly three elements using a series of 
 * comparisons and stack operations. The possible operations include swapping 
 * the top two elements, rotating the stack, and reverse rotating the stack. 
 * The function determines the correct sequence of operations based on the 
 * values of the top three elements of the stack.
 *
 * The stack operations used are:
 * - swap(a, "sa"): Swaps the top two elements of the stack.
 * - rotate(a, "ra"): Rotates the stack so that the top element becomes the 
 *   bottom element.
 * - reverse_rotate(a, "rra"): Rotates the stack so that the bottom element 
 *   becomes the top element.
 */
void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		swap(a, "sa");
	else if (first > second && second > third)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (first > second && second < third && first > third)
		rotate(a, "ra");
	else if (first < second && second > third && first < third)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, "rra");
}

/**
 * @brief Sorts a stack of four elements.
 *
 * This function sorts a stack of four elements by first pushing the smallest
 * element to another stack, sorting the remaining three elements, and then
 * pushing the smallest element back to the original stack.
 *
 * @param a Pointer to the stack to be sorted.
 * @param b Pointer to an auxiliary stack used for sorting.
 */
void	sort_four(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	sort_three(a);
	push(b, a, "pa");
}

/**
 * @brief Sorts a stack of five elements using an auxiliary stack.
 *
 * This function sorts a stack `a` containing five elements by 
 * using an auxiliary stack `b`.
 * It first pushes the two smallest elements from `a` to `b`, sorts the 
 * remaining three elements in `a`, and then pushes the two smallest 
 * elements back from `b` to `a`.
 *
 * @param a Pointer to the main stack to be sorted.
 * @param b Pointer to the auxiliary stack used for sorting.
 */
void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_three(a);
	push(b, a, "pa");
	push(b, a, "pa");
}

/**
 * @brief Sorts a stack of four or five elements.
 *
 * This function sorts a stack `a` containing either four or five elements by
 * utilizing helper functions `sort_four` and `sort_five`. If the stack `a`
 * contains four elements, it calls `sort_four`. If the stack `a` contains five
 * elements, it calls `sort_five`.
 *
 * @param a Pointer to the stack to be sorted.
 * @param b Pointer to an auxiliary stack used during sorting.
 */
void	sort_four_five(t_stack *a, t_stack *b)
{
	if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}
