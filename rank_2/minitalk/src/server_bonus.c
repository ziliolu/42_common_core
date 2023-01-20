/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:37:45 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/01/20 13:06:10 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_handle_signal(int signal, siginfo_t *info, void *vp)
{
	static char	bits;
	static int	count;
	
	(void)vp;
	if (signal == SIGUSR1)
		bits = bits | (1 << (7 - count));
	count++;
	if (count == 8)
	{
		ft_printf("%c", bits);
		if(bits == '\0')
			kill(info->si_pid, SIGUSR2);
		bits = 0;
		count = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Invalid number of arguments, try again!\n");
		return (0);
	}
	ft_printf("PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
