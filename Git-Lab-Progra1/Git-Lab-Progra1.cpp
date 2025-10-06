#include <iostream>
#include <iomanip>
#include "Persona.h"

int main()
{
    std::cout << "***************************************************************" << std::endl;
    std::cout << "*             SISTEMA DE GESTION DE ESTUDIANTES               *" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    std::cout << std::endl;

    std::cout << "Cargando archivos JSON desde la carpeta 'datos'..." << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    std::vector<Persona> estudiantes = Persona::loadAllFromFolder("datos");

    if (estudiantes.empty()) {
        std::cout << "No se encontraron archivos JSON válidos en la carpeta 'datos'." << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "Se cargaron " << estudiantes.size() << " estudiante(s) exitosamente." << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < estudiantes.size(); ++i) {
        std::cout << "ESTUDIANTE #" << (i + 1) << std::endl;
        estudiantes[i].display();

        if (i < estudiantes.size() - 1) {
            std::cout << "Presiona Enter para continuar al siguiente estudiante...";
            std::cin.get();
            std::cout << std::endl;
        }
    }

    std::cout << "***************************************************************" << std::endl;
    std::cout << "*                   FIN DEL PROGRAMA                          *" << std::endl;
    std::cout << "***************************************************************" << std::endl;

    return 0;
}