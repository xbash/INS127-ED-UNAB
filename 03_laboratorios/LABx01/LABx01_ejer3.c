#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
ASIGNATURA: INS127 Estructura de datos, Seccion 652 (Laboratorio)
DOCENTE: TOMAS LARA VALDOVINOS
ALUMNO: Jorge Sepulveda S.
FECHA: 23/03/2017
ACTIVIDAD: LABORATORIO 1, EJERCICIO 3
*/

int main(){

int dia,mes,ano,dia_mes;
//se solicita ingresar mes de nacimiento validando este
    do{
    printf("Favor ingrese el mes de su nacimiento. Este debe ser un mes v\240lido: ");
    scanf("%d",&mes);
    }while(mes<1 || mes>12);

    dia_mes=dia_meses(mes);

//se solicita ingresar dia de nacimiento validando este
    do{
    printf("Favor ingrese el d\241a de su nacimiento. Este debe ser un d\241a v\240lido seg\243n mes: ");
    scanf("%d",&dia);
    }while(dia>dia_mes);

//se solicita ingresar año de nacimiento validando este
    do{
    printf("Favor ingrese el ano de su nacimiento. Este debe ser un ano v\240lido: ");
    scanf("%d",&ano);
    }while(ano<=0);
    printf("\n");
    printf("Tu fecha de nacimiento es (DD/MM/AA): %d/%d/%d",dia,mes,ano);
    sumadatos(dia,mes,ano);
}
//funcion para saber la cantidad de dias por mes
int dia_meses(int mes){
int Enero=31,Febrero=28,Marzo=31,Abril=30,Mayo=31,Junio=30,Julio=31,Agosto=31,Septiembre=30,Octubre=31,Noviembre=30,Diciembre=31;
if(mes==1){
    mes=Enero;
}
if(mes==2){
    mes=Febrero;
}
if(mes==3){
    mes=Marzo;
}
if(mes==4){
    mes=Abril;
}
if(mes==5){
    mes=Mayo;
}
if(mes==6){
    mes=Junio;
}
if(mes==7){
    mes=Julio;
}
if(mes==8){
    mes=Agosto;
}
if(mes==9){
    mes=Septiembre;
}
if(mes==10){
    mes=Octubre;
}
if(mes==11){
    mes=Noviembre;
}
if(mes==12){
    mes=Diciembre;
}
return mes;
}

//funcion para buscar número mágico
int sumadatos(int dia, int mes, int ano){
    int suma_dia,suma_mes,sumaMDA,numero_magico,suma_total;
    int D_dia,U_dia,D_mes,U_mes, M_sumaMDA,C_sumaMDA,D_sumaMDA,U_sumaMDA,M_suma_total,C_suma_total,D_suma_total,U_suma_total;
    //separar decena y unidad del dia y sumarlas
    D_dia = dia/10;
    U_dia = dia-(D_dia*10);
    suma_dia = D_dia + U_dia;
    //separar decena y unidad del mes y sumarlas
    D_mes = mes/10;
    U_mes = mes-(D_mes*10);
    suma_mes = D_mes + U_mes;

    //suma unidades y decenas del mes y día mas el año
    sumaMDA=suma_dia+suma_mes+ano;

    //separar en millares, centenas, decenas y unidades el numero sumaMDA
    M_sumaMDA = sumaMDA/1000;
                C_sumaMDA = (sumaMDA-(M_sumaMDA*1000))/100;
                D_sumaMDA = (sumaMDA- (M_sumaMDA*1000 + C_sumaMDA*100))/10;
    U_sumaMDA = sumaMDA-(M_sumaMDA*1000 + C_sumaMDA*100 + D_sumaMDA*10 );
    suma_total=M_sumaMDA+C_sumaMDA+D_sumaMDA+U_sumaMDA;

    //sacar el numero magico
    M_suma_total = suma_total/1000;
                C_suma_total = (suma_total-(M_suma_total*1000))/100;
                D_suma_total = (suma_total- (M_suma_total*1000 + C_suma_total*100))/10;
    U_suma_total = suma_total-(M_suma_total*1000 + C_suma_total*100 + D_suma_total*10 );
    numero_magico = M_suma_total+C_suma_total+D_suma_total+U_suma_total;

    //mostrar por pantalla numero mágico
    printf("\n");
    printf("Tu n\243mero m\240gico es: %d \n",numero_magico);


}
