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
    int readfd, writefd, sz, smp;
    char buff[512];

    writefd = open(FIFO1, O_WRONLY, 0);
    readfd = open(FIFO2, O_RDONLY, 0);

    printf("Connection established successfully");

    while (1)
    {
        printf("Enter the sentence :");
        fgets(fname, sizeof(fname), stdin);
        sz = strlen(fname);
        fname[sz - 1] = '\0';
        smp = strcmp(fname, "end");
        if (smp == 0)
        {
            write(writefd, fname, strlen(fname));
            break;
        }
        else
        {
            write(writefd, fname, strlen(fname));
        }
    }

    while ((n = read(readfd, buff, 512)) > 0)
    {
        write(1, buff, n);
    }
    close(readfd);
    close(writefd);
    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}