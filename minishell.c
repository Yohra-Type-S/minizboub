/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:39:31 by edvicair          #+#    #+#             */
/*   Updated: 2022/12/07 19:52:13 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(t_msh *msh)
{
	if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "cd", 3))
		ft_cd(msh);
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "pwd", 4))
		ft_pwd(msh);
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "env", 4))
		ft_env(msh);
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "export", 7))
		ft_export(msh);
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "unset", 6))
		ft_unset(msh);
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "getenv", 7))
		printf("%s = %s\n", msh->token->cmd[1], ft_getenv(msh, msh->token->cmd[1]));
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "echo", 5))
		ft_echo(msh);
	else if (msh->token->cmd[0] && !ft_strncmp(msh->token->cmd[0], "exit", 5))
		ft_exit(msh);
	else
	{
		/*
		int i = 0;
		while(msh->token->cmd[i])
		{
			printf("CMD[%d] = %s\n", i, msh->token->cmd[i]);
			i++;
		}*/
	}
	ft_free_token(msh->token);
}

int	main(int ac, char **av, char **env)
{
	t_msh	msh;
	t_env	*cpy;

	ft_init_struct(&msh, env);
	while (1)
	{
		msh.line = space_chips(readline("minizboub-> "));
		if (msh.line)
		{
			add_history(msh.line);
			//msh.token = ft_fill_token(&msh);
			if (parser(&msh))
			{
				if (msh.token && !msh.pip)
					ft_cmd(&msh);
			}
			// if (msh.token && msh->pip)
			// 	ft_cmd_pipe(&msh);
		//	ft_free_double(msh.token->cmd);
			free(msh.line);
		}
	}
	free(msh.line);
	return (0);
}
