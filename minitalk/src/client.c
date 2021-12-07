/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:38:39 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/07 13:43:34 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_message(pid_t pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
	{
		ctob(msg[i], pid);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		printf("Enter the server PID & a message.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (1)
	{
		sig_message(pid, msg);
		pause();
	}
	return (0);
}
