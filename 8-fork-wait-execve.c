#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - exercise: fork + wait + execve
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid = 1;
	int i = 0;
	int status;
	char *argv[] = {"bin/ls", "-l", "tmp/", NULL};

	my_pid = getpid();

	while (i <= 4 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("errors");
			return (1);
		}
		wait(&status);
		i++;
	}
	if (child_pid == 0)
	{
		printf("--------------------------------\n\n");
		printf("ID YANN: %u\n\nID PADRE: %u\n\n", getpid(), getppid());
		printf("--------------------------------\n\n");
	}
	else
	{
		printf("%u I AM THE FATHER AND MY ID IS: %u\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, NULL) == -1)
	{
	}
	return (0);

}
