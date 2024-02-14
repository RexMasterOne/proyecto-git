#include "user.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

User:: User(const std::string& id,const std::string& password,const std::string& rol):id_(id),password_(password),rol_(rol){}
int User::Login(const std::string& id,const std::string& password)const{
    if(id==id_ && password==password_){
        if(rol_=="USR"){return 3;}
        if(rol_=="DA"){return 2;}
        if(rol_=="OR"){return 1;}
    }
    return 0;
}

void User::ShowActivities(){
    Limpiar();
    std::ifstream f("actividades.txt");
    if (!f.is_open()) {
        Limpiar();
        std::cout<<"ERROR: no se pudo abrir el fichero de actividades (ShowActivities)"<<std::endl;
        return;
    }
    bool empty=false;
    std::vector<std::string> lines;
    std::string line;
    while (getline(f,line)) {
        lines.push_back(line);
    }
    f.close();
    int i=0;
    std::vector<std::string> output;
    for (const std::string& iterator : lines) {
        i++;
        output.push_back(iterator);
        if ((i%6==0)) {
            if (output[1]=="true") {
                empty = true;
                std::cout<<output[0]<<""<<std::endl<<""<<output[2]<<""<<std::endl<<""<<output[3]<<""<<std::endl<<""<<output[4]<<""<<std::endl<<""<<output[5]<<""<<std::endl<<""<<std::endl;
            }
            output.clear();
        }
    }
    if (empty==false) {
        Limpiar();
        std::cout<<"No hay actividades disponibles en este momento"<<std::endl<<std::endl;
    }
}

void User:: Registro(){
// Definir un array para almacenar el correo electrónico
    const int tamanoMaximoCorreo = 100;
    char bufferCorreo[tamanoMaximoCorreo] = "empty";  // Inicializar como "empty"

    bool correoValido=false;

    // Pedir al usuario que ingrese el correo electrónico
    std::cin.getline(bufferCorreo, tamanoMaximoCorreo);

    // Asignar la dirección del array a cadenaCompleta
    const char* cadenaCompleta = bufferCorreo;

    const char* cadenaBuscada = "@uco.es";

    // Obtener el tamaño de la cadena completa
    size_t tamanoCadena = strlen(cadenaCompleta);

    // Buscar la cadena en la cadena completa
    size_t posicion = std::string(cadenaCompleta).find(cadenaBuscada);

    // Verificar si la cadena fue encontrada
    if (posicion != std::string::npos) {
        correoValido = true;
    }

    // Solicitar al usuario que ingrese el correo electrónico hasta que sea válido
    while (!correoValido) {
        std::cout << "Ingrese su correo electrónico: ";

        // Pedir al usuario que ingrese el correo electrónico
        std::cin.getline(bufferCorreo, tamanoMaximoCorreo);

        // Asignar la dirección del array a cadenaCompleta
        const char* cadenaCompleta = bufferCorreo;

        const char* cadenaBuscada = "@uco.es";

        // Obtener el tamaño de la cadena completa
        size_t tamanoCadena = strlen(cadenaCompleta);

        // Buscar la cadena en la cadena completa
        size_t posicion = std::string(cadenaCompleta).find(cadenaBuscada);

        // Verificar si la cadena fue encontrada
        if (posicion != std::string::npos) {
            correoValido = true;
        } else {
            std::cout << "El correo no es válido. Inténtelo de nuevo." << std::endl;
            correoValido = false;
        }
    }

    // Abrir un fichero para leer
    std::ifstream archivoEntrada("user.txt");

    // Verificar si el fichero se abrió correctamente
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa en caso de error
    }

    // Verificar si el usuario ya existe en el fichero
    bool usuarioExistente = false;
    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        // Utilizar un stringstream para extraer el correo de cada línea
        std::istringstream streamLinea(linea);
        std::string correoEnLinea;
        streamLinea >> correoEnLinea;

        // Verificar si el correo coincide
        if (correoEnLinea == bufferCorreo) {
            usuarioExistente = true;
            break;
        }
    }

    // Cerrar el fichero de entrada
    archivoEntrada.close();

    // Si el usuario ya existe, mostrar un mensaje y salir
    if (usuarioExistente) {
        std::cout << "El usuario ya existe en el fichero." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Abrir el fichero para escribir
    std::ofstream archivoSalida("user.txt", std::ios::app);

    // Verificar si el fichero se abrió correctamente
    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa en caso de error
    }

    // Pedir al usuario que ingrese la contraseña
    std::cout << "Ingrese su contraseña: ";
    std::string contraseña;
    std::getline(std::cin, contraseña);

    // Escribir en el fichero: "Correo Contraseña Rol"
    archivoSalida << bufferCorreo << " " << contraseña << " USR" << std::endl;

    // Cerrar el fichero de salida
    archivoSalida.close();

    std::cout << "Datos escritos en el fichero correctamente." << std::endl;

    exit(EXIT_SUCCESS);
}

void User:: RegistroOR(){
// Definir un array para almacenar el correo electrónico
    const int tamanoMaximoCorreo = 100;
    char bufferCorreo[tamanoMaximoCorreo] = "empty";  // Inicializar como "empty"

    bool correoValido=false;

    // Pedir al usuario que ingrese el correo electrónico
    std::cin.getline(bufferCorreo, tamanoMaximoCorreo);

    // Asignar la dirección del array a cadenaCompleta
    const char* cadenaCompleta = bufferCorreo;

    const char* cadenaBuscada = "@uco.es";

    // Obtener el tamaño de la cadena completa
    size_t tamanoCadena = strlen(cadenaCompleta);

    // Buscar la cadena en la cadena completa
    size_t posicion = std::string(cadenaCompleta).find(cadenaBuscada);

    // Verificar si la cadena fue encontrada
    if (posicion != std::string::npos) {
        correoValido = true;
    }

    // Solicitar al usuario que ingrese el correo electrónico hasta que sea válido
    while (!correoValido) {
        std::cout << "Ingrese su correo electrónico: ";

        // Pedir al usuario que ingrese el correo electrónico
        std::cin.getline(bufferCorreo, tamanoMaximoCorreo);

        // Asignar la dirección del array a cadenaCompleta
        const char* cadenaCompleta = bufferCorreo;

        const char* cadenaBuscada = "@uco.es";

        // Obtener el tamaño de la cadena completa
        size_t tamanoCadena = strlen(cadenaCompleta);

        // Buscar la cadena en la cadena completa
        size_t posicion = std::string(cadenaCompleta).find(cadenaBuscada);

        // Verificar si la cadena fue encontrada
        if (posicion != std::string::npos) {
            correoValido = true;
        } else {
            std::cout << "El correo no es válido. Inténtelo de nuevo." << std::endl;
            correoValido = false;
        }
    }

    // Abrir un fichero para leer
    std::ifstream archivoEntrada("user.txt");

    // Verificar si el fichero se abrió correctamente
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa en caso de error
    }

    // Verificar si el usuario ya existe en el fichero
    bool usuarioExistente = false;
    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        // Utilizar un stringstream para extraer el correo de cada línea
        std::istringstream streamLinea(linea);
        std::string correoEnLinea;
        streamLinea >> correoEnLinea;

        // Verificar si el correo coincide
        if (correoEnLinea == bufferCorreo) {
            usuarioExistente = true;
            break;
        }
    }

    // Cerrar el fichero de entrada
    archivoEntrada.close();

    // Si el usuario ya existe, mostrar un mensaje y salir
    if (usuarioExistente) {
        std::cout << "El usuario ya existe en el fichero." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Abrir el fichero para escribir
    std::ofstream archivoSalida("user.txt", std::ios::app);

    // Verificar si el fichero se abrió correctamente
    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa en caso de error
    }

    // Pedir al usuario que ingrese la contraseña
    std::cout << "Ingrese su contraseña: ";
    std::string contraseña;
    std::getline(std::cin, contraseña);

    // Escribir en el fichero: "Correo Contraseña Rol"
    archivoSalida << bufferCorreo << " " << contraseña << " OR" << std::endl;

    // Cerrar el fichero de salida
    archivoSalida.close();

    std::cout << "Datos escritos en el fichero correctamente." << std::endl;

    exit(EXIT_SUCCESS);
}

void User:: RegistroDA(){
// Definir un array para almacenar el correo electrónico
    const int tamanoMaximoCorreo = 100;
    char bufferCorreo[tamanoMaximoCorreo] = "empty";  // Inicializar como "empty"

    bool correoValido=false;

    // Pedir al usuario que ingrese el correo electrónico
    std::cin.getline(bufferCorreo, tamanoMaximoCorreo);

    // Asignar la dirección del array a cadenaCompleta
    const char* cadenaCompleta = bufferCorreo;

    const char* cadenaBuscada = "@uco.es";

    // Obtener el tamaño de la cadena completa
    size_t tamanoCadena = strlen(cadenaCompleta);

    // Buscar la cadena en la cadena completa
    size_t posicion = std::string(cadenaCompleta).find(cadenaBuscada);

    // Verificar si la cadena fue encontrada
    if (posicion != std::string::npos) {
        correoValido = true;
    }

    // Solicitar al usuario que ingrese el correo electrónico hasta que sea válido
    while (!correoValido) {
        std::cout << "Ingrese su correo electrónico: ";

        // Pedir al usuario que ingrese el correo electrónico
        std::cin.getline(bufferCorreo, tamanoMaximoCorreo);

        // Asignar la dirección del array a cadenaCompleta
        const char* cadenaCompleta = bufferCorreo;

        const char* cadenaBuscada = "@uco.es";

        // Obtener el tamaño de la cadena completa
        size_t tamanoCadena = strlen(cadenaCompleta);

        // Buscar la cadena en la cadena completa
        size_t posicion = std::string(cadenaCompleta).find(cadenaBuscada);

        // Verificar si la cadena fue encontrada
        if (posicion != std::string::npos) {
            correoValido = true;
        } else {
            std::cout << "El correo no es válido. Inténtelo de nuevo." << std::endl;
            correoValido = false;
        }
    }

    // Abrir un fichero para leer
    std::ifstream archivoEntrada("user.txt");

    // Verificar si el fichero se abrió correctamente
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa en caso de error
    }

    // Verificar si el usuario ya existe en el fichero
    bool usuarioExistente = false;
    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        // Utilizar un stringstream para extraer el correo de cada línea
        std::istringstream streamLinea(linea);
        std::string correoEnLinea;
        streamLinea >> correoEnLinea;

        // Verificar si el correo coincide
        if (correoEnLinea == bufferCorreo) {
            usuarioExistente = true;
            break;
        }
    }

    // Cerrar el fichero de entrada
    archivoEntrada.close();

    // Si el usuario ya existe, mostrar un mensaje y salir
    if (usuarioExistente) {
        std::cout << "El usuario ya existe en el fichero." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Abrir el fichero para escribir
    std::ofstream archivoSalida("user.txt", std::ios::app);

    // Verificar si el fichero se abrió correctamente
    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el fichero." << std::endl;
        exit(EXIT_FAILURE); // Salir del programa en caso de error
    }

    // Pedir al usuario que ingrese la contraseña
    std::cout << "Ingrese su contraseña: ";
    std::string contraseña;
    std::getline(std::cin, contraseña);

    // Escribir en el fichero: "Correo Contraseña Rol"
    archivoSalida << bufferCorreo << " " << contraseña << " DA" << std::endl;

    // Cerrar el fichero de salida
    archivoSalida.close();

    std::cout << "Datos escritos en el fichero correctamente." << std::endl;

    exit(EXIT_SUCCESS);
}