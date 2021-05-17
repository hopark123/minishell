/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:21:12 by suhong            #+#    #+#             */
/*   Updated: 2021/05/17 06:03:22 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"

# define ERROR	-1

typedef struct s_string
{
	char	word;
	char	*str;
	struct s_string	*next;
}	t_string;

//char	**split_comma(char *str);
int	meet_word(char *str);

#endif
