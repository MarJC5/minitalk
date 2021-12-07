/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:30:20 by jmartin           #+#    #+#             */
/*   Updated: 2021/12/07 13:44:58 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		count;
	int		num;

	sign = 1;
	count = 0;
	num = 0;
	while (str[count] == ' '
		|| str[count] == '\f'
		|| str[count] == '\n'
		|| str[count] == '\r'
		|| str[count] == '\t'
		|| str[count] == '\v')
		count++;
	if (str[count] == '-')
		sign = -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] && (str[count] >= '0' && str[count] <= '9'))
		num = num * 10 + (str[count++] - '0');
	return (sign * num);
}

int	ctob(char c, pid_t pid)
{
	int	i;

	i = 8;
	while(i-- > 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
	}
	return (0);
}
