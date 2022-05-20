/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:31:03 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/20 16:30:35 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>


void signal_handler(int n)
{
	if (n == SIGUSR1)
	{
		ft_printf("Siemanko\n");
	}
}

int	main(int argc, char **argv)
{
	int pid = getpid();
	ft_printf("PID : %d \n", pid);
	signal(SIGUSR1, signal_handler);
	while(1)
	{

		sleep(1);
	}
	return (0);
}
