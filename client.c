/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:30:57 by tfedoren          #+#    #+#             */
/*   Updated: 2022/05/23 19:07:51 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	loop_char(char c, int pid)
{
	int		j;
	char	temp;

	temp = c;
	j = 0;
	while (j < 8)
	{
		if ((temp & 1) == 1)
		{
			kill (pid, SIGUSR1);
			usleep (50);
		}
		if ((temp & 1) == 0)
		{	
			kill (pid, SIGUSR2);
			usleep (50);
		}
		temp = temp >> 1;
		j++;
	}
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
		pid = ft_atoi(argv[1]);
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
