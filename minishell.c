/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:24:52 by seukim            #+#    #+#             */
/*   Updated: 2020/06/18 19:24:52 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_clear(char **array, int n)
{
	int			index;

	index = 0;
	while (index < n)
		free(array[index++]);
	free(array);
}

static char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	char		*final;

	final = dest;
	while (*src != 0 && len > 0)
	{
		*dest++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dest++ = 0;
		len--;
	}
	return (final);
}

static void		*ft_memalloc(size_t size)
{
	void		*dest;
	char		*clean;

	dest = malloc(size);
	clean = dest;
	if (dest)
	{
		while (size != 0)
		{
			*clean++ = 0;
			size--;
		}
		return (dest);
	}
	else
	{
		return (NULL);
	}
}

static int		count_str(char *s1, char c)
{
	int			n_str;

	n_str = 0;
	while (*s1)
	{
		while (*s1 == c && *s1)
			s1++;
		if (*s1 != c && *s1)
			n_str++;
		while (*s1 != c && *s1)
			s1++;
	}
	return (n_str);
}

char		**ft_split(char *s1, char c)
{
	char	**res;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * count_str(s1, c)+ 1)))
		return (NULL);
	while (*s1 != 0)
	{
		i = 0;
		while (s1[i] != c && s1[i] != 0)
			i++;
		if (i)
		{
			if (!(res[k++] = ft_strncpy(ft_memalloc(i + 1), s1, i)))
				ft_clear(res, k);
			s1 = &s1[i];
		}
		else
			s1++;
	}
	res[k] = NULL;
	return (res);
}













void	find_n(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
}

void	setargv(char **argv)
{
	int i;

	i = 0;
	i = strlen(argv[0]);
	while (1)
	{
		if (argv[0][i] == '\\')
		{
			argv[0][i] = '\0';
			break ;
		}
		argv[0][i] = '\0';
		i--;
	}
}

int main(int argc, char **argv, char **env)
{
	char	buff[100];
	char	**cmd;
	char 	*p1;
	int		i;

	setargv(argv);
	while(1)
	{
		printf("minishell> :");
		read(0, buff, 100);
		find_n(buff);
		cmd = ft_split(buff, ' ');
		check_order(cmd, argv);
		if (strcmp(buff, "exit") == 0)
			break ;
	}
	return (0);
}
