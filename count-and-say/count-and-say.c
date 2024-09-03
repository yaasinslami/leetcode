#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* countAndSay(int n) {
    char    *prev;
    char    *cur;
    int     count;
    int     index;
    int     len;
    int     i;

    if (n == 1)
    {
        cur = (char *)malloc(2 * sizeof(char));
        if (!cur)
            return (NULL);
        sprintf(cur, "%s", "1");
        return (cur);
    }
    prev = countAndSay(n - 1);
    len = strlen(prev);
    cur = (char *)malloc((len * 2) + 1);
    if (!cur)
        return (NULL);
    i = 0;
    index = 0;
    count = 0;
    while (i < len)
    {
        count++;
        if (i == len - 1 || prev[i] != prev[i + 1])
        {
            index += sprintf(cur + index, "%d%c", count, prev[i]);
            count = 0;
        }
        i++;
    }
    free(prev);
    return (cur);
}
