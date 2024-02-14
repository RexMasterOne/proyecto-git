#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "general.h"

class Director {
public:
    Director()
    {
        LoadActivities();
    }
    bool EditActivity();
    bool ActivateActivity();
private:
    struct Activity {
        std::string id;
        bool activa;
        std::string tipo;
        std::string ponente;
        std::string fecha_y_hora;
        std::string lugar;
    };
    std::vector<Activity> actividades;
    void LoadActivities();
    void SaveActivities();
};