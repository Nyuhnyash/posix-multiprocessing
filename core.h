#include <unistd.h>

void greeting(char *);
void bye(char *);

typedef void(*color_t)(void);

pid_t create(color_t, int);

void blue(void);
void red(void);
void purple(void);
void orange(void);
void yellow(void);
void green(void);