
#include <unistd.h>
#include <stdlib.h>

int check_sep(char ch, char *charset)
{
    int i;

    i = 0;
    while(charset[i])
    {
        if (charset[i] == ch)
            return (1);
        i++;
    }
    return (0);
}

int count_words(char *str, char *charset)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && check_sep(str[i], charset))
            i++;
        if (str[i])
            count++;
        while (str[i] && !check_sep(str[i], charset))
            i++;
    }
    return (count);
}

int word_len(char *str, char *charset)
{
    int i;
    int wlen;

    wlen = 0;
    i = 0;
    while (str[i] && !check_sep(str[i], charset))
    {
        wlen++;
        i++;
    }
    return (wlen);
}

char    *full_alloc(char *str, char *charset)
{
    int     i;
    int     wlen;
    char    *string;

    wlen = word_len(str, charset);
    string = (char *)malloc((sizeof(char) * wlen) + 1);
    if (!string)
        return (NULL);
    i = 0;
    while (i < wlen)
    {
        string[i] = str[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}

char    **ft_split(char *str, char *charset)
{
    char    **strings;
    int     count;
    int     i;

    count = count_words(str, charset);
    strings = (char **)malloc((sizeof(char *) * count) + 1);
    if (!strings)
        return (NULL);
    i = 0;
    while (*str)
    {
        while (*str && check_sep(*str, charset))
            str++;
        if (*str)
        {
            strings[i] = full_alloc(str, charset);
            i++;
        }
        while (*str && !check_sep(*str, charset))
            str++;
    }
    strings[i] = 0;
    return (strings);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int     count;
    char    **strings;
    int     i;

    if (ac == 3)
    {
        i = 0;
        count = count_words(av[1], av[2]);
        strings = ft_split(av[1], av[2]);
        if (strings == NULL)
            return (-1);
        while (strings[i])
        {
            ft_putstr(strings[i]);
            if (i < count - 1)
                write(1, "\n", 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
