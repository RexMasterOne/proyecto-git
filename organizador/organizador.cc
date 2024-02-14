#include "organizador.h"
#include <vector>

bool Organizador::CreateAcivity(){
    Limpiar();
    std::cout<<"Introduzca el id de la nueva actividad"<<std::endl;
    std::string id;
    std::cin>>id;
    Activity actividad(id);
}

void Organizador::ShowPrescriptions() {
    Limpiar();
    std::vector<std::string> lines;
    std::string line;
    bool empty = false;
    std::ifstream f("preinscripciones.txt");
    while (getline(f,line)) {
        empty = true;
        lines.push_back(line);
    }
    if (empty == false) {
        std::cout<<"No hay prescripciones en este momento"<<std::endl<<""<<std::endl;
    }
    int i = 0;
    for (const std::string& output : lines) {
        i++;
        if ((i%2)==1) {
            std::cout<<output<<" - ";
        } else {
            std::cout<<output<<std::endl;
        }
    }
    std::cout<<std::endl;
}