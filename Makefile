# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: oswin <oswin@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/19 15:48:54 by oswin         #+#    #+#                  #
#    Updated: 2021/12/22 16:57:35 by oswin         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
OBJ			= obj/main.o
CC			= gcc
RM			= rm -f
HEADER		= -I headers/
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -Lmlx_linux -lmlx -lXext -lX11 -lm -lz

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) -c $(CFLAGS) $(HEADER) -o $@ $<

clean:
				@${RM} ${OBJ} \
				$(info ************  so_long Clean)

libclean:
				@${MAKE} clean -C Libft --no-print-directory

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  so_long Removed) \
				&& ${MAKE} fclean -C Libft --no-print-directory

re:			fclean all

${NAME}:	${OBJ} Libft/libft.a
				@${CC} -o $@ $^ ${MLXFLAGS}\
				$(info ************  so_long Ready!)

Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory


.PHONY: all clean fclean re libft
