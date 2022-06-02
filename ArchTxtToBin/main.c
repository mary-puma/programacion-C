#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    if(!archTxtFijoToBin("archivoDeTextoF.txt"))
   {
       printf(" no se pudo abrir el archivo");
       return 1;
   }
   if(!archTxtVarToBin("archivoDeTextoV.txt"))
   {
       printf(" no se pudo abrir el archivo");
       return 1;
   }

    return 0;
}
