#include <stdio.h>

#define VOWEL_A 0
#define VOWEL_E 1
#define VOWEL_I 2
#define VOWEL_O 3
#define VOWEL_U 4

void	shift_function(int *bitmask, char vowel)
{
	switch (vowel)
	{
		case 'a': *bitmask ^= (1 << VOWEL_A); break;
		case 'e': *bitmask ^= (1 << VOWEL_E); break;
		case 'i': *bitmask ^= (1 << VOWEL_I); break;
		case 'o': *bitmask ^= (1 << VOWEL_O); break;
		case 'u': *bitmask ^= (1 << VOWEL_U); break;
	}
}

int	is_vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return (1);
	return (0);
}

int findTheLongestSubstring(char* s)
{
	int	bitmask_map[32], i = 0, max_length = 0, length = 0, bitmask = 0;

	// initialize the bitmask map
	while (i < 32)
	{
		bitmask_map[i] = -1;
		i++;
	}

	bitmask_map[0] = 0;
	i = 0;
	while (s[i])
	{
		// if str[i] is a vowel , we should toggle its corresponding bit
		if (is_vowel(s[i]))
		{
			shift_function(&bitmask, s[i]);
		}

		if (bitmask_map[bitmask] != -1)
		{
			length = i + 1 - bitmask_map[bitmask];
			if (length > max_length)
			{
				max_length = length;
			}
		}
		else
		{
			bitmask_map[bitmask] = i + 1;
		}
		i++;
	}
	return (max_length);
}

int main()
{
	char	*str = "Hello ecma6, howo are you, a";

	printf("%d\n", findTheLongestSubstring(str));
	return (0);
}
