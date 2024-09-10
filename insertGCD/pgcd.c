#include "main.h"

int	min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

int	pgcd(int n1, int n2)
{
	int	i;
	int	pgcd;

	//handle the cas of pgcd(0, 7)
	if (n1 == 0 || n2 == 0)
	{
		return (n1 == 0 ? n2 : n1);
	}

	pgcd = 1;
	i = 2;
	while (i <= min(n1, n2))
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			pgcd *= i;
			n1 /= i;
			n2 /= i;
		}
		else
			i++;
	}
	return (pgcd);
}
