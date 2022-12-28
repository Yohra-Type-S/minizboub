/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:52:58 by motaouss          #+#    #+#             */
/*   Updated: 2022/12/26 17:21:40 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_pipe(char *str)
{
	int	i;
	int	pipe;

	i = 0;
	pipe = 0;
	while (str[i])
	{
		if (str[i] == '|')
			pipe++;
		if (str[i] == '\'' || str[i] == '"')
			i = split_what(str, i, str[i]);
		i++;
	}
	//printf("pipe : %d\n", pipe);
	return (pipe);
}

int	find_pipe(char *str, int i)
{
	while (str[i] != '|' && str[i])
	{
		i++;
	}
	if (str[i] = '\0')
		return (ft_strlen(str));
	return (i);
}

char	*ft_substr2(const char *s, int min, int max)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char *) * (max - min + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (min < max)
	{
		s2[i] = s[min];
		i++;
		min++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
int	is_redir(char *str, int i)
{
	
}
*/