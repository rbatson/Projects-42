/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:09:30 by rbatson           #+#    #+#             */
/*   Updated: 2022/03/22 12:14:44 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_global_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			ft_pb(stacks, 1);
			if (stacks->b->data > stacks->med)
				ft_rb(&stacks->b, 1);
		}
		else
			ft_ra(&stacks->a, 1);
	}
	if (stacks->a->data < stacks->a->next->data)
		ft_sa(stacks->a, 1);
	ft_pa(stacks, 1);
	ft_start_sort(stacks);
}

void	ft_start_sort(t_stacks *stacks)
{
	t_steps	*step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!step)
		exit(1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_markup(stacks->a, stacks->count_a);
		ft_steps_markup(stacks->b, stacks->count_b);
		ft_minimum_insertion_steps(stacks, step);
		ft_instruction_execution(stacks, step);
	}
	if ((ft_count_to_min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->data != stacks->min)
			ft_rra(&stacks->a, 1);
	}
	else
		while (stacks->a->data != stacks->min)
			ft_ra(&stacks->a, 1);
	free(step);
}

void	ft_steps_markup(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

void	ft_minimum_insertion_steps(t_stacks *stacks, t_steps *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_action = ft_finding_place(stacks, stacks->b, steps, min_action);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

void	ft_instruction_execution(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&stacks->a, 1);
		else
			ft_rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&stacks->b, 1);
		else
			ft_rrb(&stacks->b, 1);
		steps->count_b--;
	}
	ft_pa(stacks, 1);
}
