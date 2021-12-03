/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:38:39 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/03 15:22:44 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_message(pid_t pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
	{
		if (ctob(msg[i]) == 0)
			kill(pid, SIGUSR1);
		else if (ctob(msg[i]) == 1)
			kill(pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
		printf("Enter the server PID & a message.\n");
	else
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		sig_message(pid, msg);
	}
	return (0);
}
