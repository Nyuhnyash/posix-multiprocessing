#define NAME "YELLOW"

#include <sys/wait.h>
#include "core.h"

void yellow()
{
	int green_exit_code;
	pid_t green_pid = create(green, green_exit_code);

	greeting(NAME);
	wait(&green_exit_code);
	bye(NAME);
}