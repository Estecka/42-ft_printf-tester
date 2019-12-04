PRINTF_H_DIR	= ../
PRINTF_DIR		= ../
LIBPRINTF		= ${PRINTF_DIR}/libftprintf.a

NAME	= test.out

test: ${NAME}
${NAME}: printf
	gcc *.c -o ${NAME} -Wall -Wextra -L ${PRINTF_DIR} -lftprintf -I ${PRINTF_H_DIR}

printf: ${LIBPRINTF}
${LIBPRINTF}:
	make -C ${PRINTF_DIR}

autorun: fclean test
	norminette `find ../* -name "*.[ch]"`
	./${NAME}


all: printf test

clean:
	make clean -C ${PRINTF_DIR}
	rm -f *.o
	rm -f *.gch

fclean: clean
	rm -f ${NAME}
	make fclean -C ${PRINTF_DIR}

re: fclean test

.PHONY: all clean fclean re autorun printf test
