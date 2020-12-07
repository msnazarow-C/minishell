/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_terminal_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:50:48 by sgertrud          #+#    #+#             */
/*   Updated: 2020/12/07 18:31:09 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "parse.h"
#include <term.h>

int	remove_terminal_mode(void)
{
	t_term term;
	
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	tputs(exit_insert_mode, 1, ft_putchar);
	//tputs(exit_delete_mode, 1, ft_putchar);
	return (1);
}