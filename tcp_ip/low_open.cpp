//
// Created by dev on 24/1/2022.
//

#include "my_socket_header.h"
#include <fcntl.h>


int main()
{
    int fd;
    char buf[100]{"Let's go!\n"};
    fd = open("data.txt",O_CREAT |O_RDWR);
    if (fd == -1){
//        error_handling("open() error!");
    }
    printf("file descriptor: %d\n",fd);
    if (write(fd, buf, sizeof (buf)) == -1){
//        error_handling("write() error!");
    }
    read(fd,buf,100);
    puts(buf);
    close(fd);
    return 0;
}