//
// Created by dev on 23/1/2022.
//

#include "my_socket_header.h"

#ifdef __cplusplus

void error_handling(const std::string &message) {
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}

#elif
void error_handling(cahr *message){
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(EXIT_FAILURE);

}
#endif