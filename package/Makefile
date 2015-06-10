##
## Makefile for Module package in /home/robin_f/Programming/Epitech/S2/C/PSU_2014_42sh/package
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Tue Jun  9 19:50:33 2015 Guillaume ROBIN
## Last update Wed Jun 10 15:24:58 2015 Guillaume ROBIN
##

CC	= gcc

RM	= rm -f

# Your lib name.
NAME	= libname.so

FLAGS	+= -shared -Wl,-soname,$(NAME)

CFLAGS	+= -Werror -Wall -Wextra

CFLAGS	+= -I ./core_src/

SRCS	+= core_src/env.c \
	   core_src/env_convert.c \
	   core_src/env_drawing.c \
	   core_src/env_ext.c \
	   core_src/module_pack_1.c \
	   core_src/module_pack_2.c \
	   core_src/module_pack_3.c \
	   core_src/module_pack_4.c

SRCS	+= core_src/tools/error.c \
	   core_src/tools/my_getnbr.c \
	   core_src/tools/put_natural.c \
	   core_src/tools/str_cat.c \
	   core_src/tools/str_contains.c \
	   core_src/tools/string.c \
	   core_src/tools/get_next_line.c \
	   core_src/tools/my_puterr.c \
	   core_src/tools/put_str_fd.c \
	   core_src/tools/str_cmp.c \
	   core_src/tools/str_dup.c

# Your files.
SRCS	+=

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
