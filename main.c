#include <stdio.h>

size_t myStrlen(const char *str);
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *str1, const char *str2);

int main(int argc, char **argv)
{
    // printf("Strlen: %d", myStrlen("test"));
    // printf("Strcpy: %s", myStrcpy("test", "DPDPDPDP");
    // printf("Strcmp: %s", myStrcmp("test", "test"));

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
