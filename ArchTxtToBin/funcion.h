#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

typedef struct
{
    int dni;
    char apellido[35];
    char nombre[35];
    float promedio;

}t_alumno;

int archTxtFijoToBin(char* nombreArch);
int archTxtVarToBin(char* nombreArch);
void desglosamientoVariable(char* linea, t_alumno* alum);
void desglosamientoFijo(char* linea,t_alumno* alumno);


#endif // FUNCION_H_INCLUDED
