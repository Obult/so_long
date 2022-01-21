# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: oswin <oswin@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/19 15:48:54 by oswin         #+#    #+#                  #
#    Updated: 2022/01/21 15:44:08 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
OBJ			= main.o import_map.o setup_mlx.o load_textures.o \
			set_hooks.o push_image.o actions.o load_file.o
OBJS		= $(addprefix obj/, ${OBJ})
CC			= gcc
RM			= rm -f
HEADER		= -I headers/
CFLAGS		= -Wall -Werror -Wextra -g
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) -c $(CFLAGS) $(HEADER) -o $@ $<

clean:
				@${RM} ${OBJS} \
				$(info ************  so_long Clean)

libclean:
				@${MAKE} clean -C Libft --no-print-directory

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  so_long Removed) \
				&& ${MAKE} fclean -C Libft --no-print-directory \
				&& ${MAKE} clean -C mlx --no-print-directory

re:			fclean all

${NAME}:	${OBJS} Libft/libft.a mlx/libmlx.a
				@${CC} -o $@ $^ ${MLXFLAGS}\
				$(info ************  so_long Ready!)

Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory

mlx/libmlx.a:
				@${MAKE} -C mlx --no-print-directory


.PHONY: all clean fclean re libft
