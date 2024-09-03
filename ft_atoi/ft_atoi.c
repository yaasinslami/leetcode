int myAtoi(char* s) {
    int result;
    int sign;
    int i;

    i = 0;
    sign = 1;
    result = 0;
    while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while(s[i] && (s[i] >= '0' && s[i] <= '9'))
    {
        if (result > (2147483647 - (s[i] - '0')) / 10)
            return (sign == 1) ? 2147483647 : -2147483648;
        result = (result * 10) + s[i] - '0';
        i++;
    }
    return (sign * result);
}

#include <stdio.h>

int main()
{
    printf("%d\n", myAtoi("-91283472332"));
    return (0);
}
