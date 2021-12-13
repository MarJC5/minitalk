/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/13 14:26:52 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	int		c;
	int		bitshift;

	c = 0;
	bitshift = 0;
	while (sig == SIGUSR1)
	while (sig == SIGUSR2)
	bitshift++;
	if (bitshift == 8)
	{
		ft_printf("%d", c);
		c = 0;
		bitshift = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: \033[1;32m%d\033[0m\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
