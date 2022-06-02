#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"


int archTxtFijoToBin(char* nombreArch)
{
    t_alumno alumno;
    char linea[76];
    FILE *pftxt, *pfbin;
    pftxt = fopen(nombreArch,"rt");
    if(!pftxt)
    {
        printf("no se pudo abrir el archivo de texto");
        return 0;
    }
    pfbin = fopen("ArchivoBin.dat","w+b");
    if(!pfbin)
    {
        fclose(pftxt);
        return 0;
    }

    while(fgets(linea,sizeof(linea),pftxt))
    {
        desglosamientoFijo(linea,&alumno);
        //printf("%d %s %s %.2f\n",alumno.dni,alumno.apellido,alumno.nombre,alumno.promedio);
        fwrite(&alumno,sizeof(t_alumno),1,pfbin);

    }

    ///mostrar el contenido del archivo binario

    fseek(pfbin,0l,SEEK_SET);
    fread(&alumno,sizeof(t_alumno),1,pfbin);
    while(!feof(pfbin))
    {
        printf("%d %s %s %f\n",alumno.dni,alumno.apellido,alumno.nombre,alumno.promedio);
        fread(&alumno,sizeof(t_alumno),1,pfbin);
    }

    fclose(pfbin);
    fclose(pftxt);
    return 1;
}

void desglosamientoFijo(char* linea,t_alumno* alumno)
{
    char *marcador;
    if((marcador=strrchr(linea,'\n')))
    {
        *marcador='\0';
    }
    linea+=strlen(linea);///me posiciono con el puntero al final de la cadena es decir en el '\0'
    linea-=5;///max caracteres 10.50
    sscanf(linea,"%f",&(alumno->promedio));
    *linea='\0';
    linea-=30;
    strcpy(alumno->nombre,linea);//no lleva el amperson porque el nombre es un puntero
    *linea='\0';
    linea-=30;
    strcpy(alumno->apellido,linea);
    *linea='\0';
    linea-=8;
    sscanf(linea,"%d",&(alumno->dni));//va con amperson porque el dni no es un puntero

}

int archTxtVarToBin(char* nombreArch)
{
    FILE *pftxt,*pfbin;
    char linea[76];
    t_alumno alumno;
    pftxt=fopen(nombreArch,"rt");
    if(!pftxt)
    {
        printf("error, no se pudo abrir el archivo de texto");
        return 0;
    }
    pfbin=fopen("archivoBinario.dat","w+b");
    if(!pfbin)
    {
        fclose(pftxt);
        return 0;
    }

    while(fgets(linea,sizeof(linea),pftxt))
    {
        desglosamientoVariable(linea,&alumno);
        fwrite(&alumno,sizeof(t_alumno),1,pfbin);
    }

    ///mostrar archivo binario
    fseek(pfbin,0l,SEEK_SET);
    fread(&alumno,sizeof(t_alumno),1,pfbin);
    while(!feof(pfbin))
    {
        printf("%d %s %s %f\n",alumno.dni,alumno.apellido,alumno.nombre,alumno.promedio);
        fread(&alumno,sizeof(t_alumno),1,pfbin);
    }

    fclose(pftxt);
    fclose(pfbin);
    return 1;

}
void desglosamientoVariable(char* linea, t_alumno* alum)
{
    char* marcador;
    if((marcador=strrchr(linea,'\n')))
    {
        *marcador='\0';
    }
    if((marcador=strrchr(linea,'|'))==NULL)
       return;
    sscanf(marcador+1,"%f",&(alum->promedio));
    *marcador='\0';
    if((marcador=strrchr(linea,'|'))==NULL)
        return;
    strcpy(alum->nombre,marcador+1);
    *marcador='\0';
    if((marcador=strrchr(linea,'|'))==NULL)
        return;
    strcpy(alum->apellido,marcador+1);
    *marcador='\0';
    sscanf(linea,"%d",&(alum->dni));

}
