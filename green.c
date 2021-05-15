#define NAME "GREEN"

#include "core.h"
#include "lib/fifo.h"
#include "lib/sem.h"
#include "pathnames.h"

#define MAX_LINES 32

void green()
{
	greeting(NAME);

	int lengths[MAX_LINES] = {0};
	int count = swap_XY(YELLOW_GREEN_FIFO_PATH, lengths);

	if (count > MAX_LINES)
		err("Input file is too long");

	printf("%s получил %d строки через FIFO\n", NAME, count);

	for (int i = 0; i < count; i++)
	{
		sem(GREEN_ORANGE_SEM_SYNC, 0);
		sem_setval(GREEN_ORANGE_SEM_VALUE, lengths[i]);
		printf("%s передал, посредством семафора: %d\n", NAME, lengths[i]);
		sem(GREEN_ORANGE_SEM_SYNC, i + 1 < count ? 2 : 3);
	}

	bye(NAME);
}