
int _pow(int base, int power)
{
	int result;

	result = 1;
	while (power)
	{
		result *= base;
		power--;
	}
	return (result);
}

int	length(int nb)
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

int	get_len_prefix(int n1, int n2)
{
	int len1 = length(n1);
	int len2 = length(n2);

	if (len1 > len2)
	{
		n1 /= (int)_pow(10, len1 - len2); 
	}
	else if (len2 > len1)
	{
		n2 /= (int)_pow(10, len2 - len1);
	}

	int common_prefix_length = 0;
	while (n1 > 0 && n2 > 0)
	{
		if (n1 == n2)
		{
			common_prefix_length += length(n1);
			break;
		}

		n1 /= 10;
		n2 /= 10;
	}
	return (common_prefix_length);
}

int	not_dupp(int num, int arr[], int index)
{
	int i = 0;

	while (i < index)
	{
		if (num == arr[i])
			return (0);
		i++;
	}
	return (1);
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
	int	i, j;
	int	prefixLength, maxLength = 0;

	i = 0;
	while (i < arr1Size)
	{
		if (not_dupp(arr1[i], arr1, i))
		{
			j = 0;
			while (j < arr2Size)
			{
				if (not_dupp(arr2[j], arr2, j))
				{
					prefixLength = get_len_prefix(arr1[i], arr2[j]);
					if (prefixLength > maxLength)
					{
						maxLength = prefixLength;
					}
				}
				j++;
			}
		}
		i++;
	}
	// get the largest prefix stored in the hashTable
	return (maxLength);
}

#include <stdio.h>
int main()
{
	int arr1[] = {1, 2, 3};
	int arr2[] = {4, 4, 4};

	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr1) / sizeof(int);
	int result = longestCommonPrefix(arr1, size1, arr2, size2);
	printf("%d\n", result);
	return (0);
}