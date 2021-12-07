/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/07 13:57:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	printf("%d", sig);
}

int	main(void)
{
	printf("Server PID: \033[1;32m%d\033[0m\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		if (signal(SIGUSR1, sig_handler) == SIG_ERR)
			printf("\ncan't catch SIGUSR1\n");
		if (signal(SIGUSR2, sig_handler) == SIG_ERR)
			printf("\ncan't catch SIGUSR2\n");
		pause();
	}
	return (0);
}
