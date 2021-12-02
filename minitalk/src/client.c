/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:38:39 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/02 17:33:12 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_message(pid_t pid, char *msg)
{
	int	i;
	(void)pid;

	i = -1;
	while (msg[++i])
		ctob(msg[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		sig_message(ft_atoi(argv[1]), argv[2]);
	else
		printf("Enter the server PID & a message.\n");
	return (0);
}
