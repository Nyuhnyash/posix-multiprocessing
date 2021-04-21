#include <unistd.h>

void greeting(const char *);
void bye(const char *);
void err(const char *);

typedef void(*module_t)();

pid_t create(module_t, int);

void blue();
void red();
void purple();
void orange();
void yellow();
void green();