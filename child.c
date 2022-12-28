/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:36:39 by edvicair          #+#    #+#             */
/*   Updated: 2022/11/29 00:07:05 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    one_child(t_msh *msh, int in, int out, int *child)
{
        child = fork();
        if (child == -1)
        {
            perror("Can't fork");
//          free_double(pipe->path);
            exit(0);
	    }
        if (child = 0)
        {
            
        }
}
void    ft_child(t_msh *t_msh)
{
    int in;
    int out;
    
    
}