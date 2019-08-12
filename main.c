/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:49:57 by forange-          #+#    #+#             */
/*   Updated: 2019/08/13 00:10:54 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include "ft_printf.h"

int	main(void)
{
	/*
 	char				ch_min = CHAR_MIN;
	char				ch_max = CHAR_MAX;
	unsigned char		u_ch_max = UCHAR_MAX;
	short				shrt_min = SHRT_MIN;
	short				shrt_max = SHRT_MAX;
	unsigned short		u_shrt_max = USHRT_MAX;
	int					i_min = INT_MIN;
	int					i_max = INT_MAX;
	unsigned int		u_i_max = UINT_MAX;
	long				l_i_min = LONG_MIN;
	long				l_i_max = LONG_MAX;
	unsigned long		u_l_i_max = ULONG_MAX;
	long long			ll_i_min = LLONG_MIN;
	long long			ll_i_max = LLONG_MAX;
	unsigned long long	u_ll_i_max = ULLONG_MAX;
	float				f = 0.0;
	double				d = 0.0;
	long double			l_d = 1.3;

	float fl = 1.3;
	double db = 1.1;
	long double ldb1 = 1.1;
 */

/* 	t_printf			print;

	ft_bzero(&print, sizeof(t_printf));
	print.flag |= L_BIGL;

	if (!(print.flag ^ L_HH))
		printf ("YES!!!!\n");
 *//*
	printf("%c\n", ch_min - 1);
	printf("%c\n", ch_max);
	printf("%c\n", u_ch_max);
	printf("%8i\n", shrt_min);
	printf("%8i\n", shrt_max);
	printf("%10hu\n",u_shrt_max);
	printf("%i\n", i_min);
	printf("%i\n", i_max);
	printf("%u\n", u_i_max);
	printf("%li\n", l_i_min);
	printf("%li\n", l_i_max);
	printf("%lu\n", u_l_i_max);
	printf("%lli\n", ll_i_min);
	printf("%lli\n", ll_i_max);
	printf("%llu\n", u_ll_i_max);
	printf("%f\n", f);
	printf("%f\n", d);
	printf("%Lf\n", l_d);
	printf("%hhd\n", (char)i_max);
*/
//	printf("%f\n", 0.1/1);
//	printf("%X !destiny\n", -6, 5);

	/*
	* принтф читает последовательность только пока она валидная.
	* C первым неавлидным знаком он прекращает обрабатывать текст,
	* как формат и начинает его выводить, как строку.
	*
	* Надо как-то обойти сегу при попытке обращения к невалидному указателю. Пример:
	* printf ("%s", -5);
	*/
//	printf("%7ud\n", -1);
/*
		union
		{
			long double ldb;
			short exp;
			unsigned long long mant;
		} u_float;

	long long mask = 1;
	(void)mask;

	u_float.ldb = ldb1;

	db = 1.3;
	printf("LONG DOUBLE\n");
	printf("%.50Lf Lf\n", l_d);
	printf("%.50f f\n", l_d);
	printf("%.50lf lf\n", l_d);
	printf("\nDOUBLE\n");
	printf("%.50Lf Lf\n", db);
	printf("%.50f f\n", db);
	printf("%.50lf lf\n", db);
	printf("\nFLOAT\n");
	printf("%.50Lf Lf\n", fl);
	printf("%.50f f\n", fl);
	printf("%.50lf lf\n\n", fl);
*/

//	wchar_t *a = L"Ё";

//	printf("%s\n", L"Ё");
//	printf("%ls\n", L"Ё");
//	printf("%c\n", L'Ё');
//	printf("%lc\n", L'Ё');
//	printf("%ls\n", "Ё");
/*
	printf("%s\n", "my 123");
	printf("%2s\n", "my 123");
	printf("%10s\n", "my 123");
	printf("%-10.4s\n", "my 123");
	printf("%10.4s\n", "my 123");
	int out = printf("%.s", "my 123");
	printf ("out = %d\n", out);
	printf("%-10.4s\n", "my 123");
	printf("%10.15s\n", "my 123");
	printf("%10.1s\n", "my 123");
	printf("%2.1s\n", "my 123");
	printf("%10.s\n", "my 123");
	printf("%2.3s\n", "my 123");
	printf("%-2.3s\n", "my 123");
 */
//	printf ("%f\n", fl);
//	printf("%lf\n", db);
//	printf("%Lf\n", ldb1);
//	printf("%5hh07d\n", 5); 			/* флаги учитываются всегда */
//	printf("%hL hhdQQ\n", 5000000);		/* спецификатор длины всегда читается */
//	printf("%hhd\n", shrt_min);
//	printf("% #+0 06d\n", 6);
//
//	ft_printf("%-4.2s\n", "12345");
	//printf("%-4.2s\n", "12345");

//	ft_printf("%4.2s\n", "12345");
	//printf("%4.2s\n", "12345");
//	printf("%4c\n", 'a');
//	ft_printf("%4c\n", 'a');
//	printf("%-4c\n", 'a');
//	ft_printf("%-4c\n", 'a');
/*
	printf("%%\n");
	ft_printf("%%\n");

	printf("%4%\n");
	ft_printf("%4%\n");

	printf("%-4%\n");
	ft_printf("%-4%\n");
	 */
	/*
	int out = printf("%10.s\n", NULL);
	printf("%d\n", out);
 */
/*
	printf ("%p\n", (void*)0x0);
	printf ("%p\n\n", a);

	printf ("%10p\n", (void*)0x0);
	printf ("%10p\n\n", a);

	printf ("%-10p\n", (void*)0x0);
	printf ("%-10p\n\n", a);

	printf ("%p\n", NULL);
	ft_printf("%p\n\n", (void*)0xff);

	printf ("%lx\n", (long)-256);
	printf ("%lx\n\n", (long)256);

	printf ("%x\n", INT_MIN);
	printf ("%x\n\n", INT_MAX);
*/
	long double		ld;

	ld = 3141500.314158887;
	/*
	printf("flag F_ZERO\n%12f||||||\n", (float)-1546545546654.545);
	printf("%012f||||||\n", (float)-0.545);
	printf("%12.1f||||||\n", (float)-0.545);
	printf("%012.1f||||||\n", (float)-0.545);
	printf("flag F_MINUS\n% 012f||||||\n", (float)0.545);
	printf("%-12f||||||\n", (float)0.545);
	printf("% 012.1f||||||\n", (float)0.545);
	printf("%-12.1f||||||\n", (float)0.545);
	*/
	printf("ld = '% -12Lf';\n", ld);
	ft_printf("ld = '% -12Lf';\n\n\n", ld);

	int out = printf("%f", 0.000001);
	printf("\nout = %d\n", out);
	out = ft_printf("%f", 0.000001);
	printf("\nout = %d\n", out);

	printf ("%lx\n", LONG_MIN);
	ft_printf ("%lX #\n", LONG_MIN);
	printf ("%lx\n\n", LONG_MAX);
	ft_printf ("%#0.5lX\n\n", LONG_MAX);

	printf ("%llx\n", LLONG_MIN);
	ft_printf ("%llx\n", LLONG_MIN);
	printf ("%llx\n\n", LLONG_MAX);
	ft_printf ("%llx\n\n", LLONG_MAX);

	//printf("%15.1%%s\n", "test");
	ft_printf("%15.1%%s\n", "test");

	printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	out = printf("%42.8ls", L"");
	printf("\nout = %d\n", out);
	out = ft_printf("%42.8ls", L"");
	printf("\nout = %d\n", out);

	setlocale(LC_ALL, "en_US.UTF-8");
/*
	printf("%#13.10x\n", 256);
	printf("%015.hhx\n", (unsigned char)234);
	printf("%#13.10hx\n", (unsigned short)256);
	printf("%#13.10lx\n", (unsigned long)256);

	int out = printf("%4.3s", "1Ёжи");
	printf("\nout = %d\n", out);
	out = ft_printf("%4.3s", "1Ёжи");
	printf("\nout = %d\n\n", out);

	out = printf("%30ls", L"(╯°Д°)╯︵/(.□ . \\)");
	printf("\nout = %d\n", out);
	out = ft_printf("%30ls", L"(╯°Д°)╯︵/(.□ . \\)");
	printf("\nout = %d\n\n", out);

	out = printf("%c", (char)123456);
	printf("\nout = %d\n", out);
	out = ft_printf("%c", (char)123456);
	printf("\nout = %d\n", out);
*/
	return (0);
}
