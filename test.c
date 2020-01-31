#include "libftprintf.h"

void wrap_print_form(char *format, ...)
{
	va_list lst;
	
	va_start(lst, format);
	print_form(format, &lst);
	va_end(lst);
}

int main(void)
{
	wrap_print_form("%-50.100000d", 1234567);
	return (0);
}
