#include <stdio.h>
#include <stdlib.h>
/**
 * main - has arguments parsed
 * @ac: arg 1
 * @av: arg 2
 * Return: 0
 */
int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
