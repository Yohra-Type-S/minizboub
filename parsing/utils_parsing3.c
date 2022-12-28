/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:20:01 by motaouss          #+#    #+#             */
/*   Updated: 2022/12/09 19:35:21 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redir	*ft_redir_new(char *cmd)
{
	t_redir	*lst_redir;

	lst_redir = (t_redir *)malloc(sizeof(t_redir));
	if (!lst_redir)
		return (NULL);
	lst_redir->type = redir_type(cmd);
	lst_redir->next = 0;
	return (lst_redir);
}

t_redir	*ft_redir_last(t_redir *redir)
{
	if (redir)
	{
		while (redir->next)
			redir = redir->next;
	}
	return (redir);
}

void	ft_redir_add_back(t_redir **redir, t_redir *new)
{
	t_redir	*lst_redir;

	if (redir)
	{
		if (*redir)
		{
			lst_redir = ft_redir_last(*redir);
			lst_redir->next = new;
		}
		else
			*redir = new;
	}
}

t_redir	*ft_fill_redir(char *cmd_p)
{
	t_redir	*redir;
	int	i;
	char	**s;

	s = tokenizator(cmd_p, '<');
	i = 0;
	while (cmd[i])
	{
		ft_redir_add_back(&redir, ft_redir_new(cmd[i]));
		i++;
	}
	return (redir);
}