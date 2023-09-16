#include “main.h”

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */

int (*find_function(const char *format))(va_list)
{
 unsigned int i = 0;
 code_f find_f[] = {
  {"s", printf_string},
  {NULL, NULL}
 };

 while (find_f[i].sc)
 {
  if (find_f[i].sc[0] == (*format))
   return (find_f[i].f);
  i++;
 }
 return (NULL);
}
int _printf(const char *format, ...)
{
 va_list ap;
 int (*f)(va_list);
 unsigned int i = 0, cprint = 0;

 if (format == NULL)
  return (-1);
 va_start(ap, format);
 while (format[i])
 {
  while (format[i] != '%' && format[i])
  {
   putchar(format[i]);
   cprint++;
   i++;
  }
  if (format[i] == '\0')
   return (cprint);
  f = find_function(&format[i + 1]);
  if (f != NULL)
  {
   cprint += f(ap);
   i += 2;
   continue;
  }
  if (!format[i + 1])
   return (-1);
  putchar(format[i]);
  cprint++;
  if (format[i + 1] == '%')
   i += 2;
  else
   i++;
 }
 va_end(ap);
 return (cprint);
}
