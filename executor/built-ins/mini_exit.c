/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:32:15 by nelisabe          #+#    #+#             */
/*   Updated: 2020/12/26 13:11:38 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"
#include <errno.h>
#include <string.h>

static int		error_too_many_args(int mode)
{
	if (mode != 1)
		write(2, "exit\n", 5);
	write(2, "minishell: exit: too many arguments\n", 36);
	return (1);
}

static int		error_numeric_argument(char *wrong_argument, char **args, \
	t_envp **envp_list, int mode)
{
	if (mode != 1)
		write(2, "exit\n", 5);
	write(2, "minishell: exit: ", 17);
	write(2, wrong_argument, ft_strlen(wrong_argument));
	write(2, ": numeric argument required\n", 28);
	remove_terminal_mode();
	envp_lst_clear(envp_list, free);
	free_matrix(args);
	return (2);
}

static int		check_overflow(long int code, char *argument)
{
	int			str_len;
	int			num_len;

	if (!ft_strcmp(argument, "9223372036854775808"))
		return (1);
	if (!ft_strcmp(argument, "-9223372036854775808"))
		return (0);
	str_len = ft_strlen(argument);
	num_len = 1;
	if ((argument[0] == '+' && code < 0) || (argument[0] != '-' && code < 0))
		return (1);
	if (argument[0] == '+')
		str_len--;
	if (code < 0)
	{
		code *= -1;
		str_len--;
	}
	while ((code /= 10) > 0)
		num_len++;
	if (str_len != num_len)
		return (1);
	return (0);
}

static long int	norm_exit(long int code, char **args, t_envp **envp_list, \
	int mode)
{
	if (args[1] && check_overflow(code, args[1]))
		return (error_numeric_argument(args[1], args, envp_list, mode));
	if (mode != 1)
	{
		write(2, "exit\n", 5);
		remove_terminal_mode();
	}
	envp_lst_clear(envp_list, free);
	free_matrix(args);
	return (code);
}

int				mini_exit(char **args, t_envp **envp_list, int mode)
{
	int			index;

	index = -1;
	errno = 0;
	if (args[1])
	{
		if (!args[2])
		{
			while (args[1][++index])
				if (!ft_isdigit(args[1][index]) && !(index == 0 && \
					(args[1][index] == '-' || args[1][index] == '+')))
					break ;
			if (args[1][index] == '\0')
				exit(norm_exit(ft_atol(args[1]), args, envp_list, mode));
			else
				exit(error_numeric_argument(args[1], args, envp_list, mode));
		}
		else
			return (error_too_many_args(mode));
	}
	exit(norm_exit(0, args, envp_list, mode));
}
