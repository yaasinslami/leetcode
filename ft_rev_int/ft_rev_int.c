#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

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

int ft_rev_int(int  x)
{
    char    *str;
    int     res;
    int     i;
    int     j;
    char    temp;

    str = ft_itoa(x);
    if (!str)
        return (0);
    i = 0;
    if (x < 0)
        i = 1;
    j = strlen(str) - 1;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    res = atoi(str);
    free(str);  // Free the allocated memory
    // Check if the reversed number is out of the range of a 32-bit signed integer
    if (res > INT_MAX || res < INT_MIN)
        return (0);
    return (res);
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
