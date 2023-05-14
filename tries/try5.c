#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_MAX 1000

int main()
{
    FILE *fp;
    int status;
    char path[PATH_MAX];

    fp = popen("ls ", "r");

    if (fp == NULL)  return 0;


    while (fgets(path, PATH_MAX, fp) != NULL)
        printf("\nTest=> %s", path);

    status = pclose(fp);
}