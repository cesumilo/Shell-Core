# Shell-Core
This project is a part of another project called "42sh". It was made during my first year at Epitech. The goal was to develop a shell on Linux. My group was composed of Caroline Perez, Lucien Perouze, Quentin Rochefort and Adrien Van Noort.

## What was our organisation ?
We thought about a modular architecture. The interest was to code a "Core" in order to manage several modules. Each person will be able to code his own module.

## How we made a module ?
A module is built into a shared library. Then, the core loads all the modules which are in the "modules" directory.

## What can you do with this "Shell Core" ?
First, you can build your own shell like "bash" with your modules. At the beginning, it provides nothing except the "manager" and the "exit" command. Even if there are no modules in the directory (or no directory), the shell still start. You can quit with the shortcut "CTRL+D".

## What the Shell Core provides ?

Here is a list of the features:

- Tokens:
  * ;
  * |
  * >
  * <
  * <<
  * >>
  * &&
  * ||
- Multiple pipes & redirections.

```bash
cat << log >> log2
```

- Reverse redirections.

```bash
<< log cat >> log2
```

- Separator:
  * " [...] "

## How to make your module ? (Code):

```c
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "package.h"
#include "tools.h"
#include "const.h"

void	module_name(char **name)
{
  *name = "module name";
}

int	module_start(t_mod_pack *pack)
{
  pid_t	pid;
  int	status;

  if (pack->ac >= 1 && !pack->av && str_cmp(pack->av[0], "cmd") == EQUAL)
    {
      pack->err = ERR_FOUND;
      if ((pid = fork()) == -1 && !my_puterr(ERR_FORK))
	pack->err = ERR_NOT_FOUND;
      if (pid == 0)
	{
	  signal_handler();
	  pipe_management(pack);
	  redirection_management(pack);
	  /* ACTIONS */
	}
      else if (pid > 0)
	{
	  signal_handler_parent(pid);
	  if (waitpid(pid, &status, 0) == ERROR)
	    pack->err = my_puterr(ERR_WAITPID);
	  pipe_management_parent(pack);
	  redirection_management_close(pack);
	  if (check_signal(pid, status, packet) == ERROR)
	     packet->err = ERROR;
	}
    }
  else if (pack->err != ERR_FREE)
    pack->err = ERR_NOT_FOUND;
  return (manage_return(pack));
}

```

## Explanations:
As you can see in the code above, we have several functions to be compatible with the core.

### Functions:

**Tools functions : (not mandatory)**

1. *str_cmp* : compares two strings.
2. *my_puterr* : prints a string on the error output.

**Core functions : (make module available with pipes and redirections)**

1. *pipe_management* : manages pipes in the son process.
2. *pipe_management_parent* : manages pipes in the parent process.
3. *manage_return* : manages the returned value by the son/parent process.
4. *redirection_management* : manages redirections in the son process.
5. *redirection_management_close* : manages redirections in the parent process.
6. *signal_handler* : manages signals that are given by the son process.
7. *signal_handler_parent* : manages signals in the parent process. For example, the son sends a *SEGSEGV* signal.
8. *check_signal* : prints a message on the *STDERR* if there is an error.

**System functions : (mandatory for pipes and redirections)**

1. *fork* : duplicate the running process (see man fork).
2. *waitpid* : placed in the parent process, it waits the son process (see man waitpid).

**IMPORTANT** : The order of functions calls is done on purpose ! Please follow this order for the smooth running of things.

### Data structures:

The first data structure that you will learn about is **t\_mod\_pack**.

```c
typedef struct		s_module_packet
{
  char			id;
  int			err;
  int			ac;
  char			**av;
  char			**env;
  t_env			**env_list;
  char			is_alias;
  void			*data;
  t_jobs		**jobs;
}			t_mod_pack;

```

This is the packet that will travel between the different modules. There are a lot of information in it.

> **id** - is the ID of the module.

> **err** - is a variable that tell to the core "Ok! There is no problem!" or "Wait.. Something's wrong."

> **ac** - is like in the "main" function (called "argc"). It gives you the size of the array called "av".

> **av** - is like in the "main" function (called "argv"). It provides the user's input. In fact the command that the user has written.

> **env** - is an array which contains all the shell environment.

> **env_list** - is a pointer on a list. It allows you to modify the environment with the given functions (see env.h).

> **is_alias** - is a bit special. Indeed, if "is\_alias" s value is equal to TRUE (see const.h), you will "free" the **av** array with the function called "cut\_tab\_free" (see package.h).

> **data** - is a variable that contains by default an array of **t_module** given by the core.

> **jobs** - contains all the process that have been paused by the user (see package.h). It allows you to create a module in order to manage process.

There are many other variables in this structures to manage the stream between the core and the modules. However, I will not describe all the variables. You are invited to see the source code and discover them by yourself. For informations, a lot of these variables are used to manage pipes and redirections.

## We need to go deeper !

----
**How to know if it's my module that the user is calling ?**
----

```c
if (pack->ac >= 1 && !pack->av && str_cmp(pack->av[0], "cmd") == EQUAL)
```

   This is very simple to understand. First we need to verify if the "av" array has arguments. If it doesn't have any arguments you must tell to the core "It's not my job!".

   If you have the function **manage\_return** in your module you must use this line:
```c
pack->err = ERR_NOT_FOUND;
```

  If you don't have **manage_return**, you can do this:
```c
return ((pack->err = ERR_NOT_FOUND));
```

  Then, if there are arguments in the array, you want to check if the first argument is your command line. In this case, we use our own function *str\_cmp* (see tools.h) but you can do it by an other way.

  **IMPORTANT** : You must tell something to the core by the **err** variable ! In all cases !

  If it contains your command line you must say "Ok! It's my job !" :
```c
pack->err = ERR_FOUND;
```

----
**How to tell something to the core ?**
----

> pack->err = ??? ;

   There are 3 defines :

   1. **ERR\_FOUND** : tells that your module manage the command line.
   2. **ERR\_NOT\_FOUND** : tells that it's not your job.
   3. **ERROR** : tells "It's my job but there is an error during the execution !" (see const.h)

----
**Can the core tell something to you ?**
----

Yes ! In fact, when the user quit the shell the core will tell you "Ok! It's the end for now! Please free all your static variables (if there is)".

So. When you receive the message **ERR_FREE** by the **err** variable. You must free all your static variables which need to be freed.

```c
if (pack->err == ERR_FREE)
{
    free(...);
    ...
    free(...);
}
```

**IMPORTANT** : You don't have to modify the **err** variable during this process! This is why in the example there is :

```c
else if (pack->err != ERR_FREE)
    pack->err = ERR_NOT_FOUND;
```

----
**Can you change the name of the function called "*module_start*" or "*module_name*" ?**
----

Actually, you can not change those names because the "Core" need to find the symbol of each function in order to run your module and get its name. This is the minimum in order to run a module.

----
**What do includes ?**
----

Let's explain a bit :

```c
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
```
* They are needed by the system calls.

```c
#include "package.h"
```
* This is the minium (with the system calls includes) to create a module.

```c
#include "const.h"
```
* It provides to you several defines (see const.h).

----
**How to compile your module ?**
----

It's very simple ! Just code your module and place the source code and the headers in the "package" directory. Then, fill the "Makefile".

```make

[...]

# Your lib name.
NAME	= libname.so

[...]

#Your headers directory.
CFLAGS	+=

[...]

# Your files.
SRCS	+=

[...]
```

Now you just use :

* **make** : compile your module.
* **make re** : re-compile your module.
* **make clean** : clean the object files.
* **make fclean** : clean the objects files and the executable.

## Conclusion

It was a beautiful project ! We thought a lot about the architecture and that allows us to manage our time pretty well. For now, it's your job to make your own shell ! Ask questions or report a bug at the address: *guillaume1.robin@epitech.eu*

# Licence
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Shell-Core</span> by <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">Robin Guillaume</span> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.<br />Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/cesumilo/Shell-Core" rel="dct:source">https://github.com/cesumilo/Shell-Core</a>.
