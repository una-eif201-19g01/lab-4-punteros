/*
 * =====================================================================================
 *
 *       Filename:  Empleado.h
 *
 *    Description:  Definición de la Clase Empleado
 *
 *        Created:  2019-08-22
 *
 *         Author:  Maikol Guzman Alan mikeguzman@gmail.com
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */


#ifndef EMPLEADOPUNTEROS_EMPLEADO_H
#define EMPLEADOPUNTEROS_EMPLEADO_H


#include <string>

const int NUMERO_MAXIMO = 100;

class Empleado {
protected:
    std::string nombre;
    int empleadoNumero;
    int anoExperiencia;
    float salarioBase;
    bool revision;

private:
    // El salario aumenta 2% cada año hasta los 3 años y despues aumenta 5% cada año
    float aumentarSalario(const int *);
    static void procesarRevision(bool *);

public:
    Empleado();

    Empleado(const std::string &nombre, int anoExperiencia, float salarioBase);

    std::string obtenerDatosEmpleado();

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    int getAnoExperiencia() const;

    void setAnoExperiencia(int anoExperiencia);

    float getSalarioBase() const;

    void setSalarioBase(float salarioBase);

    bool isRevision() const;

    void setRevision(bool revision);
};


#endif //EMPLEADOPUNTEROS_EMPLEADO_H
