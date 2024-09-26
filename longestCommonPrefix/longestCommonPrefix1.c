#include <stdlib.h>

int	count(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while(nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int	i;
	char	*str;

	str = (char *)malloc((sizeof(char) * count(nbr)) + 1);
	if (!str)
		return (NULL);
	i = count(nbr);
	str[i] = '\0';
	i--;
	if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
	while(i >= 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	return (str);
}

int get_len_prefix(int n1, int n2)
{
	char	*str1 = ft_itoa(n1);
	char	*str2 = ft_itoa(n2);

	int i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}

	free(str1);
	free(str2);

	return (i);
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
	int	i, j;
	int	prefixLength, maxLength = 0;

	i = 0;
	while (i < arr1Size)
	{
		j = 0;
		while (j < arr2Size)
		{
			prefixLength = get_len_prefix(arr1[i], arr2[j]);
			if (prefixLength > maxLength)
			{
				maxLength = prefixLength;
			}
			j++;
		}
		i++;
	}
	// get the largest prefix stored in the hashTable
	return (maxLength);
}

#include <stdio.h>
int main()
{
	int arr1[] = {1, 10, 100};
	int arr2[] = {1000};

	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr1) / sizeof(int);
	int result = longestCommonPrefix(arr1, size1, arr2, size2);
	printf("%d\n", result);
	return (0);
}