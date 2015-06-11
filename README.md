# Shell-Core
This project is a part of another project called 42sh. It was made during my first year at Epitech. The goal was to develop a shell on Linux.

## What was our organisation ?
We thought about a modular architecture. The interest was to code a "Core" in order to manage several modules. Each person will be able to code his own module and make everything.

## How we made a module ?
A module is built into a shared library. Then, the core loads all the modules which are in the "modules" directory.

## What can you do with this "Shell Core" ?
First, you can build your own shell like "bash" with your modules. At the beginning, it provides nothing except the "manager" and the "exit" command. Even if there are no modules in the directory (or no directory), the shell still start. You can quit with the shortcut "CTRL+D".

## What the Shell Core provides ?

Here is a list of the shell features:

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
As you can see in the code above, we have several functions to make the module available with the core.

### Functions:

**Tools functions : (not mandatory)**

1. *str_cmp* : compare two strings.
2. *my_puterr* : print a string on the error output.

**Core functions : (make module available with pipes and redirections)**

1. *pipe_management* : manage pipes in the son process.
2. *pipe_management_parent* : manage pipes in the parent process.
3. *manage_return* : manage the returned value by the son/parent process.
4. *redirection_management* : manage redirections in the son process.
5. *redirection_management_close* : manage redirections in the parent process.
6. *signal_handler* : manage signals that are given by the son process.
7. *signal_handler_parent* : manage signals in the parent process. For example if the son sends a *SEGSEGV* signal.
8. *check_signal* : print a message on the *STDOUT* if there is an error.

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

This is the packet which will travel between the different modules. There are a lot of informations in it.

> **id** - is the ID of the module.

> **err** - is the variable that tell to the core "Ok! There is no problem!" or "Wait.. Something's wrong."

> **ac** - is like in the "main" function (called "argc"). It gives you the size of the array called "av".

> **av** - is like in the "main" function (called "argv"). It provides the user's input. In fact the command that the user has written.

> **env** - is an array which contains all the shell environment.

> **env_list** - is a pointer on a list. It allows you to modify the environment with the given functions (see package).

> **is_alias** - is a bit special. Indeed, if "is\_alias" s value is equal to TRUE (see const.h), you will "free" the **av** array with the function called "cut\_tab\_free" (see package).

> **data** - is a variable that contains by default an array of **t_module** given by the core.

> **jobs** - contains all the process that have been paused by the user (see package). It allows you to create a module in order to manage process.

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