/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/03 15:20:29 by jmartin          ###   ########.fr       */
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
	struct sigaction sig;

	sig.sa_handler = &sig_handler;
	sig.sa_flags = SA_RESTART;
	printf("Server PID: \033[1;32m%d\033[0m\n", getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		if (sigaction(SIGUSR1, &sig, NULL) == -1)
			printf("\ncan't catch SIGUSR1\n");
		if (sigaction(SIGUSR2, &sig, NULL) == -1)
			printf("\ncan't catch SIGUSR2\n");
		sleep(1);
	}
	return (0);
}
