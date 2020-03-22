#include <math.h>
#include <string.h>
#include "validarFecha.h"
#define SIGLO 100
void sumarDia(fecha pDato);
int intervaloMesesBisiesto(int pMes);
int intervaloMeses(int pMes);
int intervaloSiglos(int pAnio);
void intervaloDias(int pCodDia);
void calculoDeLaFecha(int pCodMes, int pCodAnio, fecha pDato);

int main()
{
    bool returnBool;
    fecha dato;
    int codigoMes, codigoAnio;

    printf("\n  Ingrese D%ca: ",161);
    scanf("%i",&dato.dia);
    printf("\n  Ingrese Mes: ");
    scanf("%i", &dato.mes);
    printf("\n  Ingrese A%co: ",164);
    scanf("%i",&dato.anio);

    returnBool = esBisiesto(dato);
    if(returnBool == true){
        printf("\n  El a%co es bisiesto.",164);
        printf("\n  La cantidad de dias del mes es %d", validamosMesBisiesto(dato.dia,dato.mes));
        codigoMes = intervaloMesesBisiesto(dato.mes);
    }else{
        printf("\n  El a%co no es bisiesto.",164);
        printf("\n  La cantidad de dias del mes es %d", validamosMes(dato.dia,dato.mes));
        codigoMes = intervaloMeses(dato.mes);
    }

    sumarDia(dato);

    printf("\n  Fin del proceso de Suma de un dia a la fecha.");
    printf("\n  ------------------------------- \n");
    printf("\n  Inicio del proceso de mostrar Dia exacto de una cierta fecha.");

    codigoAnio = intervaloSiglos(dato.anio);

    calculoDeLaFecha(codigoMes,codigoAnio,dato);

    return 0;
}

///////////////////////////////////////////////

void sumarDia(fecha pDato){

    int returnMonth;
    bool returnBool;

    returnBool = esBisiesto(pDato);
    if(returnBool == true){
        returnMonth = validamosMesBisiesto(pDato.dia,pDato.mes);
    }else{
        returnMonth = validamosMes(pDato.dia, pDato.mes);
    }

    if (pDato.dia == returnMonth){

        pDato.dia = 1;

        if(pDato.mes == 12){
                pDato.mes=1;
                pDato.anio+=1;
        }else {
            pDato.mes += 1;
        }
    }else {
        pDato.dia+=1;
    }
    printf("\n  La fecha del d%ca siguiente es %i/%i/%i", 161, pDato.dia, pDato.mes, pDato.anio);
}

///////////////////////////////////////
void intervaloDias(int pCodDia){

    char* diaSemana;

    switch(pCodDia){
    case 1 :
        diaSemana = "Lunes";
        break;
    case 2 :
        diaSemana = "Martes";
        break;
    case 3 :
        diaSemana = "Miercoles";
        break;
    case 4 :
        diaSemana = "Jueves";
        break;
    case 5 :
        diaSemana = "Viernes";
        break;
    case 6 :
        diaSemana = "Sabado";
        break;
    case 0 :
        diaSemana = "Domingo";
        break;
    }

    printf("\n  El d%ca exacto de la fecha introducida es %s.\n\n", 161, diaSemana);
}

///////////////////////////////////////////////////
int intervaloMesesBisiesto(int pMes){

    int returnMonth;
    switch(pMes){
       case 1 :
            returnMonth = 0;
            break;
        case 2 :
            returnMonth = 3;
            break;
        case 3 :
            returnMonth = 4;
            break;
        case 4 :
            returnMonth = 0;
            break;
        case 5 :
            returnMonth = 2;
            break;
        case 6 :
            returnMonth = 5;
            break;
        case 7 :
            returnMonth = 0;
            break;
        case 8 :
            returnMonth = 3;
            break;
        case 9 :
            returnMonth = 6;
            break;
        case 10 :
            returnMonth = 1;
            break;
        case 11 :
            returnMonth = 4;
            break;
        case 12 :
            returnMonth = 6;
            break;
    }
    return returnMonth;
}
/////////////////////////////////////////////////////////
int intervaloMeses(int pMes){

    int returnMonth;

    switch(pMes){
        case 1 :
            returnMonth = 0;
            break;
        case 2 :
            returnMonth = 3;
            break;
        case 3 :
            returnMonth = 3;
            break;
        case 4 :
            returnMonth = 6;
            break;
        case 5 :
            returnMonth = 1;
            break;
        case 6 :
            returnMonth = 4;
            break;
        case 7 :
            returnMonth = 6;
            break;
        case 8 :
            returnMonth = 2;
            break;
        case 9 :
            returnMonth = 5;
            break;
        case 10 :
            returnMonth = 0;
            break;
        case 11 :
            returnMonth = 3;
            break;
        case 12 :
            returnMonth = 5;
            break;
    }
    return returnMonth;
}

/////////////////////////////////////////////////////////
int intervaloSiglos(int pAnio){

    int gregorianCalendarInicial = 1600;
    int rangoMax = 99;
    int intervSiglo = 6;
    int flag = NULL;

    int gregorianCalendarFinal = gregorianCalendarInicial + rangoMax;

    while(flag == 0){

        if(pAnio >= gregorianCalendarInicial && pAnio <= gregorianCalendarFinal ){
            flag = 1;
        }else{
            gregorianCalendarInicial += SIGLO;
            gregorianCalendarFinal = gregorianCalendarInicial + rangoMax;
            intervSiglo -= 2;

            if(intervSiglo < 0){
                intervSiglo = 6;
            }
        }
    }
    return intervSiglo;
}
///////////////////////////////////////////////////////////
void calculoDeLaFecha(int pCodMes, int pCodAnio, fecha pDato){

    int ultimosDosNroAnio;
    float divisionRedondeoAbajo;
    int suma;
    int resultado;

    ultimosDosNroAnio = ((pDato.anio % 1000) % 100);
    divisionRedondeoAbajo = floor(ultimosDosNroAnio / 4);

    suma = pDato.dia + pCodMes + ultimosDosNroAnio + divisionRedondeoAbajo + pCodAnio;
    resultado = suma % 7;

    intervaloDias(resultado);
}


