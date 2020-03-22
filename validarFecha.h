#ifndef VALIDARFECHA_H_INCLUDED
#define VALIDARFECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

bool esBisiesto(fecha pDato){

    int aux;
    if((pDato.anio % 4 == 0 && pDato.anio % 100 != 0) || pDato.anio % 400 == 0){
        aux = validamosMesBisiesto(pDato.dia, pDato.mes);
        return true;
    }else{
        aux = validamosMes(pDato.dia,pDato.mes);
        return false;
    }
}

int validamosMesBisiesto(int pDia, int pMes){

        int cantDias = NULL;

    switch(pMes){
        case 1 :
            cantDias = 31;
            break;
        case 2 :
            cantDias = 29;
            break;
        case 3 :
            cantDias = 31;
            break;
        case 4 :
            cantDias = 30;
            break;
        case 5 :
            cantDias = 31;
            break;
        case 6 :
            cantDias = 30;
            break;
        case 7 :
            cantDias = 31;
            break;
        case 8 :
            cantDias = 31;
            break;
        case 9 :
            cantDias = 30;
            break;
        case 10 :
            cantDias = 31;
            break;
        case 11 :
            cantDias = 30;
            break;
        case 12 :
            cantDias = 31;
            break;
        default :
            printf("\n  No se ha introducido un Mes v%clido.",160);
    }

    return cantDias;
}

int validamosMes(int pDia, int pMes){

    int cantDias = NULL;

    switch(pMes){
        case 1 :
            cantDias = 31;
            break;
        case 2 :
            cantDias = 28;
            break;
        case 3 :
            cantDias = 31;
            break;
        case 4 :
            cantDias = 30;
            break;
        case 5 :
            cantDias = 31;
            break;
        case 6 :
            cantDias = 30;
            break;
        case 7 :
            cantDias = 31;
            break;
        case 8 :
            cantDias = 31;
            break;
        case 9 :
            cantDias = 30;
            break;
        case 10 :
            cantDias = 31;
            break;
        case 11 :
            cantDias = 30;
            break;
        case 12 :
            cantDias = 31;
            break;
        default :
            printf("\n  No se ha introducido un Mes v%clido.",162);
    }

    return cantDias;
}

#endif // VALIDARFECHA_H_INCLUDED
