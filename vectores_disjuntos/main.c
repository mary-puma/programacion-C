#include <stdio.h>
#include <stdlib.h>
#include "funcion_vector.h"
#define TAM1 5
#define TAM2 3
int main()
{
    int vector1[TAM1]= {-1,2,3,4,5};
    int vector2[TAM2]= {-2,0,5};

    if(vectorDisjunto(vector1,vector2,TAM1,TAM2))
    {
        printf("Los vectores son disjuntos");

    }
    else
    {
        printf("Los vectores no son disjuntos");
    }

    return 0;
}
