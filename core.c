#include <stdlib.h>
#include <signal.h>

#include "core.h"
#include "lib/sem.h"

pid_t first;

void greeting(const char *name)
{
	fprintf(stderr, "%s запустился с PID = %d, PPID = %d!\n", name, getpid(), getppid());
	sem(PROCESS_COUNTER_SEM, -1);
	kill(first, SIGUSR1);
}

void bye(const char *name)
{
	fprintf(stderr, "%s завершился с PID = %d, PPID = %d!\n", name, getpid(), getppid());
	sem(PROCESS_COUNTER_SEM, -1);
	kill(first, SIGUSR2);
}

void err(const char *text)
{
	fprintf(stderr, "%s\n", text);
	kill(0, SIGINT);
}

pid_t create(module_t module, int exit_code)
{
	pid_t pid = fork();
	if (pid == -1)
		err("Failed to fork()");

	if (pid == 0)
	{
		module();
		exit(exit_code);
	}

	return pid;
}

void main()
{
	first = getpid();
	blue();
}
