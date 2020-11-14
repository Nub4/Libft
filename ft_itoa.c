/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 09:51:57 by minummin          #+#    #+#             */
/*   Updated: 2020/10/06 09:51:27 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_min(char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	str[0] = 45;
	str[1] = 2 + 48;
	str[2] = 1 + 48;
	str[3] = 4 + 48;
	str[4] = 7 + 48;
	str[5] = 4 + 48;
	str[6] = 8 + 48;
	str[7] = 3 + 48;
	str[8] = 6 + 48;
	str[9] = 4 + 48;
	str[10] = 8 + 48;
	str[11] = '\0';
	return (str);
}

static char	*ft_yee(char *str, int count, int i, int n)
{
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[count - 1] = n % 10 + 48;
		n = n / 10;
		count--;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		count;
	int		i;
	char	*str;

	if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = 0 + 48;
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = NULL;
		return (ft_min(str));
	}
	count = ft_count(n);
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = count;
	return (ft_yee(str, count, i, n));
}
