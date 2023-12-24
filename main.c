#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Объявления функций
char *myStrchr(const char *str, int c);
size_t myStrlen(const char *str);
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *str1, const char *str2);
char *myRand(char *secret_code);
int myAtoi(const char *str);
void startGame(int argc, char **argv);

// Главная функция
int main(int argc, char **argv) {
  // Вызов главной функции игры
  startGame(argc, argv);

  return 0;
}

// Функция начала игры
void startGame(int argc, char **argv) {
  // Выделение памяти под секретный код
  char *secretCode = malloc(sizeof(char) * 5);
  int attempts = 10;

  // Обработка аргументов командной строки
  for (size_t i = 1; i < argc; i++) {
    if ((myStrcmp(argv[i], "-c")) == 0) {
      myStrcpy(secretCode, argv[++i]);
    } else if ((myStrcmp(argv[i], "-t")) == 0) {
      attempts = myAtoi(argv[++i]);
    }
  }

  // Если секретный код не был предоставлен, генерируем его
  if (!secretCode[0]) {
    myRand(secretCode);
  }

  // Вывод информации о игре
  printf("Секретный код: %s\n", secretCode);
  printf("Попыток: %d\n", attempts);

  // Освобождение памяти
  free(secretCode);
}

// Функция генерации случайного секретного кода
char *myRand(char *secret_code) {
  int i = 0;
  srand(time(0));
  char valid_numbers;

  while (i < 4) {
    valid_numbers = (rand() % 9) + 48;

    // Проверка, есть ли valid_numbers уже в secret_code
    int found = 0;
    for (int j = 0; j < i; ++j) {
      if (secret_code[j] == valid_numbers) {
        found = 1;
        break;
      }
    }

    // Если valid_numbers не найден в secret_code, добавляем его
    if (!found) {
      secret_code[i++] = valid_numbers;
    }
  }

  return secret_code;
}

// Функция поиска символа в строке
char *myStrchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == c) {
      return (char *)str;
    }
    str++;
  }
  return NULL;
}

// Функция определения длины строки
size_t myStrlen(const char *str) {
  size_t size = 0;
  for (size_t i = 0; str[i] != '\0'; i++) {
    size++;
  }
  return size;
}

// Функция сравнения строк
int myStrcmp(const char *str1, const char *str2) {
  size_t sizeStr1 = myStrlen(str1);
  size_t sizeStr2 = myStrlen(str2);

  if (sizeStr1 > sizeStr2) {
    return 1;
  } else if (sizeStr1 < sizeStr2) {
    return -1;
  }

  for (size_t i = 0; i < sizeStr1; i++) {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
  }

  return 0;
}

// Функция копирования строк
char *myStrcpy(char *str1, const char *str2) {
  size_t lenStr2 = myStrlen(str2);

  for (size_t i = 0; i <= lenStr2; i++) {
    str1[i] = str2[i];
  }
  return str1;
}

// Функция преобразования строки в число
int myAtoi(const char *str) {
  int i = 0;
  long int num = 0;
  int flag = 0;

  while (str[i] == ' ') {
    i++;
  }

  if (str[i] == '+' || str[i] == '-') {
    if (str[i] == '-') {
      flag = 1;
    }
    i++;
  }

  while (str[i] >= '0' && str[i] <= '9') {
    num = num * 10 + (str[i] - '0');

    if (!flag && num > INT_MAX) {
      return INT_MAX;
    } else if (flag && -num < INT_MIN) {
      return INT_MIN;
    }

    i++;
  }
  if (flag) {
    num = -num;
  }

  return num;
}
