/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:58 by nelisabe          #+#    #+#             */
/*   Updated: 2020/12/01 13:49:29 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_commands	*comm_last_element(t_commands *commands)
{
	while (commands)
	{
		if (!(commands->next))
			break ;
		commands = commands->next;
	}
	return (commands);
}

t_commands	*comm_lst_new(char **args, int fd_in, int fd_out)
{
	t_commands	*new_element;

	if (!(new_element = (t_commands*)malloc(sizeof(t_commands))))
		return (NULL);
	new_element->command = args;
	new_element->fd_in = fd_in;
	new_element->fd_out = fd_out;
	new_element->next = NULL;
	return (new_element);
}

void		comm_lst_clr(t_commands **commands)
{
	t_commands	*temp;

	if (!commands)
		return ;
	while (*commands)
	{
		temp = (*commands)->next;
		free((*commands)->command);
		free(*commands);
		*commands = temp;
	}
	*commands = NULL;
}

void		comm_add_back(t_commands *command, t_commands **commands)
{
	t_commands	*temp;

	if (!(*commands))
		*commands = command;
	else
	{
		temp = comm_last_element(*commands);
		temp->next = command;
	}
}
