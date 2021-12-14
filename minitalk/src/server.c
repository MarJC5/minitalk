/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:16:34 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/14 16:45:14 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static char	c;
	static int	bitshift = 0;

	bitshift++;
	if (bitshift == 8)
	{
		ft_printf("%c", c);
		if (!c)
			ft_printf("\n");
		bitshift = 0;
		c = 0;
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
