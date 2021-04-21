#define NAME "BLUE"

#include <sys/wait.h>
#include <stdio.h>

#include "core.h"
#include "lib/sem.h"

int processes_count = 0;

void sig_handler(int signal)
{
	if (signal == SIGUSR1)
		processes_count++;
	if (signal == SIGUSR2)
		processes_count--;
	
	fprintf(stderr, "Количество процессов: %d\n", processes_count);
	sem(PROCESS_COUNTER_SEM, 1);
}

void blue()
{
	sem_setval(PROCESS_COUNTER_SEM, 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	
	int red_exit_code;
	pid_t red_pid = create(red, red_exit_code);

	greeting(NAME);
	wait(&red_exit_code);
	bye(NAME);
}