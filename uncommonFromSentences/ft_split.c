#include "main.h"
#include <stdlib.h>

int check_sep(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int count_words(char *str)
{
	int	i, count = 0;

	i = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i]))
			i++;
		if (str[i])
		{
			count++;
		}
		while (str[i] && !check_sep(str[i]))
			i++;
	}
	return count;
}

int word_len(char *str)
{
	int	i, w_len = 0;

	i = 0;
	while (str[i] && !check_sep(str[i]))
	{
		w_len++;
		i++;
	}
	return (w_len);
}


char	*ft_strdup(char *str)
{
	int		i, w_len;
	char	*result;

	w_len = word_len(str);

	// allocate for the result allocated word
	result = (char *)malloc((sizeof(char) * w_len) + 1);
	if (!result)
		return (NULL);

	// start dupplicating
	i = 0;
	while (i < w_len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char *str)
{
	int		i, count;
	char	**strings;

	count = count_words(str);
	strings = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);

	// start storing to the 2D array
	i = 0;
	while (*str)
	{
		while (*str && check_sep(*str))
			str++;
		if (*str)
		{
			strings[i] = ft_strdup(str);
			if (!strings[i])
			{
				while (i > 0)
					free(strings[--i]);
				free(strings);
				return (NULL);
			}
			i++;
		}
		while (*str && !check_sep(*str))
			str++;
	}
	strings[i] = NULL;
	return (strings);
}

