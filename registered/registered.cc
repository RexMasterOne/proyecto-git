#include "registered.h"
#include <iostream>
#include <fstream>
#include <vector>

bool Registered::Preinscribirse(){
    Limpiar();
    std::ifstream f("actividades.txt");
    if (!f.is_open()) {
        Limpiar();
        std::cout<<"ERROR: No se pudo abrir el archivo de actividades (Preinscribirse)"<<std::endl;
    }
    std::string id, activa, line;
    std::vector<std::string> lines;
    while(getline(f,line))
        lines.push_back(line);
    f.close();
    if (lines.size()==0) {
        std::cout<<"No hay actividades disponibles en este momento"<<std::endl<<std::endl;
        return false;
    }
    std::cout<<"Estas son las actividades disponibles"<<std::endl;
    ShowActivities();
    std::cout<<"Seleccione la actividad en la que quiera inscribirse escribiendo su nombre"<<std::endl;
    std::string nombre;
    std::cin>>nombre;
    int i=0;
    for (const std::string& output : lines) {
        i++;
        if ((i-1==0) || ((i-1)%6==0))
            id = output;
        if (((i-2==0) || ((i-2)%6==0)) && (id == nombre) && (output=="true")) {
            PreinscribirUsuario(nombre);
            return true;
        }
    }
    Limpiar();
    std::cout<<""<<std::endl<<"Esa actividad no existe"<<std::endl<<""<<std::endl;
    return false;
}

void Registered::PreinscribirUsuario(std::string actividad) {
    std::ifstream f("preinscripciones.txt");
    if (!f.is_open()) {
        Limpiar();
        std::cout<<""<<std::endl<<"ERROR: No se pudo abrir el archivo de preinscripciones (PreinscribirUsuario ifstream)"<<std::endl<<""<<std::endl;
        return;
    }
    std::vector<std::string> lines;
    std::string line, id_fichero, actividad_fichero;
    while (getline(f,line))
        lines.push_back(line);
    int i = 0;
    for (const std::string& output : lines) {
        i++;
        if (i%2!=0) {
            id_fichero = output;
        } else {
            if ((id_fichero == id_) && (output == actividad)) {
                Limpiar();
                std::cout<<""<<std::endl<<"Ya estás preinscrito en esta actividad"<<std::endl<<""<<std::endl;
                return;
            }
        }
    }
    f.close();
    std::ofstream f2("preinscripciones.txt",std::ios::app);
    if (!f2.is_open()) {
        Limpiar();
        std::cout<<"ERROR: No se pudo abrir el archivo de preinscripciones (PreinscribirUsuario ofstream)"<<std::endl;
        return;
    }
    f2<<id_<<std::endl<<actividad<<std::endl;
    Limpiar();
    std::cout<<std::endl<<"Preinscripción realizada con éxito"<<std::endl<<std::endl;
    return;
}

void Registered::VerPreinscripciones(){
    Limpiar();
    std::vector<std::string> lines;
    std::string line;
    bool empty = false;
    std::ifstream f("preinscripciones.txt");
    while (getline(f,line)) {
        empty = true;
        lines.push_back(line);
    }
    f.close();
    if (empty==false) {
        std::cout<<"No se ha preinscrito en ninguna actividad"<<std::endl<<std::endl;
        return;
    }
    std::string nombre,actividad;
    std::vector<std::string> actividades;
    int i=0;
    for (const std::string& output : lines) {
        i++;
        if (i%2==1) {
            nombre = output;
        } else if (nombre==(*this).id_) {
            actividades.push_back(output);
        }
    }
    if (actividades.size()==0) {
        std::cout<<"No se ha preinscrito en ninguna actividad"<<std::endl<<std::endl;
        return;
    }
    std::cout<<"Se ha preinscrito en las siguientes actividades:"<<std::endl;
    for (const std::string& output : actividades) 
        std::cout<<output<<std::endl;
    std::cout<<std::endl;
    return;
}