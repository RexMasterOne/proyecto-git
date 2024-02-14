#ifndef REGISTERED_H
#define REGISTERED_H

#include "user.h"
#include "general.h"

class Registered : public User{
    public:
        Registered(const std::string& id,const std::string& password,const std::string& rol) : User(id,password,rol){};
        bool Preinscribirse();
        void PreinscribirUsuario(std::string actividad);
        void VerPreinscripciones();
};

#endif