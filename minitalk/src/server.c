/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/20 12:14:34 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static char	c = 0;
	static int	bit = 128;
	static int	bitshift = 0;

	if (sig == SIGUSR1)
	{
		c += bit;
		bit /= 2;
	}
	else if (sig == SIGUSR2)
		bit /= 2;
	bitshift++;
	if (bitshift == 8)
	{
		ft_printf("%c", c);
		bit = 128;
		bitshift = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: \033[1;32m%d\033[0m\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
