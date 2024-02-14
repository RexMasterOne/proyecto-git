#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <fstream>
#include "general.h"

class Activity{
    private:
        std::string id_;
        bool activa_=false;
        std::string tipo_;
        std::string ponente_;
        std::string fecha_y_hora_;
        std::string lugar_;
    public:
        Activity(std::string id, bool activa=false, std::string tipo="empty",std::string ponente = "empty", std::string fecha_y_hora="empty", std::string lugar="empty") {
            id_=id;
            activa_=activa;
            tipo_=tipo;
            ponente_=ponente;
            fecha_y_hora_=fecha_y_hora;
            lugar_=lugar;
            GuardarActividad();
        }
        bool GuardarActividad();
        std::string GetId(){return id_;}
        bool GetActiva(){return activa_;}
        void SetActiva(bool activa){activa_=activa;}
        std::string GetTipo(){return tipo_;}
        void SetTipo(std::string tipo){tipo_=tipo;}
        std::string GetPonente(){return ponente_;}
        void SetPonente(std::string ponente){ponente_=ponente;}
        std::string GetFechaYHora(){return fecha_y_hora_;}
        void SetFechaYHora(std::string fecha_y_hora){fecha_y_hora_=fecha_y_hora;}
        std::string GetLugar(){return lugar_;}
        void SetLugar(std::string lugar){lugar_=lugar;}
};

#endif