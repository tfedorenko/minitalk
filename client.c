/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:30:57 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/23 11:52:08 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	loop_char(char c, int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((c & 1) == 1)
			kill (pid, SIGUSR1);
		if ((c & 1) == 0)
			kill (pid, SIGUSR2);
		j++;
	}
	j = 0;
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*string;

	i = 0;
	if (argc == 3)
	{
		string = argv[2];
		pid = ft_atoi(argv[2]);
		ft_printf("%d\n", pid);
		if (kill(pid, 0) != 0)
		{
			ft_printf("unvalid pid");
			return (0);
		}
		while (string[i])
		{
			loop_char(string[i], pid);
			i++;
		}
	}
	else
		ft_printf("error, wrong number of arguments\n");
	return (0);
}
