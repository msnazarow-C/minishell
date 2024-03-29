/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:25:40 by nelisabe          #+#    #+#             */
/*   Updated: 2020/12/26 13:07:51 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"
#include <errno.h>

static int	check_flag(char *argument)
{
	int		index;

	index = -1;
	if (argument[++index] != '-')
		return (0);
	while (argument[++index])
		if (argument[index] != 'n')
			return (0);
	if (argument[index - 1] == '-')
		return (0);
	return (1);
}

int			mini_echo(char **args)
{
	int		index;
	int		temp;
	int		flag;

	errno = 0;
	index = 0;
	flag = 0;
	while (args[++index] && (temp = check_flag(args[index])))
		flag = temp;
	while (args[index])
	{
		write(1, args[index], ft_strlen(args[index]));
		if (args[index + 1])
			write(1, " ", 1);
		index++;
	}
	if (!flag)
		write(1, "\n", 1);
	return (0);
}
