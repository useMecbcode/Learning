//
// Created by dev on 25/1/2022.
//
#include "common.h"
void error_handling(const std::string &message){
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}