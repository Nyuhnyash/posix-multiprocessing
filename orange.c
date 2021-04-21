#define NAME "ORANGE"

#include <stdio.h>

#include "core.h"
#include "lib/sem.h"
#include "lib/shm.h"


void orange()
{
	greeting(NAME);

	int val = 0;
	int *sum = attach_shm();
	*sum = 0;

	while(1)
	{
		sem(GREEN_ORANGE_SEM, -1);
		val = sem_getval(GREEN_ORANGE_SEM);
		if (val + 1 == LAST_LENGTH) 
		{
			sem_setval(GREEN_ORANGE_SEM, 0);
			break;
		}

		*sum += val;
		printf("%s получил, посредством семафора: %d\n", NAME, val);
		sem(GREEN_ORANGE_SEM, -val);
	}

	detach_shm(sum);

	sem(ORANGE_RED_SEM, 1);
	
	bye(NAME);
}
