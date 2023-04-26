#ifndef _SHELL_H
#define _SHELL_H


#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/**
* This variable is used to pass the environment
* variables to the execve function.
*/
extern char **environ;
/* Program name */
char *name;
/* History counter */
int hist;

/**
 * linked_struct  - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct linked_struct.
 */
typedef struct linked_struct
{
	char *dir;
	struct linked_struct *next;
} list_t;

/**
 * builtin_struct - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_struct
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * alias_struct - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_struct.
 */
typedef struct alias_struct
{
	char *name;
	char *value;
	struct alias_struct *next;
} alias_lst;

/* Aliases linked list */
alias_lst *aliases;

/* Main Helpers */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
int execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

/* Input Helpers */
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_argumentss(char *line, int *exe_ret);
int call_arguments(char **args, char **front, int *exe_ret);
int run_arguments(char **args, char **front, int *exe_ret);
int handle_arguments(int *exe_ret);
int check_arguments(char **args);
void free_args(char **args, char **front);
char **change_aliases(char **args);

/* String functions */
int custom_strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Builtins */
int (*find_builtin(char *command))(char **args, char **front);
int exit_shell(char **args, char **front);
int env_shell(char **args, char __attribute__((__unused__)) **front);
int set_env(char **args, char __attribute__((__unused__)) **front);
int unset_env(char **args, char __attribute__((__unused__)) **front);
int cd_shell(char **args, char __attribute__((__unused__)) **front);
int alias_shell(char **args, char __attribute__((__unused__)) **front);
int help_shell(char **args, char __attribute__((__unused__)) **front);

/* Builtin Helpers */
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/* Error Handling */
int make_error(char **args, int err);
char *error_env(char **args);
char *error_a(char **args);
char *error_b_exit(char **args);
char *error_c_cd(char **args);
char *error_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* Linkedlist Helpers */
alias_lst *add_alias_end(alias_lst **head, char *name, char *value);
void free_alias_list(alias_lst *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void helper_all(void);
void helper_alias(void);
void helper_cd(void);
void helper_exit(void);
void _helper(void);

/*Environment Helpers*/

void env_help(void);
void setenv_help(void);
void unsetenv_help(void);
void history_help(void);

int file_commands(char *file_path, int *exe_ret);
#endif
