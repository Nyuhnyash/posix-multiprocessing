#define NAME "PURPLE"

#include <unistd.h>
#include <sys/wait.h>
#include "core.h"

void purple()
{
	int orange_exit_code;
	pid_t orange_pid = create(orange, orange_exit_code);

	greeting(NAME);
	wait(&orange_exit_code);
	bye(NAME);
}