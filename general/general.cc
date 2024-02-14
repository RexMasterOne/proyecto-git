#include "general.h"

void Limpiar(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
    return;
    
}