# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: oswin <oswin@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/19 15:48:54 by oswin         #+#    #+#                  #
#    Updated: 2022/01/20 18:48:20 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
OBJ			= obj/main.o obj/import_map.o obj/setup_mlx.o obj/load_textures.o \
			obj/set_hooks.o obj/push_image.o obj/actions.o obj/load_file.o
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
				@${RM} ${OBJ} \
				$(info ************  so_long Clean)

libclean:
				@${MAKE} clean -C Libft --no-print-directory

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  so_long Removed) \
				&& ${MAKE} fclean -C Libft --no-print-directory \
				&& ${MAKE} clean -C mlx --no-print-directory

re:			fclean all

${NAME}:	${OBJ} Libft/libft.a mlx/libmlx.a
				@${CC} -o $@ $^ ${MLXFLAGS}\
				$(info ************  so_long Ready!)

Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory

mlx/libmlx.a:
				@${MAKE} -C mlx --no-print-directory


.PHONY: all clean fclean re libft
