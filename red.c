#define NAME "RED"

#include <sys/wait.h>
#include "core.h"

void red()
{
	int purple_exit_code;
	pid_t purple_pid = create(purple, purple_exit_code);

	int yellow_exit_code;
	pid_t yellow_pid = create(yellow, yellow_exit_code);

	greeting(NAME);
	wait(&purple_exit_code);
	wait(&yellow_exit_code);
	bye(NAME);
}