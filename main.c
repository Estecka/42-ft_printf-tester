/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:30:43 by abaur             #+#    #+#             */
/*   Updated: 2019/11/28 14:52:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int    vprintf(const char* format, va_list args); // Defined in stdio.
int ft_vprintf(const char* format, va_list args); // Needs to be defined by you.

static void TestOnePrintf(const char* format, ...)
{
	va_list args;
	va_list argscpy;

	int expected;
	int returned;

	va_start(args, format);
	va_copy(argscpy, args);

	printf("\n");
	printf("\"%s\"\n\"", format);

	expected = vprintf(format, argscpy);
	printf("\"\n");

	write(1, "\"", 1);
	returned = ft_vprintf(format, args);
	printf("\"\n");

	va_end(argscpy);
	va_end(args);

	if (expected != returned){
		printf("\033[1;31m");
		printf("\t Expected: %d \n\t Returned: %d \n", expected, returned);
		printf("\033[0m");
	}
}

void TestPrintf()
{
	printf("\n\n\tft_vprintf\n");

	TestOnePrintf("Boop");
	TestOnePrintf("Vraie fausse alerte %%", 0, 0);
	TestOnePrintf("Fausse vraie alerte %wysiwyg", 0);
	TestOnePrintf("Alerte a la con %\0", 0);

	TestOnePrintf("String %s", "Soupe au choux");
	TestOnePrintf("Zeroed string %010s", "Gnouh");
	TestOnePrintf("Padded string `%10s`", "Bneh");
	TestOnePrintf("Left padded string `%-010s`", "Poux");

	TestOnePrintf("Characters %c, %5c, %05c, %-5c, %#-05c", '%', '5', ' ', '-', '0');
	TestOnePrintf("Decimal %d, %d, %d, %015d, %-015d", 0, INT_MIN, INT_MAX, INT_MIN, INT_MAX);
	TestOnePrintf("Unsigned %u, %u, %015u, %-015u", 0, UINT_MAX, INT_MAX, UINT_MAX);
	TestOnePrintf("Octa %o, %o, %010o, %-010o", 0, UINT_MAX, INT_MAX, UINT_MAX);
	TestOnePrintf("Hexa %x, %x, %010x, %-010x", 0, UINT_MAX, INT_MAX, UINT_MAX);
	TestOnePrintf("HEXA %X, %X, %010X, %-010X", 0, UINT_MAX, INT_MAX, UINT_MAX);

	TestOnePrintf("Double Padding !! %3-010d", 0);
	TestOnePrintf("Je beguaie %-0-0d", 5);
}

int	main()
{
	TestPrintf();
}
