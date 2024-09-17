#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list {
	char *word;
	int count;
} t_list;

void	fil_fullSplit(char **full_split, char **s1_split, char **s2_split);
void	add_word(t_list *hash_table[], char *word, int *table_size);

char	**uncommonFromSentences(char* s1, char* s2, int* returnSize)
{
	char **s1_split, **s2_split, **full_split, **result;

	s1_split = ft_split(s1);
	s2_split = ft_split(s2);

	// for count1 and count2
	int count1 = count_words(s1), count2 = count_words(s2);

	// allocig for the full_split that contain all the words from s1 & s2
	full_split = (char **)malloc(sizeof(char *) * (count1 + count2 + 1));
	if (!full_split)
		return (NULL);

	fil_fullSplit(full_split, s1_split, s2_split);

	int table_size = 0;
	t_list *hash_table[100] = {0};

	int i = 0;
	while (full_split[i])
	{
		add_word(hash_table, full_split[i], &table_size);
		i++;
	}
	// now the hash table is filled

	int result_size = 0;
	i = 0;
	while (i < table_size)
	{
		if (hash_table[i]->count == 1)
			result_size++;
		i++;
	}

	// now we will allocate for the resulted array
	result = (char **)malloc(sizeof(char *) * (result_size + 1));
	if (!result)
		return (NULL);

	// now fill the array with filtred case --> one word that appear more than one
	i = 0;
	int res_idx = 0;
	while (i < table_size)
	{
		if (hash_table[i]->count == 1)
		{
			result[res_idx] = ft_strdup(hash_table[i]->word);
			res_idx++;
		}
		i++;
	}
	result[res_idx] = NULL;
	*returnSize = result_size;

	// now let's free all uneccesary memory
	for (int i = 0; s1_split[i]; i++) free(s1_split[i]);
	for (int i = 0; s2_split[i]; i++) free(s2_split[i]);
	// free the entire arrays
	free(s1_split);
	free(s2_split);

	// for full_split
	i = 0;
	while (full_split[i])
	{
		free(full_split[i]);
		i++;
	}
	free(full_split);

	// for the hash_table
	i = 0;
	while (i < table_size)
	{
		if (hash_table[i])
		{
			free(hash_table[i]->word);
			free(hash_table[i]);
		}
		i++;
	}
	return (result);
}

void	add_word(t_list *hash_table[], char *word, int *table_size)
{
	int	found = 0;

	int i = 0;
	while (i < *table_size)
	{
		if (strcmp(hash_table[i]->word, word) == 0)
		{
			(hash_table[i]->count)++;
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
	{
		t_list *new_word = (t_list *)malloc(sizeof(t_list));
		if (!new_word)
			return;
		new_word->word = ft_strdup(word);
		new_word->count = 1;
		hash_table[*table_size] = new_word;
		(*table_size)++;
	}
}

void fil_fullSplit(char **full_split, char **s1_split, char **s2_split)
{
	int i = 0, j = 0;
	while (s1_split[j])
	{
		full_split[i] = ft_strdup(s1_split[j]);
		i++;
		j++;
	}
	j = 0;
	while (s2_split[j])
	{
		full_split[i] = ft_strdup(s2_split[j]);
		i++;
		j++;
	}
	full_split[i] = 0;
}



int main()
{
	char *s1 = "s z z z z s";
	char *s2 = "j s z ejtb";

	int size = 0;
	char **result = uncommonFromSentences(s1, s2, &size);

	//int count = count_words(str);
	int i = 0;
	while (i < size)
	{
		printf("%s\n", result[i]);
		i++;
	}

	// Free the result array
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

