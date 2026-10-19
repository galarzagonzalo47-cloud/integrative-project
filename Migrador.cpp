#include <iostream>
#include <fstream>
#include "Migrador.h"
#include "SociosArchivo.h"
#include "Socios.h"

void exportarSociosACSV() {
    SociosArchivo archivo;
    int total = archivo.getCantidadRegistros();

    // Creamos el archivo CSV en la carpeta de tu proyecto
    std::ofstream csv("Socios_export.csv");

    if (!csv.is_open()) { // Verificamos si el archivo se abrió correctamente
        std::cout << "Error al crear el archivo CSV." << std::endl;
        return;
    }

    // 1. Escribimos la cabecera con los nombres de las columnas
    csv << "NumSocio,Dni,Nombre,Apellido,Telefono,Email,FechaNacimiento,Estado\n";

    // 2. Leemos del .dat usando tu método .leer(i) y escribimos cada fila en el CSV
    for (int i = 0; i < total; i++) {
        Socios reg = archivo.leer(i); // <--- Acá lo llamás como lo tenés implementado

        csv << reg.getNumSocio() << ","
            << reg.getDni() << ","
            << "\"" << reg.getNombre() << "\","
            << "\"" << reg.getApellido() << "\","
            << "\"" << reg.getTelefono() << "\","
            << "\"" << reg.getEmail() << "\","
            << "\"" << reg.getFechaNacimiento().getDia() << "/" << reg.getFechaNacimiento().getMes() << "/" << reg.getFechaNacimiento().getAnio() << "\","
            << (reg.getEstado() ? 1 : 0) << "\n";
            // Nota: Se usan comillas para los campos de texto para manejar correctamente los caracteres especiales y las comas dentro de los datos.
    }

    csv.close();
    std::cout << "Exportado con éxito a 'Socios_export.csv'" << std::endl;
}