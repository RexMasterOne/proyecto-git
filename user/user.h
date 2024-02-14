#ifndef USER_H
#define USER_H
#include <string>
#include "general.h"

class User{
    private:
    std::string password_;
    public:
    std::string id_;
    std::string rol_;
    User(const std::string& id,const std::string& password,const std::string& rol);
    int Login(const std::string& id,const std::string& password)const;
    void ShowActivities();
    void SetRol(std::string rol){rol_=rol;}
    void Registro();
    void RegistroOR();
    void RegistroDA();
};

#endif