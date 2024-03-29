/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:56:00 by sgertrud          #+#    #+#             */
/*   Updated: 2021/01/02 11:59:29 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_end_arg(char c)
{
	return (c == '\n' || c == ';' || c == '&' || c == '|' || c == '>' ||
	c == '<' || c == ' ' || c == 0 || c == ')' || c == '(');
}

int	check_end_command(char c)
{
	return (c == '\n' || c == ';' || c == '&' || c == 0);
}

int	check_sc(char c)
{
	return (c == '|' || c == '>' || c == '<' || c == ';' || c == '&' || c == '('
	|| c == ')' || c == '*' || c == '?' || c == '\\');
}

int	check_and_or(char c, char h)
{
	return (c == h && (h == '|' || h == '&'));
}

int	check_wild(char *str)
{
	while (*str)
	{
		if (*str == '*' || *str == '?')
			return (1);
		str++;
	}
	return (0);
}
