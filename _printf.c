
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            // Handle %c specifier
            if (*format == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
