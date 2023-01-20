/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:37:45 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/01/20 11:39:19 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_handle_signal(int signal)
{
	static char	bits;
	static int	count;

	if (signal == SIGUSR1)
		bits = bits | (1 << (7 - count));
	count++;
	if (count == 8)
	{
		ft_printf("%c", bits);
		bits = 0;
		count = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	sa.sa_handler = &ft_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
