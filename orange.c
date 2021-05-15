#define NAME "ORANGE"

#include "core.h"
#include "lib/sem.h"
#include "lib/shm.h"

void orange()
{
	greeting(NAME);

	int val = 0;
	int *sum = attach_shm();
	*sum = 0;

	sem_setval(GREEN_ORANGE_SEM_SYNC, 0);

	while (1)
	{
		sem(GREEN_ORANGE_SEM_SYNC, -1);

		val = sem_getval(GREEN_ORANGE_SEM_VALUE);

		*sum += val;
		printf("%s получил, посредством семафора: %d\n", NAME, val);

		if (sem_getval(GREEN_ORANGE_SEM_SYNC) == 2)
			break;

		sem(GREEN_ORANGE_SEM_SYNC, -1);
	}

	printf("%s сохранил в разделяемой памяти: %d\n", NAME, *sum);
	detach_shm(sum);

	sem(ORANGE_RED_SEM, 1);

	bye(NAME);
}
