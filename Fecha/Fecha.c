#include "Fecha.h"

booleano esBisiesto(int anio);
int cantDiasMes(int mes, int anio);

int esFechaValida(Fecha fecha)
{
    if(fecha.anio>ANIO_BASE)
    {
        if(fecha.mes >= 1 && fecha.mes<= 12 )
        {
            if(fecha.dia >= 1 && fecha.dia<= cantDiasMes(fecha.mes,fecha.anio))
            {
                return VERDADERO;
            }
        }
    }
    return FALSO;

}
///Para saber si es bisiesto un año no alcanza con que sea multiplo de 4
/// los años multiplos de 100 no son bisiesto pero se da que el año multiplo de 400 si es bisiesto

booleano esBisiesto(int anio)
{
    return (anio%4 == 0 && anio%100 !=0) || anio%400 ==0;
}

int cantDiasMes(int mes, int anio)
{
    int diasMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes == 2 && esBisiesto(anio))
    {
        return 29;
    }
    return diasMes[mes];
}
