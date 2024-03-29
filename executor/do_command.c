/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:10:57 by nelisabe          #+#    #+#             */
/*   Updated: 2020/12/27 05:31:24 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <termios.h>

int		save_ret_value(int value, t_envp **envp_list)
{
	char	*value_to_save;
	char	*temp;

	if (!(temp = ft_itoa(value)))
		return (error_print_return(NULL));
	if (!(value_to_save = envp_create_envp_str("?", temp)))
	{
		free(temp);
		return (error_print_return(NULL));
	}
	free(temp);
	if (envp_replace_variable(envp_list, value_to_save, 0))
	{
		free(value_to_save);
		return (error_print_return(NULL));
	}
	return (0);
}

int		do_command(char **args, t_envp **envp_list)
{
	int			return_value;
	t_commands	*commands;

	if (!(return_value = parse_command_ex(args, &commands, *envp_list)))
	{
		if ((return_value = run_commands(commands, envp_list)))
		{
			comm_lst_clr(&commands);
			if (check_fatal_error(return_value))
				exit_fatal(return_value, args, envp_list);
		}
	}
	else
	{
		if (check_fatal_error(return_value))
			exit_fatal(return_value, args, envp_list);
	}
	comm_lst_clr(&commands);
	if (save_ret_value(return_value, envp_list))
		exit_fatal(12, args, envp_list);
	return (return_value);
}
