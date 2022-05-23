/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:31:03 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/23 18:51:36 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bt_function(int k)
{
	static int	i;
	static char	c;

	if (i < 8)
	{
		c = c + (k << i);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

static void	signal_handler(int n)
{
	if (n == SIGUSR1)
		bt_function(1);
	else
		bt_function(0);
}

int	main(void)
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
