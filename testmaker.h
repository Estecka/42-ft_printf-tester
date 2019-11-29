/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmaker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:18:15 by abaur             #+#    #+#             */
/*   Updated: 2019/11/29 17:46:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMAKER_H
#define TESTMAKER_H

#include <stdarg.h>

void	printTitle(const char* title);
void	LogFormat(const char* format);

short	Test(const char* format, va_list args);
void	UnitTest(const char* format, char type, int count, va_list candidates);
void	UnitTestAll(const char** formats, char type, int count, ...);

#endif
