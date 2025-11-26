#include "lib.h"
#include "version.h"
#include <iostream>

int version() {
    return BUILD_NUMBER;
}

void printHello() {
    std::cout << "Hello, World!" << std::endl;
}

/*  реализация функций;
    любой файл, подключивший lib.h, сможет вызвать version() или printHello()*/