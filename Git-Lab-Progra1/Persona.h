#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif

class Persona {
private:
    std::string name;
    std::string location;
    std::string profession;

    std::string extractJsonValue(const std::string& json, const std::string& key);
    std::string trim(const std::string& str);

public:
    Persona();
    Persona(const std::string& name, const std::string& location, const std::string& profession);

    bool loadFromJsonFile(const std::string& filePath);
    static std::vector<Persona> loadAllFromFolder(const std::string& folderPath);

    void display() const;

    const std::string& getName() const { return name; }
    const std::string& getLocation() const { return location; }
    const std::string& getProfession() const { return profession; }
};