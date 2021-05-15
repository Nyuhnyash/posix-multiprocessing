#define NAME "RED"

#include <sys/wait.h>
#include <fcntl.h>

#include "core.h"
#include "pathnames.h"
#include "lib/shm.h"
#include "lib/sem.h"

void red()
{
	int purple_exit_code;
	pid_t purple_pid = create(purple, purple_exit_code);

	int yellow_exit_code;
	pid_t yellow_pid = create(yellow, yellow_exit_code);

	greeting(NAME);

	sem(ORANGE_RED_SEM, -1);
	int *sum = attach_shm();

	printf("%s получил из разделяемой памяти: %d\n", NAME, *sum);

	if (!access(RED_RESULT_PATH, F_OK))
		remove(RED_RESULT_PATH);
	int fd = open(RED_RESULT_PATH, O_WRONLY | O_CREAT | O_EXCL, 0666 /*S_IRUSR | S_IWUSR*/);
	write(fd, sum, sizeof(int));

	close(fd);

	detach_shm(sum);

	sem(RED_PURPLE_SEM, 1);

	waitpid(yellow_pid, &yellow_exit_code, 0);
	waitpid(purple_pid, &purple_exit_code, 0);
	bye(NAME);
}