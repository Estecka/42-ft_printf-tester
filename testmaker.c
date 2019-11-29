/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmaker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:17:37 by abaur             #+#    #+#             */
/*   Updated: 2019/11/29 18:17:43 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "logutil.h"
#include "../ft_printf.h"

void printTitle(const char* title)
{
	printfc(CYAN, 0, "\n\"%s\"\n", title);
}

short Test(const char* format, va_list args)
{
	va_list args1;
	va_list args2;

	int expected;
	int returned;

	va_copy(args1, args);
	va_copy(args2, args);

	printf("\"");
	expected = vprintf(format, args1);
	printf("\"\n");

	write(1, "\"", 1);
	returned = ft_vprintf(format, args2);
	printf("\"\n");

	if (expected != returned){
		printfc(RED, 1, "\tExpected : %d \n", expected);
		printfc(RED, 1, "\tReturned : %d \n", returned);
	}

	va_end(args1);
	va_end(args2);
	return expected == returned;
}

/*
** Runs all the arguments through the given test
*/
void UnitTest(const char* format, char type, int count, va_list args)
{
	format = strdup(format);

	for (char *str=(char*)format; *str; str++)
		if (*str == '?')
			*str = type;
	
	printTitle(format);
	for (int i=0; i<count; i++){
		Test(format, args);
		va_arg(args, long);
		printf("\n");
	}

	free((void*)format);
} 

/*
** Runs all the arguments through each of the given tests.
*/
void UnitTestAll(const char** const tests, char type, int count, ...)
{
	va_list args;


	for (const char** src=tests; *src; src++){
		va_start(args, count);
		UnitTest(*src, type, count, args);
		va_end(args);
	}

}
