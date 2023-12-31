#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Определение констант
enum {
  CODE_LENGTH = 4,
  DEFAULT_ATTEMPTS = 10,
  MAX_DIGIT = 8,
  MIN_DIGIT = 0,
  MAX_INPUT_LENGTH = CODE_LENGTH + 1,
  MY_INT_MIN = (-2147483648),
  MY_INT_MAX = 2147483647,
  INPUT_NOT_COMPLETE = -1
};

// Объявление функций
void start_game(int argc, char **argv);
void game_process(char *, int);
char *generate_secret_code(char *);
char *my_scanf();
void display_game_info(const char *, int);
int is_valid_input(const char *);
int are_digits_unique(const char *);
size_t my_atoi(const char *);
int my_strcmp(const char *, const char *);
char *my_strcpy(char *, const char *);
size_t my_strlen(const char *);
int my_strchr(const char *, int);
char *my_strdup(const char *);
void print_error_message(const char *);