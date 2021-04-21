#define NAME "YELLOW"

#include <sys/wait.h>

#include "core.h"
#include "lib/fifo.h"
#include "pathnames.h"

void yellow()
{
	create_fifo(YELLOW_GREEN_FIFO_PATH);

	int green_exit_code;
	pid_t green_pid = create(green, green_exit_code);

	greeting(NAME);

	print_unchanged(YELLOW_GREEN_FIFO_PATH);

	wait(&green_exit_code);
	bye(NAME);
}