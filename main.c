#include <stdio.h>
#include <limits.h>
#include <unistd.h>

size_t myStrlen(const char *str);
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *str1, const char *str2);
int myAtoi(const char *str);

int main(int argc, char **argv)
{
    // printf("Strlen: %d", myStrlen("test"));
    // printf("Strcpy: %s", myStrcpy("test", "DPDPDPDP");
    // printf("Strcmp: %s", myStrcmp("test", "test"));
    // printf("Atoi: %d", myAtoi("5432"));

    return 0;
}

size_t myStrlen(const char *str)
{
    size_t size = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        size++;
    }

    return size;
}

int myStrcmp(const char *str1, const char *str2)
{
    size_t sizeStr1 = myStrlen(str1);
    size_t sizeStr2 = myStrlen(str2);
    ;

    if (sizeStr1 > sizeStr2)
    {
        return 1;
    }
    else if (sizeStr1 < sizeStr2)
    {
        return -1;
    }

    for (size_t i = 0; i < sizeStr1; i++)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }

    return 0;
}

char *myStrcpy(char *str1, const char *str2)
{
    size_t lenStr2 = myStrlen(str2);

    for (size_t i = 0; i <= lenStr2; i++)
    {
        str1[i] = str2[i];
    }
    return str1;
}

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
