/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:30:43 by abaur             #+#    #+#             */
/*   Updated: 2019/11/21 14:47:02 by abaur            ###   ########.fr       */
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

	int result;

	va_start(args, format);
	va_copy(argscpy, args);

	result = vprintf(format, argscpy);
	printf("\t=> %d\n", result);

	result = ft_vprintf(format, args);
	printf("\t=> %d\n", result);

	va_end(argscpy);
	va_end(args);

	printf("\n");
}

void TestPrintf()
{
	printf("\n\n\tft_vprintf\n");

	TestOnePrintf("Boop");
	TestOnePrintf("Digit %d", 5);
	TestOnePrintf("String %s", "Soupe au choux");
	TestOnePrintf("Hexa %x %x", 0, 32);
	TestOnePrintf("Octa %o %o", 0, 32);
	TestOnePrintf("Fausse alerte %%");
	TestOnePrintf("Fausse vraie alerte %w");

	TestOnePrintf("I got a %s, Woho, ho", "hangover");
}

int	main()
{
	TestPrintf();
}
