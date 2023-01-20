/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:39:36 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/01/20 13:10:56 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_send_bit(int pid, char octet)
{
	int	bit;
	int	i;

	bit = 0;
	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1);
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		i--;
	}
}

void ft_handle_signal(int signal)
{
	if(signal == SIGUSR2)
		ft_printf("Message received in the server!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	char				*str;
	//struct sigaction	sa; 

	i = 0;
	/* sa.sa_handler = &ft_handle_signal;
	sigaction(SIGUSR2, &sa, NULL); */
	signal(SIGUSR2, ft_handle_signal);
	str = argv[2];
	
	if (argc != 3)
		return (1);
	
	pid = atoi(argv[1]);
	while (str[i])
	{
		ft_send_bit(pid, str[i]);
		i++;
	}
	ft_send_bit(pid, '\0');
	while (1)
		pause();
	return (0);
}
