#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

int main()
{
    Fecha fecha;
    printf("ingrese fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);
    while(!esFechaValida(fecha))
    {
        printf("ingrese fecha (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);
    }

    printf("la fecha ingresada es %d/%d/%d\n", fecha.dia,fecha.mes,fecha.anio);

    return 0;
}
