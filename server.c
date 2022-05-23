/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:31:03 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/23 14:45:38 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>

void	signal_handler(int n)
{
	static int	i;
	static char	c;

	//i = 0;
	if (n == SIGUSR1)
	{
		if (i < 8)
		{
			c = c + (1 << i);
			i++;
		}
		if (i == 8)
		{
			ft_printf("%c", c);
			c = 0;
			i = 0;
		}
	}
	else
	{
		if (i < 8)
		{
			c = c + (0 << i);
			i++;
		}
		if (i == 8)
		{
			ft_printf("%c", c);
			c = 0;
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d \n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
