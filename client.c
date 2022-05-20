/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:30:57 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/20 16:32:32 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int 	pid;
	char	*string;
	
	if 
	//int pit_d;
	pid = ft_atoi(argv[1]);
	// pid = getpid();
	// char *line;
	kill(pid, SIGUSR1);
	ft_printf("%d\n", pid);
	return (0);
}
