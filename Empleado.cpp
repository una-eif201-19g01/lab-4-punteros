//
// Created by Maikol Guzman  on 2019-08-22.
//

#include "Empleado.h"

Empleado::Empleado() {
    empleadoNumero = std::rand() % NUMERO_MAXIMO;
}

Empleado::Empleado(const std::string &nombre, int anoExperiencia, float salarioBase) : nombre(nombre),
                                                                                   anoExperiencia(anoExperiencia),
                                                                                   salarioBase(salarioBase) {
    empleadoNumero = std::rand() % NUMERO_MAXIMO;
}

void Empleado::procesarRevision(bool *revison) {
    if (rand() % 2 == 0) {
        *revison = true;
    } else {
        *revison = false;
    }
}

float Empleado::aumentarSalario(const int *anoExpe) {
    float salarioAcumulado = salarioBase;
    if (*anoExpe > 0) {
        for (int ano = 1; ano <= *anoExpe; ++ano) {
            if (ano < 3) {
                salarioAcumulado += salarioAcumulado * float(0.02);
            } else {
                salarioAcumulado += salarioAcumulado * float(0.05);
            }
        }
    }
    return salarioAcumulado;
}

std::string Empleado::obtenerDatosEmpleado() {
    std::string datosEmpleado;
    float salarioAcumulado = aumentarSalario(&anoExperiencia);
    procesarRevision(&revision);
    std::string resultadoRevision;

    if (revision) {
        resultadoRevision = "Si";
    } else {
        resultadoRevision = "No";
    }

    datosEmpleado = "Empleado # [ " + std::to_string (empleadoNumero) + " ]\n\tNombre [ " + getNombre()
            + " ]\n\tAños de experiencia [ " + std::to_string(getAnoExperiencia()) + " ]\n\tSalario Inicial [ "
            + std::to_string(getSalarioBase()) + " ]\n\tSalario Acumulado [ " + std::to_string(salarioAcumulado)
            + " ]\n\tNecesita revision [ " +  resultadoRevision + " ]\n";

    return datosEmpleado;
}

const std::string &Empleado::getNombre() const {
    return nombre;
}

void Empleado::setNombre(const std::string &nombre) {
    Empleado::nombre = nombre;
}

int Empleado::getAnoExperiencia() const {
    return anoExperiencia;
}

void Empleado::setAnoExperiencia(int anoExperiencia) {
    Empleado::anoExperiencia = anoExperiencia;
}

float Empleado::getSalarioBase() const {
    return salarioBase;
}

void Empleado::setSalarioBase(float salarioBase) {
    Empleado::salarioBase = salarioBase;
}

bool Empleado::isRevision() const {
    return revision;
}

void Empleado::setRevision(bool revision) {
    Empleado::revision = revision;
}

