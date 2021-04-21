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
	int count = print_swapped_XY(YELLOW_GREEN_FIFO_PATH, lengths);
	if (count > MAX_LINES)
		err("Input file is too long");

	for (int i = 0; i < count; i++)
	{
		sem(GREEN_ORANGE_SEM, 1 + lengths[i]);
		sem(GREEN_ORANGE_SEM, 0);
	}

	sem(GREEN_ORANGE_SEM, LAST_LENGTH);

	bye(NAME);
}