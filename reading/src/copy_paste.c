/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 06:35:49 by sgertrud          #+#    #+#             */
/*   Updated: 2020/12/27 07:12:00 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**c_str(void)
{
	static char *str = 0;

	return (&str);
}
