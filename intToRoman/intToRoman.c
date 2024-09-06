/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intToRoman.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 05:01:30 by yslami            #+#    #+#             */
/*   Updated: 2024/09/06 05:01:30 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

char	*intToRoman(int num)
{
	char	*str;
	int		values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char	*symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int		i;

	str = (char *)malloc(20); // 10: because the max(num) = 3999 wich is have 9 charachters  in roman format
	if (!str)
		return (NULL);
	i = 0;
	str[i] = '\0';
	while (num > 0)
	{
		if (num >= values[i])
		{
			ft_strcat(str, symbols[i]);
			num -= values[i];
		}
		else
			i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main()
{
	int		num = 3999;
	char	*str;

	str = intToRoman(num);
	ft_putstr(str);
	//printf("%d\t-->\t%s\n", num, str);
	write(1, "\n", 1);
	free(str);
	return (0);
}*/