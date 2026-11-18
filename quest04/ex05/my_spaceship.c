#include <stdio.h>
#include <stdlib.h>

char* my_spaceship(char* param_1)
{
    char* names[] = {"up", "right", "down", "left"};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    int dir = 0;
    int x = 0;
    int y = 0;
    int i = 0;
    char* result;

    while (param_1[i] != '\0')
    {
        if (param_1[i] == 'R')
            dir = (dir + 1) % 4;
        else if (param_1[i] == 'L')
            dir = (dir + 3) % 4;
        else if (param_1[i] == 'A')
        {
            x += dx[dir];
            y += dy[dir];
        }
        i++;
    }
    result = malloc(64);
    if (result == NULL)
        return NULL;
    snprintf(result, 64, "{x: %d, y: %d, direction: '%s'}", x, y, names[dir]);
    return result;
}
