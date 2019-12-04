/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logutil.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:13 by abaur             #+#    #+#             */
/*   Updated: 2019/12/03 16:28:07 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGUTIL_H
#define LOGUTIL_H

#include <stdarg.h>
#include <stdio.h>

#define RED     31
#define GREEN   32
#define YELLOW  33
#define BLUE    34
#define MAGENTA 35
#define CYAN    36

#define BEEP printf("Beep\n");
#define BOOP printf("Boop\n");

int  printfc(int colour, short boldness, const char* format, ...);
int vprintfc(int colour, short boldness, const char* format, va_list arguments);

#endif
