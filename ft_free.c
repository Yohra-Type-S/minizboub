/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:36:08 by edvicair          #+#    #+#             */
/*   Updated: 2022/11/27 23:05:21 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_one_env(t_env *env)
{
    free(env->name);
    env->name = NULL;
    free(env->value);
    env->value = NULL;
    free(env);
    env = NULL;
}

void    ft_free_double(char **s)
{
    int i;

    i = 0;
    if (s == NULL)
        return ;
    while (s[i])
    {
        free(s[i]);
        s[i] = NULL;
        i++;
    }
    free(s);
    s = NULL;
}

void	ft_free_token(t_token *token)
{
	t_token *tmp;
	
	while (token->next)
	{
		ft_free_double(token->cmd);
		tmp = token;
		token = token->next;
		free(tmp);
	}
	ft_free_double(token->cmd);
	free(token);
	token = NULL;
}