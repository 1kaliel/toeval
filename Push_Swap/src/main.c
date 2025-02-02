/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:05:56 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:09:34 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @file main.c
 * @brief Entry point for the push_swap program.
 *
 * This file contains the main function which initializes the stacks,
 * parses the input, and calls the appropriate sorting function based
 * on the size of the stack.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 on success, 1 on error.
 *
 * The program expects a single input string as a command-line argument.
 * If the input is valid, it initializes two stacks and sorts the input
 * using different sorting algorithms based on the size of the stack.
 * After sorting, it frees the allocated memory for the stacks.
 */
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc != 2)
	{
		ft_printf("\033[33m⚠️ Please provide a single input string.\033[0m\n");
		return (0);
	}
	if (!parse_input(&a, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	init_stack(&b);
	if (a.size == 2)
		sort_two(&a);
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size == 4 || a.size == 5)
		sort_four_five(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
