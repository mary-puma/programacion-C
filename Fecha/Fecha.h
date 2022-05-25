#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#define VERDADERO 1
#define FALSO     0
#define ANIO_BASE 1601
typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef int booleano;
booleano esFechaValida(Fecha fecha);

#endif // FECHA_H_INCLUDED
