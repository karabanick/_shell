#ifndef MAIN_H
#define MAIN_H

/**=============== STANDARD_LIBRARY_HEADER_FILES ==================**/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

/**=============== CONVERSIONS =====================**/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**=============== BUFFERS ====================**/
#define RDBUFF_SIZE  1024
#define WRBUFF_SIZE  1024
#define BUFF_FLUSH  -1

/**=============== COMMAND CHAINING ============**/
#define CMD_NORM      0
#define CMD_OR        1
#define CMD_AND       2
#define CMD_CHAIN     3

/**================ GETLINE () ================**/
#define USE_GETLINE  0
#define USE_STRTOK  0

#define SHELL_HIST   ".simple_shell_history"
#define HIST_MAX     4096

/*===========ENVIRONMENT VARIABLE ============**/
extern char **environment;

/**============== LIST STRUCT ===============**/
/**
 * struct list_str - singly linked list
 * @num: number field
 * @str: string
 * @next: next node pointer
 */
typedef struct listr_str
{
	int numb;
	char *string;
	struct list_str *next;
} list_t;

/**=============== STATUS STRUCT =================**/
/**
 * struct status_info - struct with pseudo instructions for functions
 * @arg: arguments inputs
 * @argv: array of input arguments
 * @argc: total argument count
 * @path: command path
 * @line_count: error count
 * @err_numb: error code
 * @linecount_flag: flag line count
 * @file_name: program file name
 * @env: local copy of environment
 * @environment: global environment
 * @history: history info
 * @alias: alias command
 * @env_changed: detect change in environment
 * @cmd_status: status of last executed command
 * @cmd_buff: command buffer
 * @cmd_buff_type: command buffer type
 * @rdfd: fd to read from
 * @hist_count: history file line count
 */
typedef struct status_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_numb;
	int linecount_flag;
	char *file_name;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environment;
	int env_changed;
	int cmd_status;
	char **cmd_buff;
	int **cmd_buff_type;
	int rdfd;
	int hist_count;
} status_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**=========== BUILT_IN STRUCT ==============**/
/**
 * struct built_in - built-in struct
 * @type: biltin command flag
 * @func: function
 */
typedef struct built_in
{
	char *type;
	int (*func)(status_t *);
} built_t;

/**=============== MODULE1.c =================**/
int hsh(status_t *, char **);
int find_builtin(status_t *);
void find_cmd(status_t *);
void fork_cmd(status_t *);

/**=============== MODULE2.c =================**/
int get_cmd(status_t *, char *);
char *dup_chars(char *, int, int);
char *get_path(status_t *, char *, char *);

/**=============== MODULE3.c ==================**/
int loop_hsh(char **);

/**=============== string_func_module.c ==============**/
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/**=============== string_handler.c ===============**/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/**============== string_handlers2.c ===============**/
int _strlen(char *);
int _strcmp(char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/**=============== string_handlers3.c ================**/
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/**=============== memory_aloc.c =====================**/
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int pfree(void **);

/**=============== advanced_strings.c =================**/
char **strtow(char *, char *);
char **strtow2(char *, char);

/**=============== helper_functions.c =================**/
int interactive(status_t *);
int _delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/**============== error_functions.c =====================**/
void print_error(status_t *, char *);
int _erratoi(char *);
int print_d(int, int);
char *convert_num(long int, int, int);
void rm_comment(char *);

/**============== emulators_module1.c ================**/
int my_hist(status_t *);
int my_alias(status_t);

/**============== emulators_module2.c ================**/
int my_cd(status_t *);
int my_exit(status_t *);
int my_help(status_t *);

/**============== get_input.c functions ===============**/
ssize_t get_input(status_t *);
int get_line(status_t *, char **, size_t *);
void _inthandler(int);

/**============== info_handler.c ================**/
void _setinfo(status_t *, char **);
void _clearinfo(status_t *);
void _setinfo(status_t *, char **);
void _clearinfo(status_t *);
void _freeinfo(status_t *, int);

/**============ environment.c ============**/
char *get_environ(status_t *, const char *);
int my_environ(status_t *);
int my_setenv(status_t *);
int my_unsetenv(status_t *);
int env_list(status_t *);

/**=============== environent2.c functions ==============**/
char **_getenv(status_t *);
int set_env(status_t *, char *, char *);
int unset_env(status_t *, char *);

/**============== file_functions.c ================**/
char *get_histfile(status_t *status);
int wr_hist(status_t *status);
int rd_hist(status_t *status);
int hist_build(status_t *status, char *buff, int linecount);
int renum_hist(status_t *status);

/**=============== list_struct.c functions ==============**/
list_t *add_node(list_t **, const char *, int);
list_t *node_end(list_t **, const char *, int);
size_t print_list(const list_t *);
int del_node(list_t **, unsigned int);
void free_list(list_t **);

/** ============== list_struct2.c ================**/
size_t list_length(const list_t *);
char **list_strng(list_t *);
size_t print_liststr(const list_t *);
list_t *node_start(list_t *, char *, char);
ssize_t node_index(list_t *, list_t *);

/** ============== chain_handlers.c functions ================**/
int is_chain(status_t *, char *, size_t *);
int replace_alias(status_t *);
int check_chain(status_t *, char *, size_t *, size_t, size_t);
int replace_str(char **, char *);
int replace_var(status_t *);

#endif
