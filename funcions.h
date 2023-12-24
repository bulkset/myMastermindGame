#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

// Объявления функций
void startGame(int argc, char **argv);
void gameProcess(int attempts, char *secret_code);
char *myRand(char *secret_code);
char *myStrchr(const char *str, int c);
size_t myStrlen(const char *str);
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *str1, const char *str2);
int myAtoi(const char *str);
char *myScanf();
