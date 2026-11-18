#include <unistd.h>

void my_putstr(char* param_1)
{
    int i = 0;

    while (param_1[i] != '\0')
    {
        write(1, &param_1[i], 1);
        i++;
    }
}
