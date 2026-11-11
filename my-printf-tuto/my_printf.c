#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

static int put_char(char c)
{
    return write(1, &c, 1);
}

static int put_str(char *s)
{
    int count = 0;

    if (s == NULL)
        s = "(null)";
    while (*s)
        count += put_char(*s++);
    return count;
}

static int put_nbr(int n)
{
    long nb = n;
    int count = 0;

    if (nb < 0)
    {
        count += put_char('-');
        nb = -nb;
    }
    if (nb >= 10)
        count += put_nbr((int)(nb / 10));
    count += put_char((nb % 10) + '0');
    return count;
}

static int put_hex(uintptr_t n)
{
    char *digits = "0123456789abcdef";
    int count = 0;

    if (n >= 16)
        count += put_hex(n / 16);
    count += put_char(digits[n % 16]);
    return count;
}

static int put_ptr(void *p)
{
    int count = 0;

    count += put_str("0x");
    count += put_hex((uintptr_t)p);
    return count;
}

int my_printf(char * restrict format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            if (format[i] == 'c')
                count += put_char((char)va_arg(args, int));
            else if (format[i] == 's')
                count += put_str(va_arg(args, char *));
            else if (format[i] == 'd')
                count += put_nbr(va_arg(args, int));
            else if (format[i] == 'p')
                count += put_ptr(va_arg(args, void *));
            else if (format[i] == '%')
                count += put_char('%');
            else
            {
                count += put_char('%');
                count += put_char(format[i]);
            }
        }
        else
            count += put_char(format[i]);
    }
    va_end(args);
    return count;
}
