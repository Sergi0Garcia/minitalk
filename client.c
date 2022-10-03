/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:28:31 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/03 13:28:17 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

static void	send_char(int pid, char current_char)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (current_char & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		current_bit++;
	}
}

void	arg_val(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Usage <PID> <string>\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (!pid || pid <= 0)
	{
		ft_putstr_fd("PID not valid\n", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		pid;

	i = 0;
	arg_val(argc, argv);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (str[i])
		send_char(pid, str[i++]);
	return (0);
}
