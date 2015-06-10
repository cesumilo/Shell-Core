##
## Makefile for Module package in /home/robin_f/Programming/Epitech/S2/C/PSU_2014_42sh/package
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Tue Jun  9 19:50:33 2015 Guillaume ROBIN
## Last update Wed Jun 10 14:15:25 2015 Guillaume ROBIN
##

CC	= clang

RM	= rm -f

# Your lib name.
NAME	= libname.so

FLAGS	+= -shared -Wl,-soname,$(NAME)

CFLAGS	+= -Werror -Wall -Wextra

CFLAGS	+= -I ./

SRCS	+= env.c \
	   env_convert.c \
	   env_drawing.c \
	   env_ext.c \
	   module_pack_1.c \
	   module_pack_2.c \
	   module_pack_3.c \
	   module_pack_4.c

SRCS	+= tools/error.c \
	   tools/my_getnbr.c \
	   tools/put_natural.c \
	   tools/str_cat.c \
	   tools/str_contains.c \
	   tools/string.c \
	   tools/get_next_line.c \
	   tools/my_puterr.c \
	   tools/put_str_fd.c \
	   tools/str_cmp.c \
	   tools/str_dup.c

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
