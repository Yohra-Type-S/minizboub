/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 06:30:57 by edvicair          #+#    #+#             */
/*   Updated: 2022/11/25 09:40:03 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset_bis(t_msh *msh, t_env *cpy, t_env *cpy_b)
{
	if (!ft_strcmp(cpy->name, msh->token->cmd[1]))
	{
		msh->env = msh->env->next;
		free(cpy->name);
		free(cpy->value);
		free(cpy);
		cpy->name = NULL;
		cpy->value = NULL;
		cpy = NULL;
		return (1);
	}
	else if (cpy->next)
	{
		cpy_b = cpy;
		cpy = cpy->next;
	}
	return (0);
}

void	ft_unset(t_msh *msh)
{
	t_env	*cpy;
	t_env	*cpy_b;
	int i;

	cpy = msh->env;
	i = ft_unset_bis(msh, cpy, cpy_b);
	while (!i && cpy->next)
	{
		if (!ft_strcmp(cpy->name, msh->token->cmd[1]))
		{
			cpy = cpy->next;
			cpy_b->next = cpy;
			break ;
		}
		cpy_b = cpy;
		cpy = cpy->next;
	}
	if (!i && !ft_strcmp(cpy->name, msh->token->cmd[1]))
		cpy_b->next = NULL;
}
