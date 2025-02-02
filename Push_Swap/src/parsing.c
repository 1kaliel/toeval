/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:06:37 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:06:38 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes a stack.
 *
 * This function sets the top of the stack to NULL and the 
 * size of the stack to 0, effectively initializing an empty stack.
 *
 * @param stack A pointer to the stack to be initialized.
 */
void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

/**
 * validate_and_push - Validates a number and pushes it onto the stack.
 * @stack: A pointer to the stack where the number will be pushed.
 * @num: A string representing the number to be validated and pushed.
 *
 * This function performs the following steps:
 * 1. Checks if the provided string is a valid number using is_valid_number().
 * 2. Converts the string to an integer using ft_atoi().
 * 3. Checks if the integer is a duplicate in the stack 
 * using contains_duplicate().
 * 4. If the number is valid and not a duplicate, it pushes the number 
 * onto the bottom of the stack using push_bottom().
 *
 * Return: 1 if the number is valid and successfully pushed onto the stack,
 *         0 if the number is invalid or a duplicate.
 */
int	validate_and_push(t_stack *stack, char *num)
{
	int	value;

	if (!is_valid_number(num))
		return (0);
	value = ft_atoi(num);
	if (contains_duplicate(stack, value))
		return (0);
	push_bottom(stack, value);
	return (1);
}

/**
 * parse_and_split - Parses the input string and splits it into 
 * individual numbers, then validates and pushes each number onto the stack.
 * @stack: A pointer to the stack where the numbers will be pushed.
 * @input: The input string containing numbers separated by spaces.
 *
 * This function splits the input string into an array of strings, 
 * each representing a number. It then iterates through the array, validating 
 * and pushing each number onto the stack. If any number is invalid,
 * the function frees the allocated memory and returns 0. If all 
 * numbers are successfully validated and pushed, the function frees the 
 * allocated memory and returns 1.
 *
 * Return: 1 if all numbers are successfully validated and pushed, 0 otherwise.
 */
int	parse_and_split(t_stack *stack, char *input)
{
	char	**numbers;
	int		i;

	numbers = ft_split(input, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!validate_and_push(stack, numbers[i]))
		{
			free_split(numbers);
			return (0);
		}
		i++;
	}
	free_split(numbers);
	return (1);
}

/**
 * @brief Parses the input arguments and initializes the stack.
 *
 * This function initializes the stack and processes the input arguments.
 * It trims any leading or trailing spaces from the input and checks if the
 * input is valid. If the input is valid, it proceeds to parse and split the
 * input into the stack.
 *
 * @param stack A pointer to the stack structure to be initialized and populated.
 * @param argv An array of input arguments.
 * @return Returns 1 if the input is successfully parsed and 
 * the stack is initialized, otherwise returns 0.
 */
int	parse_input(t_stack *stack, char **argv)
{
	char	*trimmed_input;

	init_stack(stack);
	if (!argv[1] || argv[1][0] == '\0')
		return (0);
	trimmed_input = ft_strtrim(argv[1], " ");
	if (!trimmed_input || ft_strlen(trimmed_input) == 0)
	{
		free(trimmed_input);
		return (0);
	}
	free(trimmed_input);
	if (!parse_and_split(stack, argv[1]))
		return (0);
	return (1);
}

/**
 * @brief Checks if the stack contains a duplicate of the given value.
 *
 * This function iterates through the stack to determine if any node
 * contains the specified value. If a duplicate is found, the function
 * returns 1. Otherwise, it returns 0.
 *
 * @param stack A pointer to the stack to be checked.
 * @param value The value to check for duplicates in the stack.
 * @return int Returns 1 if a duplicate is found, otherwise returns 0.
 */
int	contains_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}
