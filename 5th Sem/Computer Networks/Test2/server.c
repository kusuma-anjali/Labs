#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

char fname[256];

int main()
{
    ssize_t n;
    int fd, readfd, writefd, sz, smp;
    char buff[512];

    FILE *f = fopen("file3.txt", "w");
    fclose(f);
    f = fopen("file3.txt", "a");

    if (mkfifo(FIFO1, PERMS) < 0)
    {
        printf("Cant open FIFO 1");
    }

    if (mkfifo(FIFO2, PERMS) < 0)
    {
        printf("Cant open FIFO 2");
    }

    readfd = open(FIFO1, O_RDONLY, 0);
    writefd = open(FIFO2, O_WRONLY, 0);

    printf("Connection established successfully");

    while (1)
    {
        sz = read(readfd, fname, sizeof(fname));
        fname[sz] = '\0';
        smp = strcmp(fname, "end");
        if (smp == 0)
        {
            fclose(f);
            break;
        }
        else
        {
            fprintf(f, fname, strlen(fname));
        }
    }

    if ((fd = open("file3.txt", O_RDONLY)) < 0)
    {
        strcpy(buff, "Cannot open file");
        write(writefd, buff, strlen(buff));
    }
    else
    {
        while ((n = read(fd, buff, 512)) > 0)
        {
            write(writefd, buff, n);
        }
    }
    close(readfd);
    close(writefd);
    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}