/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/02 22:27:09 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	int	c;

	c = 0;
	if (sig == SIGUSR1)
		c = 0;
	else if (sig == SIGUSR2)
		c = 1;
	printf("%d", c);
}

int	main(void)
{
	printf("Server PID: \033[1;32m%d\033[0m\n", getpid());
	while (1)
	{
		if (signal(SIGUSR1, sig_handler) == SIG_ERR)
			printf("\ncan't catch SIGUSR1\n");
		if (signal(SIGUSR2, sig_handler) == SIG_ERR)
			printf("\ncan't catch SIGUSR2\n");
		pause();
	}
	return (0);
}
