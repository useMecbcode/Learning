//
// Created by dev on 23/1/2022.
//

#include "my_socket_header.h"

int main(int argc, char **argv) {
    int sock;
    sockaddr_in serv_addr{};
    char message[30];
    ssize_t str_len{0};
    int idx = 0;
    int read_len = 0;
    if (argc != 3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(std::stoi(argv[2]));
    if (connect(sock, reinterpret_cast<sockaddr *>(&serv_addr), sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }
    str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == -1) {
        error_handling("read() error");
    }
    while (read_len = read(sock, &message[idx++], 1)){
        if (read_len == -1){
            error_handling("read() error");
        }
        str_len += read_len;
    }
    std::cout << "Message from server : " << message << std::endl;
    std::cout << "Function read be called count:  " << str_len << std::endl;
    close(sock);
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;
    net_port = htons(host_port);
    net_addr = htonl(host_addr);
    std::cout.setf(std::ios::hex,std::ios::basefield);
    std::cout << "Host order port:" << host_port << std::endl;
    std::cout << "Network order port:" << net_port << std::endl;
    std::cout << "Host order address:" << host_addr << std::endl;
    std::cout << "Network order address:" << net_addr << std::endl;
    std::cout.unsetf(std::ios::hex);
    return 0;
}