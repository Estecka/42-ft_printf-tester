/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:43:58 by abaur             #+#    #+#             */
/*   Updated: 2019/11/29 16:43:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int vprintfc(int colour, short bold, const char* format, va_list args)
{
	int r = 
		   printf("\033[%d;%dm", bold ? 1 : 0, colour)
		 + vprintf(format, args)
		 + printf("\033[0m")
		;
	va_end(args);
	return r;
}

int printfc(int colour, short bold, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	return vprintfc(colour, bold, format, args);
}
