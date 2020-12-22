/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_curpos_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:01:12 by sgertrud          #+#    #+#             */
/*   Updated: 2020/12/22 03:41:51 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "termcap.h"

void	set_curpos_end(char *start, char *end)
{
	int len;
	int res;
	int len1;
	int term;

	term = get_term_size().x;
	len1 = ft_strlen_term(start) + MSH;
	len = ft_substrlen(end,&start[ft_strlen(start)]);
	if (len > 0)
	{
		res = len1 % get_term_size().x;
		tputs(tgoto(tgetstr("ch", NULL), 1 , res + 1), 0, ft_putchar);
	/*	else if (res > 0)
			tputs(tgoto(tgetstr("LE", NULL), 1 , res), 0, ft_putchar);*/
		if ((res = (len + MSH) / get_term_size().x) != 0)
			tputs(tgoto(tgetstr("DO", NULL), 0 , res), 0, ft_putchar);
	}
}