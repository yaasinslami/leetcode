/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:23:18 by yslami            #+#    #+#             */
/*   Updated: 2024/09/05 11:23:18 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int ft_rev_int(int x)
{
    long reversed;
    int sign = x < 0 ? -1 : 1;

     if (x == INT_MIN)
        return 0;
    reversed = 0;
    x = x * sign;  // Make x positive to handle digits easily

    while (x > 0)
    {
        int digit = x % 10;
        reversed = reversed * 10 + digit;

        // Check for overflow before continuing
        if (reversed > INT_MAX)
            return 0;

        x /= 10;
    }

    return (int)(reversed * sign);  // Apply the sign back
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("%d", ft_rev_int(atoi(av[1])));
    }
    printf("\n");
    return (0);
}
