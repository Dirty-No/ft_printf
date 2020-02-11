#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <limits.h>

void wrap_print_form(char *format, ...)
{
	va_list lst;
	
	va_start(lst, format);
	print_form(format, &lst, no_write);
	va_end(lst);
}

void tst_printf(char *format, ...)
{
	int nb1;
	int nb2;
	va_list lst;
	va_list	cpy;

	va_start(lst, format);
	va_copy(cpy, lst);
	printf("\033[1;35m\n###############\t\tFORMAT : (%s)\t###############\n\033[1;32mprintf:\t\t", format);
	fflush(stdout);
	nb1 = vprintf(format, lst);
	fflush(stdout);
	printf("\033[1;36m\nft_printf:\t");
	fflush(stdout);
	nb2 = ft_vprintf(format, &cpy, write);
	printf("\n");
	va_end(lst);
	va_end(cpy);
	printf("\033[1;35m\n###############\t\tRETURN VALUES\t\t###############\n\033[1;32mprintf:\t\t|%d|\n\033[1;36mft_printf:\t|%d|\n\n\033[1;34m***************************************************************\n\033[0m", nb1, nb2);
	fflush(stdout);
}

void	test1(void)
{
	char	*ptr = malloc(1);
	char 	str[]= "\nyeeet |%%| |%c| |%d| |%p| |%X| |%s| \\|%s|\\ \
HOHOOHOHOH MINNIE VOYONS QU'EST-CE QUE TU FAISs--d- \
|%6d| |%-03d|_|%%| |%00*d| |%15.10d| |%-15.10d| |%15.1d|\n";

	ft_printf("\nft_printf (%d)\n", ft_printf(str, 'P', 3, ptr, 756,
			   	"JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500,
			   	9, 10, 7777, 123456789, -123456789, 123456789));

	printf("\nprintf (%d) \n", printf(str, 'P', 3, ptr, 756,
			   	"JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500,
			   	9, 10, 7777, 123456789, -123456789, 123456789));
	free(ptr);
}

void	test2(void)
{
	int nb1;
	int nb2;

	write(1, "ft_printf:\t", 11);
	nb1 = ft_printf("|%0*d|\n", 10, 7777);
	write(1, "printf:\t\t", 9);
	nb2 = printf("|%0*d|\n", 10, 7777);
	printf("ft_printf: %d | printf: %d\n", nb1, nb2);
}

void	test3(void)
{
	ft_printf("|% d|\n", 0x9999);
	printf("|% d|\n", 0x9999);
}

/*	undefined
void test4(void)
{
	//undefined
	ft_printf("|%-0", 42);
	printf("|%-0", 42);
	//#if 1
	// #warning "helps"
	//	#endif
}
*/

void test5(void)
{
	int		nb1;
	int		nb2;
	char 	str[]= "\nyeeet |%%| |%c| |%d| |%p| |%X| |%s| \\|%s|\\ HOHOOHOHOH MINNIE VOYONS QU'EST-CE QUE TU FAISs--d- |%6d| |%-03d|_|%%| |%00*d|\n";
	char	*ptr = malloc(1);

	nb1 = printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	fflush(stdout);
	nb2 = ft_printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	printf("%d|%d\n", nb1, nb2);	

	ft_printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	//printf(str, 'P', 3, ptr, 756, "JE SUIS UNE PETITE SOURIS AHAHA", NULL, 500, 9, 10, 7777);
	free(ptr);
}

void test6(void)
{
	int		nb1;
	int		nb2;

	nb1 = printf("Bonjour\n");
	nb2 = ft_printf("Bonjour\n");
	printf("%d|%d\n", nb1, nb2);
}

void test7(void)
{
	int		nb1;
	int		nb2;
	char	str[]= "|%15.10d|\n";

	nb1 = printf(str, -1234567);
	nb2 = ft_printf(str, -1234567);
	printf("%d|%d\n", nb1, nb2);
}

void test8(void)
{
	//minimal field width + precision with ints
	int		nb1;
	int		nb2;
	char	str[]= "|%-15.10d|\n";

	nb1 = printf(str, -1234567);
	nb2 = ft_printf(str, -1234567);
	printf("%d|%d\n", nb1, nb2);
}

void test9(void)
{
	//ONLY PRECISION WITH NUMBERS
	int		nb1;
	int		nb2;
	char	str[]= "|%.20p| |%.20x| |%.20X|\n";

	nb1 = printf(str, (char *)-50, -50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}

void test10(void)
{
	//undefined
	int		nb1;
	int		nb2;
	char	str[]= "|%-1-5.10p|  |%-1-5.10X|\n";

	nb1 = printf(str, (char *)-50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}

void test11(void)
{
	//undefined
	int		nb1;
	int		nb2;
	char	str[]= "|%1-5.10p| |%1-5.10X|\n";

	nb1 = printf(str, (char *)-50, -50);
	nb2 = ft_printf(str, (char *)-50, -50);
	printf("%d|%d\n", nb1, nb2);
}

void test12(void)
{
	//	undefined ?
	int		nb1;
	int		nb2;
	char	str[]= "|%15-1d|\n";
	nb1 = printf(str, 123456789);
	nb2 = ft_printf(str, 123456789);
	printf("%d|%d\n", nb1, nb2);
}

void test13(void)
{
	int		nb1 = 0;
	int		nb2 = 0;
	//undefined (SEGFAULT)
	//nb1 = printf(NULL);
	nb2 = ft_printf(NULL);
	printf("%d|%d\n", nb1, nb2);
}

void test14(void)
{
	//minimal field width + precision with ints POSITIVE
	int		nb1;
	int		nb2;
	char	str[]= "|%15.10d|\n";

	nb1 = printf(str, 1234567);
	nb2 = ft_printf(str, 1234567);
	printf("%d|%d\n", nb1, nb2);
}

void test15(void)
{
	//minimal field width + precision with chars
	int		nb1;
	int		nb2;
	char	str[]= "|%015.10c| |%015c|\n";

	nb1 = printf(str, 'O', 'O');
	nb2 = ft_printf(str, 'O', 'O');
	printf("%d|%d\n", nb1, nb2);
}

void test16(void)
{
	//minimal field width + LOW precision with ints POSITIVE
	int		nb1;
	int		nb2;
	char	str[]= "|%15.2X|\n";

	nb1 = printf(str, 1234567);
	nb2 = ft_printf(str, 1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test17(void)
{
	//minimal field width + LOW precision with unsigned hex int + int
	int		nb1;
	int		nb2;
	char	str[]= "|%15.1p|\t|%15.11d|\n";

	nb1 = printf(str, 1234567, 1234567);
	nb2 = ft_printf(str, 1234567, 1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test18(void)
{
	// 0 padding + * flag + negative int
	int		nb1;
	int		nb2;
	char	str[]= "|%0*d|\n";
	
	write(1, "printf:\t\t", 9);
	nb1 = printf(str, 20, -1234567);
	write(1, "ft_printf:\t", 11);
	nb2 = ft_printf(str, 20, -1234567);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void test19(void)
{
	// POINTER PADDING
	int		nb1;
	int		nb2;
	int		nb_in = -1234567;
	int		width = 20;
	char	str[]= "(%0*p)\t(%*p)\t(%-0*p)\t(%-*p)\n";
	
	write(1, "printf:\t\t", 9);
	nb1 = printf(str, width, nb_in, width, nb_in, width, nb_in, width, nb_in);
	write(1, "ft_printf:\t", 11);
	nb2 = ft_printf(str, width, nb_in, width, nb_in, width, nb_in, width, nb_in);
	printf("printf : %d | ft_printf %d\n", nb1, nb2);
}

void hello_world(void)
{
	tst_printf("|Hello World!|");
}

void	solo_int(int nb)
{
	tst_printf("|%d|", nb);
}

void	null_format(void)
{
	///UNDEFINED (real printf segfaults)
	tst_printf(NULL);
}

int main(void)
{
//	wrap_print_form("%50.100000d", 1234567);
//	solo_int(50);
	tst_printf("%-*.*s", -7, -3, "yolo");
//	test1();
//	system("leaks a.out");
	return (0);
}
