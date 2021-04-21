#include <sys/sem.h>

#define GREEN_ORANGE_SEM 0
#define ORANGE_RED_SEM 1
#define PROCESS_COUNTER_SEM 2
#define RED_PURPLE_SEM 3

#define LAST_LENGTH 10000

void sem(int number, int operation);

int sem_getval(int number);
void sem_setval(int number, int value);