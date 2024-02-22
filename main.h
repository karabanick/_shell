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
extern char **environment

/**============== LIST STRUCT ===============**/
/**
 * struct list_str - singly linked list
 * @num: number field
 * @str: string
 * @next: next node pointer
 */
typedef struct listr_str
{
	int num;
	char *str;
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
} status_t

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
