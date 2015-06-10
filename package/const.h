/*
** const.h for 42sh in /home/robin_f/Programming/S2/C/PSU_2014_42sh/include/core
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri May 22 22:37:30 2015 Guillaume ROBIN
** Last update Tue Jun  9 19:25:33 2015 Guillaume ROBIN
*/

#ifndef CONST_H_
# define CONST_H_

# define OPT_TERMCAPS_1	(char *)"--termcaps"
# define OPT_TERMCAPS_2	(char *)"-t"
# define CONFIG_PATH	(char *)".42shrc"
# define BASE_PROMPT	(char *)"$> "
# define MODULES_PATH	(char *)"modules/"

# define NO_ERR		(int)1
# define NO_ERR_0	(int)0
# define ERROR		(int)-1

# define TRUE		1
# define FALSE		0
# define EQUAL		(int)0

# define STDIN		(int)0
# define STDOUT		(int)1
# define STDERR		(int)2
# define PIPEREAD	(int)0
# define PIPEWRITE	(int)1

# define NB_TOK_FINAL	(int)8
# define TOK_SOCHV	(char *)"<"
# define TOK_SCCHV	(char *)">"
# define TOK_DCCHV	(char *)">>"
# define TOK_DOCHV	(char *)"<<"
# define TOK_SEMICOLON	(char *)";"
# define TOK_PIPE	(char *)"|"
# define TOK_AND	(char *)"&&"
# define TOK_OR		(char *)"||"

# define ERR_ENV	(char *)"Error: cannot set the environment\n"
# define ERR_EROW	(char *)"Error: cannot enable the row mode\n"
# define ERR_DROW	(char *)"Error: cannot disable the row mode\n"
# define ERR_MALLOC	(char *)"Error: cannot perform malloc()\n"
# define ERR_GTERMC	(char *)"Error: cannot get the term attributs\n"
# define ERR_GTERM	(char *)"Error: cannot get the terminal\n"
# define ERR_CHCAP	(char *)"Error: cannot get the capacity 'ch'\n"
# define ERR_LECAP	(char *)"Error: cannot get the capacity 'le'\n"
# define ERR_DOCAP	(char *)"Error: cannot get the capacity 'do'\n"
# define ERR_UPCAP	(char *)"Error: cannot get the capacity 'up'\n"
# define ERR_NDCAP	(char *)"Error: cannot get the capacity 'nd'\n"
# define ERR_TGOTO	(char *)"Error: cannot perform tgoto()\n"
# define ERR_TPUTS	(char *)"Error: cannot perform tputs()\n"
# define ERR_TERMCAP	(char *)"Error: cannot set the termcaps\n"
# define ERR_MVCURSOR	(char *)"Error: cannot move the cursor\n"
# define ERR_MODULE	(char *)"Error: something went wrong in a module\n"
# define ERR_CMD	(char *)"Error: command not found\n"
# define ERR_FORK	(char *)"Error: cannot perform fork()\n"
# define ERR_WAITPID	(char *)"Error: cannot perform wait_pid()\n"
# define ERR_EXECVE	(char *)"Error: cannot perform execve()\n"
# define ERR_PIPE	(char *)"Error: cannot perform pipe()\n"
# define ERR_SIGSEGV	(char *)"Error: Segmentation fault (core dumped)\n"
# define ERR_SIGNAL	(char *)"Error: cannot perform signal()\n"
# define ERR_SIGHUP	(char *)"Error: Death of controlling process\n"
# define ERR_SIGINT	(char *)"Keyboard Interrupt\n"
# define ERR_SIGQUIT	(char *)"Error: Quit from keyboard\n"
# define ERR_SIGILL	(char *)"Error: Illegal instruction\n"
# define ERR_SIGFPE	(char *)"Error: Floting point exception\n"
# define ERR_SIGKILL	(char *)"Error: Kill signal\n"
# define ERR_SIGPIPE	(char *)"Error: Broken pipe\n"
# define ERR_SIGTERM	(char *)"Error: Termination signal\n"
# define ERR_SIGCONT	(char *)"Error: Continue if stopped\n"
# define ERR_SIGSTOP	(char *)"Error: Stop process\n"
# define ERR_SIGTSTP	(char *)"Error: Stop typed at terminal\n"
# define ERR_DUP2	(char *)"Error: cannot perform dup2()\n"
# define ERR_EXIT	(char *)"Error: exit '1764' is reserved to the core\n"
# define ERR_UNSETENV	(char *)"Error: unsetenv: too few arguments\n"
# define ERR_ALIAS_1	(char *)"Error: alias: too few arguments\n"
# define ERR_ALIAS_2	(char *)"Error: alias: Invalid syntax\n"
# define ERR_CLOSE	(char *)"Error: cannot perform close()\n"
# define ERR_STR	(char *)"Error: "
# define ERR_END_OPEN	(char *)": cannot open the file\n"
# define ERR_42SH	(char *)"42sh: "
# define ERR_END_CMD	(char *)": command not found\n"
# define ERR_END_CD	(char *)": No such file or directory\n"
# define ERR_BG_CD	(char *)"42sh: cd: "
# define ERR_CHDIR	(char *)"Error: cannot perform chdir()\n"
# define ERR_PWD	(char *)"Error: cannot get the pwd()\n"
# define ERR_SETENV	(char *)"Error: setenv: invalid synthax\n"
# define ERR_GETENV	(char *)"Error: nothing found in the environment\n"
# define ERR_OPEN	(char *)"Error: cannot perform open()\n"
# define ERR_GLOB	(char *)"Error: cannot perform glob()\n"
# define ERR_TCSETPGRP	(char *)"Error: cannot perform tcsetpgrp()\n"
# define ERR_KILL	(char *)"Error: cannot perform kill()\n"
# define ERR_SETPGID	(char *)"Error: cannot perform setpgid()\n"
# define ERR_CLOSE_DIR	(char *)"Error: cannot perform closedir()\n"
# define ERR_OPENDIR	(char *)"Error: cannot perform opendir()\n"
# define ERR_GET_MODULE	(char *)"Error: something went wrong in get_modules()\n"

# define WAR_NOTERM	(char *)"Warning: cannot use the termcaps\n"
# define WAR_NO_ENV	(char *)"Warning: no environment defined\n"
# define WAR_SETSID	(char *)"Warning: the shell can be kill\n"

# define INFO_JOBS	(char *)"\nInfo: +[%d] Stopped %s\n"
# define INFO_JOBS_2	(char *)"+[%d] Stopped %s\n"

# define RESET_CURSOR	(char *)"ch"
# define MOVE_CURSOR_LF	(char *)"le"
# define MOVE_CURSOR_DW	(char *)"do"
# define MOVE_CURSOR_UP	(char *)"up"
# define MOVE_CURSOR_RG	(char *)"nd"
# define BUF_CAPS_SIZE	(int)4

# define BACKSPACE_STR	(char *)"\n"
# define SPACE_STR	(char *)" "
# define SLASH_STR	(char *)"/"
# define STR_CD		(char *)"cd"
# define STR_PWD	(char *)"PWD"
# define STR_ENVPWD	(char *)"PWD="
# define STR_HOME	(char *)"HOME="
# define STR_PATH	(char *)"PATH="
# define STR_OLDPWD	(char *)"OLDPWD="
# define STR_NOLDPWD	(char *)"OLDPWD"
# define STR_USER	(char *)"USER="
# define STR_TERM	(char *)"TERM="
# define STR_DASH	(char *)"-"
# define STR_EQUAL	(char *)"="
# define STR_POINT	(char *)"."
# define STR_DPOINT	(char *)".."
# define STR_STAR	(char *)"*"
# define STR_HISTORY	(char *)"history"
# define COLOR_LBLUE	(char *)"\033[0;36m"
# define COLOR_END	(char *)"\033[0m"
# define COLOR_PWD_1	(char *)" \033[0;34m{\033[0m\033[0;33m"
# define COLOR_PWD_2	(char *)"\033[0m\033[0;34m}->\033[0m "
# define CLEAR_FCT	(char *)"\033[H\033[2J"

# define CHAR_SPACE	(char)' '
# define CHAR_TAB	(char)'\t'
# define CHAR_SHARP	(char)'#'
# define CHAR_SLASH	(char)'/'
# define CHAR_DQUOTE	(char)'"'
# define CHAR_POINT	(char)'.'

# define DISPLAY_BEG	(char *)" "
# define DISPLAY_END	(char *)"  "

# define END_STR	(char)'\0'
# define VAR_STR	(char)'$'
# define TILDE		(char)'~'
# define ENV_VARIABLE_1	(char *)"abcdefghijklmnopqrstuvwxyz"
# define ENV_VARIABLE_2	(char *)"ABCDEFGHIJKLMNOPPQRSTUVWXYZ"
# define ENV_VARIABLE_3	(char *)"0123456789_"

#endif /* !CONST_H_ */
