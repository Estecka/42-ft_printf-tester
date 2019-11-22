/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:30:43 by abaur             #+#    #+#             */
/*   Updated: 2019/11/22 15:50:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

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
	expected = vprintf(format, argscpy);
	printf("\n");

	returned = ft_vprintf(format, args);
	printf("\n");

	va_end(argscpy);
	va_end(args);

	if (expected != returned)
		printf("\t Expected: %d \n\t Returned: %d \n", expected, returned);
}

void TestPrintf()
{
	printf("\n\n\tft_vprintf\n");

	TestOnePrintf("Boop");
	TestOnePrintf("Digit %d", 5);
	TestOnePrintf("String %s", "Soupe au choux");
	TestOnePrintf("Zeroed string %010s", "Gnouh");
	TestOnePrintf("Hexa %x %x", 0, 32);
	TestOnePrintf("Octa %o %o", 0, 32);
	TestOnePrintf("Vraie fausse alerte %%", 0, 0);
	TestOnePrintf("Fausse vraie alerte %wysiwyg", 0);
	TestOnePrintf("Double Padding !! %3-010d", 0);
	TestOnePrintf("Je beguaie %-0-0d", 5);

	TestOnePrintf("Padding de base %14d", -42);
	TestOnePrintf("Padding a la con %#+010X", 256);
	TestOnePrintf("Padding mesquin % 2d", 0);
	TestOnePrintf("Mesquinerie sans nom %##X", 5);

	TestOnePrintf("I got a %s, Woho, ho", "hangover");
}

int	main()
{
	TestPrintf();
}
