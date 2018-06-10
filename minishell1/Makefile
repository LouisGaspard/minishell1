##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

NAME	= mysh

CC	= gcc -g

RM	= rm -f

SRCS	= ./src/main.c			\
	  ./src/copy_env.c		\
	  ./src/my_exec_cmd.c		\
	  ./src/my_unsetenv.c		\
	  ./src/pwd_change.c		\
	  ./src/create_pwd_line.c	\
	  ./src/my_setenv.c		\
	  ./src/is_dir.c		\
	  ./src/my_add_env.c		\
	  ./src/my_realloc_env.c	\
	  ./src/my_cd.c			\
	  ./src/exec_prog.c		\
	  ./src/my_check_exit.c		\
	  ./src/check_cmd.c		\
	  ./src/history.c		\
	  ./src/get_in_env.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

LIB	= -L ./lib/ -lmy -lgnl

all: $(NAME)

$(NAME): $(OBJS)
	 make -C ./lib/my/
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	make clean -C ./lib/my/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
