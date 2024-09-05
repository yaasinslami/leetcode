/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isPalindrome.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:23:30 by yslami            #+#    #+#             */
/*   Updated: 2024/09/05 11:23:30 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

int number_len(int nb)
{
    int i;

    i = 0;
    if (nb <= 0)
    {
        nb *= -1;
        i++;

    }
    while (nb)
    {
        i++;
        nb /= 10;
    }
    return (i);
}

char    *ft_itoa(int nb)
{
    char    *str;
    int     nb_len;
    int     i;

    nb_len = number_len(nb);
    str = (char *)malloc((sizeof(char) * nb_len) + 1);
    if (!str)
        return (NULL);
    if (nb < 0)
    {
        str[0] = '-';
        nb *= -1;
    }
    i = nb_len;
    str[i--] = '\0';
    if (nb == 0)
    {
        str[i] = '0';
    }
    while (nb)
    {
        str[i--] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}

bool isPalindrome(int x)
{
    char    *str;
    int     i;
    int     j;

    str = ft_itoa(x);
    i = 0;
    j = 0;
    while (str[j])
        j++;
    j--;
    while (i <= j)
    {
        if (str[i] != str[j])
            return (false);
        i++;
        j--;
    }
    return (true);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char    *str;

    if (ac == 2)
    {
        printf("%B", isPalindrome(atoi(av[1])));
    }
    printf("\n");
    return (0);
}


