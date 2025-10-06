# Sistema de Gestión de Estudiantes

## Descripción
Esta aplicación en C++ permite cargar información de estudiantes desde archivos JSON ubicados en la carpeta `datos/` y mostrar la información con una interfaz sencilla en consola.

## Estructura del Proyecto

### Archivos principales:
- `Persona.h` - Definición de la clase Persona
- `Persona.cpp` - Implementación de la clase Persona
- `Git-Lab-Progra1.cpp` - Archivo principal con la función main
- `datos/` - Carpeta que contiene los archivos JSON

### Archivos JSON de ejemplo:
- `alexvillegas.json`
- `maria_garcia.json`
- `juan_perez.json`

## Formato de JSON
Los archivos JSON deben tener exactamente estas 3 propiedades:
```json
{
  "name": "Nombre del estudiante",
  "location": "Ubicación del estudiante",
  "profession": "Profesión del estudiante"
}
```

## Funcionalidades de la Clase Persona

### Métodos principales:
1. `loadFromJsonFile()` - Carga datos desde un archivo JSON específico
2. `loadAllFromFolder()` - Carga todos los archivos JSON de una carpeta
3. `display()` - Muestra la información del estudiante con formato visual
4. `extractJsonValue()` - Extrae valores específicos del JSON (método privado)

### Características:
- **Parsing JSON simple**: Implementa un parser básico sin dependencias externas
- **Lectura de directorio**: Compatible con Windows y Unix/Linux
- **Interfaz visual**: Usa caracteres ASCII simples para crear marcos decorativos
- **Validación**: Verifica que todos los campos requeridos estén presentes

## Flujo de Ejecución

1. **Inicio**: Muestra un banner de bienvenida
2. **Carga**: Lee todos los archivos .json de la carpeta "datos"
3. **Validación**: Verifica que cada archivo tenga los 3 campos requeridos
4. **Visualización**: Muestra cada estudiante con formato visual
5. **Interacción**: Pausa entre estudiantes para mejor lectura
6. **Fin**: Muestra mensaje de finalización

## Compilación

### Para Visual Studio:
```bash
msbuild Git-Lab-Progra1.vcxproj /p:Configuration=Debug /p:Platform=x64
```

### Para MinGW/GCC:
```bash
g++ -std=c++11 Git-Lab-Progra1.cpp Persona.cpp -o programa.exe
```

## Ejecución
```bash
./programa.exe
```

## Ejemplo de Salida
```
***************************************************************
*             SISTEMA DE GESTION DE ESTUDIANTES               *
***************************************************************

Cargando archivos JSON desde la carpeta 'datos'...
---------------------------------------------------------------
Archivo cargado: alexvillegas.json
Archivo cargado: maria_garcia.json
Archivo cargado: juan_perez.json

Se cargaron 3 estudiante(s) exitosamente.

ESTUDIANTE #1
******************************************
*        INFORMACION ESTUDIANTE          *
******************************************
* Nombre:     Alex Villegas Carranza    *
* Ubicacion:  Costa Rica                *
* Profesion:  Software Engineer         *
******************************************
```