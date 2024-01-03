#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

// Определение констант
enum
{
    CODE_LENGTH = 4,
    MAX_ATTEMPTS = 10,
    MAX_DIGIT = 8,
    MIN_DIGIT = 0,
    MAX_INPUT_LENGTH = CODE_LENGTH + 1,
    MY_INT_MIN = (-2147483648),
    MY_INT_MAX = 2147483647,
    INPUT_NOT_COMPLETE = -1
};

// Объявление функций
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
size_t my_strlen(const char *str);
char *my_strchr(const char *str, int c);
size_t my_atoi(const char *str);
int is_valid_input(const char *str);
int are_digits_unique(const char *str);
void print_error_message(const char *message);
void start_game(int argc, char **argv);
void game_process(const char *secretCode,const int attempts);
char *generate_secret_code(char *secretCode);
char *my_scanf();
void display_game_info(const char *secretCode, int attempts);
