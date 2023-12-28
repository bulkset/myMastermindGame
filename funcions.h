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
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *dest, const char *src);
size_t myStrlen(const char *str);
char *myStrchr(const char *str, int c);
size_t myAtoi(const char *str);
int isValidInput(const char *str);
int areDigitsUnique(const char *str);
void printErrorMessage(const char *message);
void startGame(int argc, char **argv);
void gameProcess(const char *secretCode);
char *generateSecretCode(char *secretCode);
char *myScanf();
void displayGameInfo(const char *secretCode, int attempts);
