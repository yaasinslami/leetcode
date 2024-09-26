#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

/**
 * struct words_t - Struct to hold each string and its type
 *
 * @str: string representation of a number
 * @type: type which mean where the @str from
 *
 * Description: struct to hold each string and its type
*/

typedef struct words_t
{
	char str[MAX_SIZE];
	int type;
} Word;

/**
 * max - get the max num between two numbers
 *
 * @n1: first num
 * @n2: second num
 *
 * Return: return the max number
*/

int	max(int n1, int n2) { return ((n1 > n2) ? n1 : n2); }

/**
 * max_prefixLength - get the max length prefix between
 * two string representation of ints
 *
 * @str1: the first string
 * @str2: the second string
 *
 * Return: return the max prefix length
*/

int max_prefixLength(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;

	while (i < len1 && i < len2)
	{
		if (str1[i] != str2[i])
		{
			break;
		}
		i++;
	}
	return (i);
}

/**
 * longestCommonPrefix - get the longest common prefix
 *
 * @arr1: the first array
 * @arr1Size: size of @arr1
 * @arr2: the second array
 * @arr2Size: size of @arr2
 *
 * Return: return the longestCommonPrefix
*/

int longestCommonPrefix(int *arr1, int arr1Size, int *arr2, int arr2Size)
{
	int		result, i = 0, j = 0, idx = 0, res = 0;
	char	str1[20], str2[20];

	/* array of Word structs */
	Word *words = (Word *)malloc(sizeof(Word) * (arr1Size + arr2Size));

	if (!words)
	{
		free(words);
		return (0);
	}

	/* fill the words array by the structs those have strings of arr1 */
	while (i < arr1Size)
	{
		snprintf(str1, sizeof(str1), "%d", arr1[i]);
		words[idx].type = 1;
		strcpy(words[idx].str, str1);
		idx++;
		i++;
	}

	/* fill the words array by the structs those have strings of arr2 */
	while (j < arr2Size)
	{
		snprintf(str2, sizeof(str2), "%d", arr2[j]);
		words[idx].type = 2;
		strcpy(words[idx].str, str2);
		idx++;
		j++;
	}

	i = 1;

	while (i < idx)
	{
		Word w1 = words[i - 1];
		Word w2 = words[i];

		if (w1.type != w2.type)
		{
			res = max(res, max_prefixLength(w1.str, w2.str));
		}
		i++;
	}

	return (res);
}

int main(void)
{
	int arr1[] = {5, 8, 5004, 52349987};
	int arr2[] = {52346, 5000, 8744};

	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr2) / sizeof(int);
	int result = longestCommonPrefix(arr1, size1, arr2, size2);

	printf("longestCommonPrefix: %d\n", result);

	return (0);
}
