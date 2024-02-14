#include "activity.h"

bool Activity::GuardarActividad(){
    std::ifstream f("actividades.txt");
    if (!f.is_open()) {
        f.close();
        std::ofstream f("actividades.txt");
        f<<id_<<""<<std::endl<<""<<(activa_ ? "true" : "false") << ""<<std::endl<<""<<tipo_<<""<<std::endl<<""<<ponente_<<""<<std::endl<<""<<fecha_y_hora_<<""<<std::endl<<""<<lugar_<<""<<std::endl<<"";
        f.close();
        return true;
    }
    std::string cadena;
    int i;
    do
    {
        std::getline(f,cadena);
        if (cadena==id_) {
            Limpiar();
            std::cout<<"ERROR: ya existe una actividad con ese ID"<<std::endl<<""<<std::endl;
            f.close();
            return false;
        }
        i=5;
        do {
            i--;
            std::getline(f,cadena);
        } while (i!=0);
    } while (!f.eof());
    f.close();
    std::ofstream f2("actividades.txt",std::ios::app);
    f2<<id_<<""<<std::endl<<"";
    if(activa_==true) {
        f2<<"true"<<std::endl<<"";
    } else {
        f2<<"false"<<std::endl<<"";
    }
    f2<<tipo_<<""<<std::endl<<""<<ponente_<<""<<std::endl<<""<<fecha_y_hora_<<""<<std::endl<<""<<lugar_<<""<<std::endl<<"";
    f.close();
    Limpiar();
    std::cout<<"Actividad creada con éxito"<<std::endl<<""<<std::endl;
    return true;
}