/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:16:14 by sgertrud          #+#    #+#             */
/*   Updated: 2020/12/26 12:22:24 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_line	*get_line(void)
{
	static t_line	line;

	return (&line);
}
