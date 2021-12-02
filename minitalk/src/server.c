/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/02 17:01:07 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		printf("0");
	else if (sig == SIGUSR2)
		printf("1");
}

int	main(void)
{
	printf("Server PID: \033[1;32m%d\033[0m\n", getpid());
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGUSR1\n");
	if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGUSR2\n");
	while (1)
		pause();
	return (0);
}
