/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:13:05 by seukim            #+#    #+#             */
/*   Updated: 2020/06/28 17:13:05 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_back(char *cmd)
{
	int i;

	i = 0;
	i = strlen(cmd);
	while (1)
	{
		if (cmd[i] == '\\')
		{
			break ;
		}
		cmd[i] = '\0';
		i--;
	}
}

void	process_cd(char **cmd, char **argv)
{
	int i;
	char cwd[100];

	i = 0;
	if (cmd[1] == NULL)
		chdir(argv[0]);
	else if (!(strcmp(cmd[1], "..")) && cmd[2] == NULL)
	{
		getcwd(cwd, sizeof(cwd));
		cd_back(cwd);
		chdir(cwd);
	}
	else if (!(strcmp(cmd[1][0], "/")) && cmd[2] == NULL)
	{
		chdir(cmd[1]);
	}

}

void	check_order(char **cmd, char **argv)
{
	char cwd[100];

	if (!(strcmp(cmd[0], "cd")))
	{
		process_cd(cmd, argv);
	}
	if (!(strcmp(cmd[0], "pwd")))
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s\n",cwd);
	}
	/*
	else if (cmd[0] = "echo")
		process_echo(cmd);
	*/

}
