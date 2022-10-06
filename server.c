/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:32:12 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/06 12:54:34 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"

static void	print_pid(void)
{
	pid_t	pid;
	char	*str;

	pid = getpid();
	str = ft_itoa(pid);
	if (!str)
	{
		ft_putstr_fd("Error printing PID\n", 1);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}

static void	handler_msg(int sig)
{
	static char	current_char = 0;
	static int	current_bit = 0;

	if (sig == SIGUSR2)
		current_char |= 1 << current_bit;
	current_bit++;
	if (current_bit == 8)
	{
		ft_putchar_fd(current_char, 1);
		current_char = 0;
		current_bit = 0;
	}
}

static void	exit_signal(int sig)
{
	(void)sig;
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, handler_msg);
	signal(SIGUSR2, handler_msg);
	signal(SIGINT, exit_signal);
	signal(SIGTERM, exit_signal);
	while (1)
		pause();
}
