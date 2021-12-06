/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:34:30 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:44 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	new_element(int num, t_color **elem, t_color *prev, t_color *next)
{
	*elem = malloc(sizeof(t_color));
	if (*elem == NULL)
		return (-1);
	(*elem)->color = num;
	(*elem)->prev = prev;
	(*elem)->next = next;
	return (1);
}

void	modify_element(t_color **elem, t_color *prev, t_color *next)
{
	if (prev)
		(*elem)->prev = prev;
	if (next)
		(*elem)->next = next;
}

int	add_my_element_to_my_stack(t_color **stacks, int num)
{
	t_color	*my_element;
	t_color	*first_element;
	t_color	*last_element;

	if (*stacks == NULL)
	{
		if (new_element(num, &my_element, NULL, NULL) == -1)
			return (-1);
		modify_element(&my_element, my_element, my_element);
		(*stacks) = my_element;
	}
	else
	{
		first_element = *stacks;
		last_element = (*stacks)->prev;
		if (new_element(num, &my_element, last_element, first_element) == -1)
			return (-1);
		first_element->prev = my_element;
		last_element->next = my_element;
	}
	return (1);
}

void	free_my_stack(t_color **my_stack)
{
	t_color	*current;
	t_color	*prev_element;

	if (*my_stack)
	{
		current = (*my_stack)->prev;
		prev_element = current->prev;
		while (prev_element != NULL && current != *my_stack)
		{
			free(current);
			current = prev_element;
			prev_element = current->prev;
		}
		free(current);
	}
}
