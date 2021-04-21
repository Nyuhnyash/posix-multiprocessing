#include <sys/shm.h>
#include <errno.h>
#include <stdio.h>

#include "../core.h"

int create_shm()
{
	key_t key = ftok(__FILE__, 0);
    if (key < 0) err("Can\'t generate key");

    int shmid = shmget(key, sizeof(int), 0600 | IPC_CREAT | IPC_EXCL);
    if (shmid < 0)
    {
        if (errno != EEXIST) 
			err("Can\'t create shared memory");

        if ((shmid = shmget(key, sizeof(int), 0)) < 0)
			err("Can\'t find shared memory");
    }

	return shmid;
}

int *attach_shm()
{
	int *address = shmat(create_shm(), NULL, 0);
	if (address == (int *)-1)
		err("Can't attach shared memory");
	return address;
}

void detach_shm(int *address)
{
	if (shmdt((void *)address) < 0)
		err("Can't detach shared memory");
}