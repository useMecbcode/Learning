//
// Created by dev on 25/1/2022.
//

#ifndef OP_NET_COMMON_H
#define OP_NET_COMMON_H
#ifndef __cplusplus
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif
#ifdef __cplusplus

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

void error_handling(const std::string &message);

#elif
void error_handling(char *message);
#endif

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#endif //OP_NET_COMMON_H

#include<netdb.h>
#include <thread>
using namespace std;
int main(int argc, char *argv[]){
    hostent *host{nullptr};
    if (argc != 2){
        cerr << "Usage: " << argv[0] << "<addr>" << endl;
        exit(EXIT_FAILURE);
    }
    host = gethostbyname(argv[1]);
    if (!host){
        error_handling("gethostbyname() error");
    }
    cout <<"Official name:" << host->h_name << endl;
    for (int i = 0; host->h_aliases[i]; ++i) {
        cout << "Aliases "<< i + 1 << ":"<<host-> h_aliases[i] << endl;
    }
    cout << (host->h_addrtype == AF_INET?"AF_INET":"AF_INET6") << endl;
    for (int i = 0; host->h_addr_list[i]; ++i) {
        cout << "IP address "<< i + 1 << ":"<< inet_ntoa(*reinterpret_cast<in_addr *>(host->h_addr_list[i])) << endl;
    }
    thread s{[](int a){cout << " " << a << endl;},3};
    s.detach();
    return 0;
}

void error_handling(const std::string &message) {
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}