#include <iostream>

#define MESSAGE "hello"     //direttiva del pre-processore

void speak(){

    std::cout << MESSAGE << std::endl;
}

//se scrivo g++ lib.cpp avrò errore del linker (ld:)
