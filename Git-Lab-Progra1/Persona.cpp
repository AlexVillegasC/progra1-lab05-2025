#include "Persona.h"
#include <sstream>
#include <algorithm>
#include <iomanip>

Persona::Persona() : name(""), location(""), profession("") {}

Persona::Persona(const std::string& name, const std::string& location, const std::string& profession)
    : name(name), location(location), profession(profession) {}

std::string Persona::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\"");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r\"");
    return str.substr(first, (last - first + 1));
}

std::string Persona::extractJsonValue(const std::string& json, const std::string& key) {
    std::string searchKey = "\"" + key + "\"";
    size_t keyPos = json.find(searchKey);

    if (keyPos == std::string::npos) {
        return "";
    }

    size_t colonPos = json.find(":", keyPos);
    if (colonPos == std::string::npos) {
        return "";
    }

    size_t valueStart = colonPos + 1;
    size_t valueEnd = json.find_first_of(",}", valueStart);

    if (valueEnd == std::string::npos) {
        valueEnd = json.length();
    }

    std::string value = json.substr(valueStart, valueEnd - valueStart);
    return trim(value);
}

bool Persona::loadFromJsonFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << filePath << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonContent = buffer.str();
    file.close();

    name = extractJsonValue(jsonContent, "name");
    location = extractJsonValue(jsonContent, "location");
    profession = extractJsonValue(jsonContent, "profession");

    return !name.empty() && !location.empty() && !profession.empty();
}

std::vector<Persona> Persona::loadAllFromFolder(const std::string& folderPath) {
    std::vector<Persona> personas;

#ifdef _WIN32
    WIN32_FIND_DATAA findFileData;
    std::string searchPath = folderPath + "\\*.json";
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::string fileName = findFileData.cFileName;
            std::string fullPath = folderPath + "\\" + fileName;

            Persona persona;
            if (persona.loadFromJsonFile(fullPath)) {
                personas.push_back(persona);
                std::cout << "Archivo cargado: " << fileName << std::endl;
            } else {
                std::cout << "Error al cargar: " << fileName << std::endl;
            }
        } while (FindNextFileA(hFind, &findFileData) != 0);
        FindClose(hFind);
    } else {
        std::cerr << "Error accediendo al directorio: " << folderPath << std::endl;
    }
#else
    DIR* dir = opendir(folderPath.c_str());
    if (dir != nullptr) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            std::string fileName = entry->d_name;
            if (fileName.length() > 5 && fileName.substr(fileName.length() - 5) == ".json") {
                std::string fullPath = folderPath + "/" + fileName;
                Persona persona;
                if (persona.loadFromJsonFile(fullPath)) {
                    personas.push_back(persona);
                    std::cout << "Archivo cargado: " << fileName << std::endl;
                } else {
                    std::cout << "Error al cargar: " << fileName << std::endl;
                }
            }
        }
        closedir(dir);
    } else {
        std::cerr << "Error accediendo al directorio: " << folderPath << std::endl;
    }
#endif

    return personas;
}

void Persona::display() const {
    std::cout << "******************************************" << std::endl;
    std::cout << "*        INFORMACION ESTUDIANTE          *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "* Nombre:     " << std::left << std::setw(25) << name << " *" << std::endl;
    std::cout << "* Ubicacion:  " << std::left << std::setw(25) << location << " *" << std::endl;
    std::cout << "* Profesion:  " << std::left << std::setw(25) << profession << " *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << std::endl;
}