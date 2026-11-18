#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_print_reverse_alphabet()
{
    char c = 'z';

    while (c >= 'a')
    {
        my_putchar(c);
        c--;
    }
    my_putchar('\n');
}
