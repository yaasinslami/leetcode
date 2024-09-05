/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count-and-say2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yassinx4002@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:24:05 by yslami            #+#    #+#             */
/*   Updated: 2024/09/05 11:24:05 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char* countAndSay(int n)
{
    char    *prev;
    char    *cur;
    char    c;
    char    c_cur;
    int     len;
    int     index;
    int     count;
    int     i;
    

    if (n == 1)
        return ("1");
    prev = countAndSay(n - 1);
    len = strlen(prev);
    cur = (char *)malloc((len * 2) + 1);
    if (!cur)
        return (NULL);
    c_cur = *prev;
    index = 0;
    count = 1;
    i = 1;
    while (i < len)
    {
        c = *(prev + i);
        if (c == c_cur)
        {
            count++;
        }
        else
        {
            *(cur + index++) = count + '0';
            *(cur + index++) = c_cur;
            c_cur = c;
            count = 1;
        }
        i++;
    }
    *(cur + index++) = count + '0';
    *(cur + index++) = c_cur;
    *(cur + index) = '\0';
    //free(prev);
    return (cur);
}

#include <stdio.h>

int main()
{
    char    *str;

    str = countAndSay(4);
    printf("%s\n", str);
    //free(str);
    return (0);
}
