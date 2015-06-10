##
## Makefile for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh
## 
## Made by Guillaume ROBIN
## Login   <robin_f@epitech.eu>
## 
## Started on  Sun May 24 22:28:09 2015 Guillaume ROBIN
## Last update Wed Jun 10 14:18:45 2015 Guillaume ROBIN
##

CC	= gcc

RM	= rm -f

NAME	= 42sh

CFLAGS	+= -Wall -Wextra -Werror

CFLAGS	+= -I ./include/ -I ./include/core/ -I ./include/module/ -I ./include/tools/

CFLAGS	+= -I ./include/module/module_alias/ -I ./include/module/manager -I ./include/module/present -I ./include/module/module_variable/ -I ./include/module/module_calc/

CFLAGS	+= -I ./include/module/module_cd/

LDFLAGS	+= -lncurses -ldl

SRCS	+= src/core/core.c \
	   src/core/core_running.c \
	   src/core/prompt.c \
	   src/core/env.c \
	   src/core/env_ext.c \
	   src/core/env_convert.c \
	   src/core/env_drawing.c \
	   src/core/get_env.c \
	   src/core/buffer.c \
	   src/core/init_termcaps.c \
	   src/core/row_mode.c \
	   src/core/move_cursor.c \
	   src/core/key_hook.c \
	   src/core/list.c \
	   src/core/pwd.c \
	   src/core/config.c

SRCS	+= src/core/hook/hook_backspace.c \
	   src/core/hook/hook_enter.c \
	   src/core/hook/hook_tabulation.c \
	   src/core/hook/hook_catch.c \
	   src/core/hook/hook_control_d.c \
	   src/core/hook/hook_control_l.c

SRCS	+= src/core/parser/parser.c \
	   src/core/parser/parser_env.c \
	   src/core/parser/parser_env_ext.c \
	   src/core/parser/count_word.c \
	   src/core/parser/parser_cut.c \
	   src/core/parser/create_subtab.c \
	   src/core/parser/btree.c \
	   src/core/parser/btree_build.c \
	   src/core/parser/btree_insert_cmd.c \
	   src/core/parser/insert_token_dir.c

SRCS	+= src/core/module/module_call.c \
	   src/core/module/module_call_ext.c \
	   src/core/module/module_jobs.c \
	   src/core/module/module_signal.c \
	   src/core/module/module_pipe.c \
	   src/core/module/module_semicolon.c \
	   src/core/module/module_chevron_management.c \
	   src/core/module/module_chevron_management_ext.c \
	   src/core/module/module_simple_close_chevron.c \
	   src/core/module/module_double_close_chevron.c \
	   src/core/module/module_simple_open_chevron.c \
	   src/core/module/module_double_open_chevron.c \
	   src/core/module/module_and_operation.c \
	   src/core/module/module_or_operation.c

SRCS	+= src/module/module_call.c

SRCS	+= src/tools/string.c \
	   src/tools/error.c \
	   src/tools/str_dup.c \
	   src/tools/my_puterr.c \
	   src/tools/str_cmp.c \
	   src/tools/str_cat.c \
	   src/tools/my_getnbr.c \
	   src/tools/get_next_line.c \
	   src/tools/put_str_fd.c \
	   src/tools/put_natural.c \
	   src/tools/str_contains.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
