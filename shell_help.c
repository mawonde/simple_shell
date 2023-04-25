#include "shell.h"

void helper_all(void);
void helper_alias(void);
void helper_cd(void);
void helper_exit(void);
void _helper(void);

/**
 * helper_all - Displays all possible builtin simple_shell commands.
 */
void helper_all(void)
{
	char *msg = "simple_shell\nThese  commands are   internally defined.\n";

	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "Type 'help' to see  list.\nType 'help name' to find ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
}

/**
 * helper_alias - Displays information on the simple_shell
 * builtin command 'alias'.
 */
void helper_alias(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
}

/**
 * helper_cd - Displays information on the simple_shell builtin command 'cd'.
 */
void helper_cd(void)
{
	char *msg = "cd: cd [DIRECTORY]\n\tChanges the current dir ";

	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "command  interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " given, the command  interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "\tThe environ variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "after a change of dir.\n";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
}

/**
 * helper_exit - Displays information on the simple_shell
 * builtin command 'exit'.
 */
void helper_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "STATUS argument is  integer used to exit the shell.";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " If no argument is given, the command  interpreted as";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
}

/**
 * _helper - Displays information on the simple_shell builtin command 'help'.
 */
void _helper(void)
{
	char *msg = "help: help\n\tSee all possible simple_shell builtin commands.\n";

	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "\n      help [BUILTIN NAME]\n\tSee specific information on  ";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, custom_strlen(msg));
}
