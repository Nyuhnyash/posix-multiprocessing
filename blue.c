#define NAME "BLUE"

#include <sys/wait.h>
#include "core.h"

void blue()
{
	int red_exit_code;
	pid_t red_pid = create(red, red_exit_code);

	greeting(NAME);
	wait(&red_exit_code);
	bye(NAME);
}