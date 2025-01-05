#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include<string.h>

int main()
{
    char dirname[256];
    struct dirent *dptr;
    DIR *dir;

    printf("ENTER DIRECTORY NAME: ");
    fgets(dirname, sizeof(dirname), stdin);
    dirname[strcspn(dirname, "\n")] = '\0';

    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("Error opening directory");
        return 1;
    }

    while ((dptr = readdir(dir)) != NULL)
    {
        printf("%s\n", dptr->d_name);
    }

    closedir(dir);
    return 0;
}

// Compile and RUN :
// gcc fileName.c - o fileName
// ./fileName