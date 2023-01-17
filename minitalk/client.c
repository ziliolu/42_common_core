#include "ft_minitalk.h"

void ft_send_bit(int pid, char octet)
{
	int bit;
	int i;

	bit = 0;
	i = 7;
	while(i >= 0)
	{
		bit = ((octet >> i) & 1);

		if(bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		i--;
	}

}

int main(int argc, char **argv)
{
	int pid;
	int i;
	char *str;
	
	i = 0;
	str = argv[2];

	if(argc == 3)
	{
		pid = atoi(argv[1]);
		while(str[i])
		{
			ft_send_bit(pid, str[i]);
			i++;
		}
	}
}

