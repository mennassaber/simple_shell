#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/* for command chaining */
#define COMMAND_NORMAL 0
#define COMMAND_OR 1
#define COMMAND_AND 2
#define COMMAND_CHAIN 3

/* for convert_number() */
#define CONVERT_TO_LOWERCASE 1
#define CONVERT_TO_UNSIGNED 2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0
OBOBOB
#define HISTORY_FILE ".simple_shell_history"
OBOBOB#define MAX_HISTORY_SIZE 4096

extern char **environment;
OBOBOB

OBOBOB/**
 * struct string_list - singly linked list
OBOBOB * @number: the number field
 * @string: a string
 * @next: points to the next node
 */
typedef struct string_list
{
    int number;
    char *string;
    struct string_list *next;
} list_t;

/**
 * struct function_arguments - contains pseudo-arguments to pass into a function,
 * allowing a uniform prototype for function pointer struct
 */
typedef struct function_arguments
{
    char *arguments;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int error_number;
    int linecount_flag;
    char *file_name;
    list_t *environment_list;
    list_t *history;
    list_t *alias;
    char **environment;
    int environment_changed;
    int status;

    char **command_buffer; /* pointer to command ; chain buffer, for memory management */
    int command_buffer_type; /* COMMAND_TYPE ||, &&, ; */
    int read_file_descriptor;
    int history_count;
} arguments_t;

#define ARGUMENTS_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
    0, 0, 0}

OBOBOB/**
 * struct built_in_commands - contains a built-in string and related function
OBOBOB */
typedef struct built_in_commands
OBOBOB{
OBOBOB    char *command;
    int (*function)(arguments_t *);
} built_in_table;


/* simple_shell.c */
int simple_shell(arguments_t *, char **);
int find_built_in_command(arguments_t *);
void find_command(arguments_t *);
void fork_command(arguments_t *);

/* path.c */
int is_command(arguments_t *, char *);
char *duplicate_characters(char *, int, int);
char *find_path(arguments_t *, char *, char *);

/* loophsh.c */
int loop_shell(char **);

/* error_string_functions.c */
void print_error_string(char *);
int print_error_character(char);
int print_to_file_descriptor(char c, int fd);
int print_string_to_file_descriptor(char *str, int fd);

/* string_functions.c */
OBOBOBint string_length(char *);
int string_compare(char *, char *);
char *starts_with_string(const char *, const char *);
OBOBOBchar *concatenate_strings(char *, char *);

/* string_functions2.c */
OBOBOBchar *copy_string(char *, char *);
char *duplicate_string(const char *);
void print_string(char *);
int print_character(char);

/* string_functions3.c */
char *copy_n_string(char *, char *, int);
char *concatenate_n_strings(char *, char *, int);
char *find_character(char *, char);

/* string_functions4.c */
char **split_string(char *, char *);
char **split_string_v2(char *, char);

/* memory_functions */
char *set_memory(char *, char, unsigned int);
void free_memory(char **);
void *reallocate_memory(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int free_block(void **);

/* more_functions.c */
int interactive_mode(arguments_t *);
int is_delimiter(char, char *);
int is_alpha(int);
int convert_to_integer(char *);

/* more_functions2.c */
int error_string_to_integer(char *);
void print_error(arguments_t *, char *);
int print_integer(int, int);
char *convert_number_to_string(long int, int, int);
void remove_comments_from_string(char *);

/* built_in_emulators.c */
OAOAOAint exit_simple_shell(arguments_t *);
int change_directory(arguments_t *);
int show_help(arguments_t *);

/* built_in_emulators2.c */
int show_history(arguments_t *);
int show_alias(arguments_t *);

/* getline.c module */
ssize_t get_input(arguments_t *);
int read_line(arguments_t *, char **, size_t *);
void handle_signal_interrupt(int);

/* arguments.c module */
void clear_arguments(arguments_t *);
void set_arguments(arguments_t *, char **);
OBOBOBvoid free_arguments(arguments_t *, int);

/* environment.c module */
char *get_environment_variable(arguments_t *, const char *);
int show_environment(arguments_t *);
int set_environment_variable(arguments_t *);
int unset_environment_variable(arguments_t *);
int populate_environment_list(arguments_t *);

/* environment2.c module */
char **get_modified_environment(arguments_t *);
int remove_environment_variable(arguments_t *, char *);
OBOBOBint add_environment_variable(arguments_t *, char *, char *);

OBOBOB/* file_io_functions.c */
OBOBOBchar *get_history_file_name(arguments_t *arguments);
int write_history_to_file(arguments_t *arguments);
OBOBOBint read_history_from_file(arguments_t *arguments);
int build_history_list_from_file(arguments_t *arguments, char *buffer, int linecount);
OBOBOBint renumber_history_list(arguments_t *arguments);

/* liststr.c module */
list_t *add_node_to_list(list_t **, const char *, int);
list_t *add_node_to_end_of_list(list_t **, const char *, int);
size_t print_string_list(const list_t *);
int delete_node_from_list_at_index(list_t **, unsigned int);
void free_string_list(list_t **);

/* liststr2.c module */
size_t length_of_list(const list_t *);
char **convert_list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *find_node_starts_with_string(list_t *, char *, char);
ssize_t get_index_of_node(list_t *, list_t *);

/* chain.c */
int is_command_chain(arguments_t *, char *, size_t *);
void check_command_chain(arguments_t *, char *, size_t *, size_t, size_t);
int replace_alias_with_string(arguments_t *);
int replace_variables(arguments_t *);
int replace_substring(char **, char *);

#endif

