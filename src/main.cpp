#include "lib.h"
#include <iostream>

int main() {
    printHello();
    std::cout << "Build " << version() << std::endl;
    return 0;
}

/*  main.cpp - только точка входа;
    вся логика вынесена в lib.cpp*/