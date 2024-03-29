/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 05:36:57 by sgertrud          #+#    #+#             */
/*   Updated: 2020/12/28 09:50:17 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H
# include "structs.h"

void		handle_back_slash(char **str, char **arg);
char		*parse_d_quote(char **str, t_envp *envp);
char		*parse_quote(char **str);
char		*parse_env(char **str, t_envp *envp);
int			check_end_arg(char c);
int			check_end_command(char c);
int			check_and_or(char c, char h);
int			check_sc(char c);
int			check_wild(char *str);
#endif
