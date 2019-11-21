PRINTFDIR	= ..
LIBFTDIR	= ../libft

PRINTF	= ${PRINTFDIR}/libftprintf.a
LIBFT	= ${LIBFTDIR}/libft.a

NAME	= test.out

test: ${NAME}
${NAME}: libft printf
	gcc *.c -o ${NAME} -Wall -Wextra -L ${PRINTFDIR} -lftprintf -L ${LIBFTDIR} -lft

printf: ${PRINTF}
${PRINTF}:
	make -C ${PRINTFDIR}

libft: ${LIBFT}
${LIBFT}:
	make -C ${LIBFTDIR}

autorun: fclean test
	norminette ${LIBFTDIR}/*.c  ${LIBFTDIR}/*.h
	norminette ${PRINTFDIR}/*.c ${PRINTFDIR}/*.h
	./${NAME}


all: libft test

clean:
	rm -f *.o
	rm -f *.gch

fclean: clean
	rm -f ${NAME}
	make fclean -C ${PRINTFDIR}
	make fclean -C ${LIBFTDIR}

re: fclean test

.PHONY: all clean fclean re autorun printf test
