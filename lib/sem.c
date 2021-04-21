#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include "sem.h"

#include "../core.h"

int _semid = -1;

int semid()
{
	if (_semid != -1) return _semid;

	key_t key = ftok(__FILE__, 0);
    if (key < 0) err("Can\'t generate key");

    _semid = semget(key, 4, 0600 | IPC_CREAT);
    if (_semid < 0) err("Can\'t get semid");

	return _semid;
}

void sem(int number, int operation)
{
    struct sembuf buf = { 
		.sem_num = number,
		.sem_op = operation,
		.sem_flg = 0
	};

    semop(semid(), &buf, 1);
}

int sem_getval(int number)
{
	return semctl(semid(), number, GETVAL);
}

void sem_setval(int number, int value)
{
	semctl(semid(), number, SETVAL, value);
}