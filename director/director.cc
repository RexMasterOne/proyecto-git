#include "director.h"
#include <sstream>
#include <limits>

void Director::LoadActivities() {
    std::ifstream file("actividades.txt");
    std::string line;
    while (std::getline(file, line)) {
        Activity act;
        act.id = line;
        std::getline(file, line);
        act.activa = (line == "true");
        std::getline(file, act.tipo);
        std::getline(file, act.ponente);
        std::getline(file, act.fecha_y_hora);
        std::getline(file, act.lugar);
        actividades.push_back(act);
    }
    file.close();
}

void Director::SaveActivities() {
    std::ofstream file("actividades.txt");
    for (const auto& act : actividades) {
        file << act.id << ""<<std::endl<<""
             << (act.activa ? "true" : "false") << ""<<std::endl<<""
             << act.tipo << ""<<std::endl<<""
             << act.ponente << ""<<std::endl<<""
             << act.fecha_y_hora << ""<<std::endl<<""
             << act.lugar << ""<<std::endl<<"";
    }
    file.close();
}

bool Director::EditActivity() {
    Limpiar();
    std::ifstream f("actividades.txt");
    std::string line;
    std::vector<std::string> lines;
    while (getline(f,line)) {
        lines.push_back(line);
    }
    if (lines.size()==0) {
        Limpiar();
        std::cout<<"No hay actividades disponibles en este momento"<<std::endl<<std::endl;
        return false;
    } 
    int i=0;
    for (const std::string& output : lines) {
        i++;
        if ((i-1)%6==0) {
            std::cout<<output<<std::endl;
        }
    }
    std::string id;
    std::cout<<std::endl<<"Introduce el id de la actividad que quieres modificar: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore newline
    for (auto& act : actividades) {
        if (act.id == id) {
            std::cout << ""<<std::endl<<""<<std::endl<<"Introduce el tipo de actividad: ";
            std::getline(std::cin, act.tipo);
            std::cout << "Introduce el ponente de la actividad: ";
            std::getline(std::cin, act.ponente);
            std::cout << "Introduce la fecha y hora de la actividad: ";
            std::getline(std::cin, act.fecha_y_hora);
            std::cout << "Introduce el lugar de la actividad: ";
            std::getline(std::cin, act.lugar);
            SaveActivities();
            Limpiar();
            std::cout<<"Actividad editada con éxito"<<std::endl<<""<<std::endl;
            return true;
        }
    }
    Limpiar();
    std::cout<<""<<std::endl<<"No se ha encontrado ninguna actividad con el id especificado"<<std::endl<<""<<std::endl;
    return false;
}

bool Director::ActivateActivity() {
    Limpiar();
    std::ifstream f("actividades.txt");
    std::string line, id_lectura, activa;
    std::vector<std::string> lines;
    while (getline(f,line)) {
        lines.push_back(line);
    }
    if (lines.size()==0) {
        Limpiar();
        std::cout<<"No hay actividades disponibles en este momento"<<std::endl<<std::endl;
        return false;
    } 
    int i=0;
    for (const std::string& output : lines) {
        i++;
        if ((i-1)%6 == 0) {
            id_lectura = output;
        } else if (((i-2)%6==0) && (output == "false")) {
            std::cout<<id_lectura<<std::endl;
        }
    }
    std::string id;
    std::cout << ""<<std::endl<<"Introduce el id de la actividad que quieres activar:";
    std::cin >> id;
    for (auto& act : actividades) {
        if (act.id == id) {
            act.activa = true;
            SaveActivities();
            Limpiar();
            std::cout<<"Actividad activada con éxito"<<std::endl<<""<<std::endl;
            return true;
        }
    }
    Limpiar();
    std::cout<<"No se ha encontrado ninguna actividad con el id especificado"<<std::endl<<""<<std::endl;
    return false;
}