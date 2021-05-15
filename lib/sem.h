#include <sys/sem.h>

#define GREEN_ORANGE_SEM_VALUE 0
#define GREEN_ORANGE_SEM_SYNC 1
#define ORANGE_RED_SEM 2
#define PROCESS_COUNTER_SEM 3
#define RED_PURPLE_SEM 4

void sem(int number, int operation);

int sem_getval(int number);
void sem_setval(int number, int value);