#include <fstream>
#include "activity.h"
#include "director.h"
#include "general.cc"
#include "organizador.h"
#include "registered.h"
#include "user.h"

void MenuUser();
void MenuOrganizador();
void MenuDirector();
void MenuRegistrado(const std::string nombre);

int main(){
    MenuUser();
}

void MenuUser() {
    std::vector<User>users;
    std::string id,password,rol;
    std::string opc_string;
    int opc;
    User usuario("empty","empty","empty");
    std::string nombre, contraseña;
    std::ifstream archivo("user.txt");
    if(!archivo){
        std::cout<<"Error al abrir el fichero user.txt"<<std::endl;
        return;
    }
    while(archivo>>id>>password>>rol){
        users.push_back(User(id,password,rol));
    }
    archivo.close();
    do {
        std::cout<<"Seleccione qué quiere hacer"<<std::endl<<""<<std::endl;
        std::cout<<"1. Iniciar sesión"<<std::endl<<"2. Mostrar actividades disponibles"<<std::endl<<"3. Registrarse"<<std::endl<<std::endl<<"0.Cerrar el programa"<<std::endl<<""<<std::endl;
        std::cin>>opc;
        std::cout<<std::endl;
        switch (opc) {
            case 1: {
                Limpiar();
                std::cout<<"Por favor, introduzca sus datos"<<std::endl;
                std::cout<<"Nombre: ";
                std::cin>>nombre;
                std::cout<<"Contraseña: ";
                std::cin>>contraseña;
                std::cout<<std::endl;
                for (const auto& user : users) {
                    switch(user.Login(nombre,contraseña)) {
                        case 1: {
                            Limpiar();
                            std::cout<<"Ha iniciado sesión como organizador"<<std::endl<<""<<std::endl;
                            MenuOrganizador();
                            return;
                        }
                       case 2: {
                            Limpiar();
                            std::cout<<"Ha iniciado sesión como director académico"<<std::endl<<""<<std::endl;
                            MenuDirector();
                            return;
                        }
                        case 3: { 
                            Limpiar();
                            std::cout<<"Ha iniciado sesión como "<<nombre<<""<<std::endl<<""<<std::endl;
                            MenuRegistrado(nombre);
                            return;
                        }
                    }
                }
                Limpiar();
                std::cout<<"Los datos no coinciden con los de ningún usuario registrado"<<std::endl<<""<<std::endl;
                break;
            }
            case 2: {
                usuario.ShowActivities();
                break;
            }
            case 3: {
                Limpiar();
                // Nombre del archivo
                const char* nombreArchivo = "user.txt";

                // Abrir el archivo para leer
                std::ifstream archivoEntrada(nombreArchivo);

                // Verificar si el archivo está vacío
                archivoEntrada.seekg(0, std::ios::end);
                if (archivoEntrada.tellg() == 0) {
                std::cout<<"Se esta registrando como OR"<<std::endl;
                usuario.RegistroOR();
                } else {
                usuario.Registro();
                }
                // Cerrar el archivo
                archivoEntrada.close();
                break;
            }
            case 0: {
                Limpiar();
                std::cout<<"Cerrando el programa..."<<std::endl;
                return;
            }
            default: {
                Limpiar();
                std::cout<<"Por favor, introduzca una opción válida (debe introducir el número de la opción)"<<std::endl<<""<<std::endl;
            }
        }
    } while (true);
}

void MenuOrganizador() {
    User usuario("","","");
    Organizador organizador;
    int opc;
    do {
        std::cout<<"Seleccione qué quiere hacer"<<std::endl<<""<<std::endl;
        std::cout<<"1. Crear actividad"<<std::endl<<""<<"2. Mostrar preinscripciones"<<std::endl<<""<<"3. Mostrar actividades activadas"<<std::endl<<"4.Registrar Diretor Academico"<<std::endl<<std::endl<<"0. Salir del programa"<<std::endl<<""<<std::endl;
        std::cin>>opc;
        std::cout<<std::endl;
        switch (opc) {
            case 0: {
                Limpiar();
                std::cout<<"Cerrando el programa..."<<std::endl;
                return;
            }
            case 1: {
                organizador.CreateAcivity();
                break;
            }
            case 2: {
                organizador.ShowPrescriptions();
                break;
            }
            case 3: {
                usuario.ShowActivities();
                break;
            }
            case 4: {
                Limpiar();
                usuario.RegistroDA();
                break;
            }
            default: {
                Limpiar();
                std::cout<<"Por favor, introduzca una opción válida (debe introducir el número de la opción)"<<std::endl<<""<<std::endl;
            }
        }
    } while (true);
}

void MenuDirector() {
    User usuario("","","");
    Director director;
    int opc;
    do {
        std::cout<<"Seleccione qué quiere hacer"<<std::endl<<""<<std::endl;
        std::cout<<"1. Editar una actividad"<<std::endl<<""<<"2. Activar una actividad"<<std::endl<<""<<"3. Mostrar actividades activadas"<<std::endl<<""<<""<<std::endl<<"0. Cerrar el programa"<<std::endl<<""<<std::endl;
        std::cin>>opc;
        std::cout<<std::endl;
        switch (opc) {
            case 0: {
                Limpiar();
                std::cout<<"Cerrando el programa..."<<std::endl;
                return;
            }
            case 1: {
                director.EditActivity();
                break;
            }
            case 2: {
                director.ActivateActivity();
                break;
            }
            case 3: {
                usuario.ShowActivities();
                break;
            }
            default: {
                Limpiar();
                std::cout<<"Por favor, introduzca una opción válida (debe introducir el número de la opción)"<<std::endl<<""<<std::endl;
            }
        }
    } while (true);
}

void MenuRegistrado(const std::string nombre) {
    User usuario("","","");
    Registered registrado(nombre,"","");
    int opc;
    do {
        std::cout<<"Seleccione qué quiere hacer"<<std::endl<<""<<std::endl;
        std::cout<<"1. Preinscribirse en una actividad"<<std::endl<<""<<"2. Mostrar actividades disponibles"<<std::endl<<"3. Mostrar actividades en las que se ha preinscrito"<<std::endl<<std::endl<<"0. Cerrar el programa"<<std::endl<<""<<std::endl;
        std::cin>>opc;
        switch (opc) {
            case 0: {
                Limpiar();
                std::cout<<"Cerrando el programa..."<<std::endl;
                return;
            }
            case 1: {
                registrado.Preinscribirse();
                break;
            }
            case 2: {
                usuario.ShowActivities();
                break;
            }
            case 3: {
                registrado.VerPreinscripciones();
                break;
            }
            default: {
                Limpiar();
                std::cout<<"Por favor, introduzca una opción válida (debe introducir el número de la opción)"<<std::endl<<""<<std::endl;
            }
        }
    } while (true);
}
