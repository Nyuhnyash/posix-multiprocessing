#include <unistd.h>

void greeting(char *);
void bye(char *);

typedef void(*module_t)(void);

pid_t create(module_t, int);

void blue(void);
void red(void);
void purple(void);
void orange(void);
void yellow(void);
void green(void);