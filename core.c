#include <stdio.h>
#include <stdlib.h>
#include "core.h"

void greeting(char *name)
{
	fprintf(stderr, "%s запустился с PID = %d, PPID = %d!\n", name, getpid(), getppid());
}

void bye(char *name)
{
	fprintf(stderr, "%s завершился с PID = %d, PPID = %d!\n", name, getpid(), getppid());
}

pid_t create(module_t module, int exit_code)
{
	pid_t pid = fork();
	if (pid == -1) exit(EXIT_FAILURE);

	if (pid == 0)
	{
		module();
		exit(exit_code);
	}
	
	return pid;
}

void main()
{
    blue();
}