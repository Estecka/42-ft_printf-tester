/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:30:43 by abaur             #+#    #+#             */
/*   Updated: 2019/12/02 14:19:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#include "testmaker.h"
#include "logutil.h"

int    vprintf(const char* format, va_list args); // Defined in stdio.
int ft_vprintf(const char* format, va_list args); // Needs to be defined by you.

static void TestOnePrintf(const char* format, ...)
{
	va_list args;
	va_start(args, format);

	printTitle(format);
	Test(format, args);

	va_end(args);
}

int main()
{
	const char* basicUnitTests[] = {
		"%?",
		"%5?",
		"%10?",
		"%-06?",
		"%.5?",
		"%.010?",
		"%.0?",
		"%.?",
		"%05.10?",
		"%010-.5?",
		"%.10-5?",
		"%-05.10-010.5?",
		NULL
	};

	printfc(YELLOW, 1, "\n\n\tft_vprintf\n");

	printfc(BLUE, 1, "\tBasic tests\n");
	UnitTestAll(basicUnitTests, '%', 1, 0);
	UnitTestAll(basicUnitTests, 'c', 5, '\0', 'a', '%', ' ', '\255');
	UnitTestAll(basicUnitTests, 's', 5, "Schtroumpf", "Gnouh", "Poux", "\0Surprise madafaka", NULL);
	UnitTestAll(basicUnitTests, 'd', 7, 0, 1, -1, 1010, -1010, INT_MAX, INT_MIN);
	UnitTestAll(basicUnitTests, 'i', 7, 0, 1, -1, 1010, -1010, INT_MAX, INT_MIN);
	UnitTestAll(basicUnitTests, 'u', 5, 0, 1, 1010, INT_MAX, UINT_MAX);
	UnitTestAll(basicUnitTests, 'x', 5, 0, 1, 1010, INT_MAX, UINT_MAX);
	UnitTestAll(basicUnitTests, 'X', 5, 0, 1, 1010, INT_MAX, UINT_MAX);
	UnitTestAll(basicUnitTests, 'u', 5, 0, 1, 1010, INT_MAX, UINT_MAX);
	UnitTestAll(basicUnitTests, 'u', 5, 0, 1, 1010, INT_MAX, UINT_MAX);
	UnitTestAll(basicUnitTests, 'p', 5, NULL, "Boop", "Tourte", INT_MAX, UINT_MAX);


	printfc(BLUE, 1, "\tParametric precision\n");
	TestOnePrintf("%.*s", 5, "string");
	TestOnePrintf("%.*d", 5, "13");
	TestOnePrintf("%.*p", 5, "Woop de do");
	TestOnePrintf("%.*p", 0, NULL);
	TestOnePrintf("%.*X", 0, 0);
	TestOnePrintf("%.*x", 0, 0);


	printfc(BLUE, 1, "\n\t Random Tests\n");
	TestOnePrintf("The %.*s %c%-2c%x.", 5, "heavyyyyyyy", 'i', 's', 0xdead);
	TestOnePrintf("Th%-2xh%xvy is%5X ?!?", 0xe, 0xea, 0xDEAD);
	TestOnePrintf("%-4s%.0u!", "YES", 0);
	TestOnePrintf("H%-2X%XI%-3X!", 0xE, 0xD, 0xED);
}
