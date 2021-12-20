/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:38:39 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/20 11:48:23 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ctob(char c, pid_t pid)
{
	int	bitshift;

	bitshift = 8;
	while(bitshift-- > 0)
	{
		if (c & (1 << bitshift))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

void	sig_message(pid_t pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		ctob(msg[i], pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Enter the server PID & a message.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	sig_message(pid, msg);
	return (0);
}
