#define NAME "PURPLE"

#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "core.h"
#include "lib/sem.h"
#include "pathnames.h"

void purple()
{
	int orange_exit_code;
	pid_t orange_pid = create(orange, orange_exit_code);

	greeting(NAME);

	wait(&orange_exit_code);

	sem(RED_PURPLE_SEM, -1);

	time_t     now = time(0);
    struct tm  tstruct;
    char       dirname[80];
    strftime(dirname, sizeof(dirname), "result_%Y-%m-%d_%X", localtime(&now));

	if (mkdir(dirname, S_IRWXU))
		err("mkdir() error");

	char *oldpaths[2] = { YELLOW_GREEN_FIFO_PATH, RED_RESULT_PATH };
	char newpath[128];
	char *oldpath; 

	for(int i = 0; i < 2; i++)
	{
		oldpath = oldpaths[i];
		sprintf(newpath, "%s/%s", dirname, oldpath);
		if (rename(oldpath, newpath))
			err("rename err");
		if (symlink(newpath, oldpath))
			err("symlink() error");
	}

	bye(NAME);
}