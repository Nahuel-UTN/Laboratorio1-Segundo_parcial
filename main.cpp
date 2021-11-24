#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "Funciones.h"
#include "rlutil.h"

using namespace std;


int main(){

 rlutil::setBackgroundColor(rlutil::BLUE);
char Ecu;
int Nfilas=6,Ncolum=6,Opc=1,Fila,Columna,Direccion,FilaNum,tot, salir,Max=0,Cal,Mal,Errado;
int Mat [6][6],Pilas,Puntaje=0,Pun,Resultado,pos0;
string jugador, Ganador;


for(int z=0;z<=1;z++){
Pilas=3;
Menu();
cin >> Opc;
cout << endl << endl;

switch(Opc){

case 1:
    cout << "Ingrese nombre del jugador" << endl;
    cin >> jugador;
    cout << endl <<"Ingrese calculadora preferida: " << endl << endl;
    cout << "Casio: 1" << endl << endl;
    cout << "Cualquier otra: 2" << endl;
    cin >> Cal;
    rlutil::cls();
    break;
case 2:
    cout << "Puntaje Maximo: " << Max << endl;
    cout << "El vicio: " << Ganador << endl << endl;
    break;
case 3:
    rlutil::setColor(rlutil::BROWN);
    cout << "Equipo Namek"  << endl << endl;
    cout << "Creado y Dirigido por: Nahuel Saucedo!" << endl << endl;
    cout << "Legajo: " << "18835" << endl << endl;
    break;
case 0:
    cout << "Esta seguro que desea salir?"<< endl;
    cout << "1   -   SALIR" << endl;
    cout << "0   -   NO SALIR" << endl;
    cin >> salir;
    if(salir==1){
        cout << "GRACIAS POR JUGAR!";
        return 0;
                }
    else{}
}
    // CIERRE DE SWITCH

if(Opc==1){
cout << "------------------------" << endl;

CargarMatriz(Mat,Nfilas,Ncolum);
while(Pilas!=0){
pos0=1;
MostarMatriz(Mat,Nfilas,Ncolum);

cout << endl << "PUNTAJE : " << Puntaje << endl << endl;
cout << endl  << "CANTIDAD DE PILAS " << Pilas << endl << endl;


cout << "------------------------" << endl;
cout << endl << "Eliga las cordenadas!" << endl;
cout << "Fila: ";
cin >> Fila;
if(Fila>6||Fila<0){
Pilas--;
}
while(Fila>6||Fila<0){
cout << "Fila fuera del rango de la matriz, Pierde una vida :(" << endl;
cout << "PILAS: " << Pilas << endl;
cout << "Fila: ";
cin >> Fila;
if(Fila>6||Fila<0){
Pilas--;
}
if(Pilas==0){
cout << "GAME OVER" << endl;
return 0;
}

}
cout << "Columna: ";
cin >> Columna;
if(Columna>6||Columna<0){
Pilas--;
}
while(Columna>6||Columna<0){
cout << "Columna fuera del rango de la matriz, pierde una vida" << endl;
cout << "PILAS: " << Pilas << endl;
cout << "Columna: ";
cin >> Columna;
if(Columna>6||Columna<0){
Pilas--;
}
if(Pilas==0){
cout << "GAME OVER" << endl;
return 0;
}
}
cout << "------------------------" << endl;




pos0=ReiniciaMatriz(Fila,Columna);
if(pos0==0&&Pilas>0){
while(Pilas!=0&&pos0==0){
Pilas--;
if(Pilas>0){
cout << endl << "NO SE PUEDE REALIZAR, PIERDE UNA PILA!!!" << endl << endl << endl;
cout << "SE VUELVE A GENERAR OTRA MATRIZ ALEATORIA!" << endl << endl;
cout << endl << "PUNTAJE : " << Puntaje << endl << endl;
cout << endl  << "CANTIDAD DE PILAS " << Pilas << endl << endl;
CargarMatriz(Mat,Nfilas,Ncolum);
MostarMatriz(Mat,Nfilas,Ncolum);
cout << "------------------------" << endl;
cout << endl << "Eliga las cordenadas!" << endl;
cout << "Fila: ";
cin >> Fila;
if(Fila>6||Fila<0){
Pilas--;
}
while(Fila>6||Fila<0){
cout << "Fila fuera del rango de la matriz, Pierde una vida :(" << endl;
cout << "PILAS: " << Pilas << endl;
cout << "Fila: ";
cin >> Fila;
if(Fila>6||Fila<0){
Pilas--;
}
if(Pilas==0){
cout << "GAME OVER" << endl;
return 0;
}

}
cout << "Columna: ";
cin >> Columna;
if(Columna>6||Columna<0){
Pilas--;
}
while(Columna>6||Columna<0){
cout << "Columna fuera del rango de la matriz, pierde una vida" << endl;
cout << "PILAS: " << Pilas << endl;
cout << "Columna: ";
cin >> Columna;
if(Columna>6||Columna<0){
Pilas--;
}
if(Pilas==0){
cout << "GAME OVER" << endl;
return 0;
}
}
//cout << "Columna: ";
//cin >> Columna;
while(Columna>6||Columna<0){
cout << "Columna fuera del rango de la matriz" << endl;
cout << "Columna: ";
cin >> Columna;}
cout << "------------------------" << endl;
pos0=ReiniciaMatriz(Fila,Columna);
}
}
}
if(Pilas>0){



MostarLugar (Mat,Fila,Columna);

MenuOperaciones();

cin >> Ecu;

cout << "------------------------" << endl;
cout << "Elija la direccion: " << endl << endl;
cout << "Arriba" << "      8" <<  endl;
cout << "Abajo" << "       2" << endl;
cout << "Izquierda" <<"   4" << endl;
cout << "Derecha" << "     6" << endl;
cin >> Direccion;


//Num0=NumElegido(Mat,Fila,Columna);

/*case 8:
Num1=Mat[Fila-2][Columna-1];
Num2=Mat[Fila-3][Columna-1];
break;*/

Mal=Prohibido(Mat,Fila,Columna,Direccion);
Errado=FueraMatriz(Fila,Columna,Direccion);



if(Mal==0||Errado==0){
cout << endl << "NO SE PUEDE REALIZAR, PIERDE UNA PILA!!!" << endl << endl << endl;
Pilas--;
}


if(Mal==1&&Errado==1){
switch(Direccion){
   case 8:
      Resultado = Cuenta(Mat, Fila, Columna,Ecu, Direccion);
if (Resultado!=-1){
Puntaje+=Resultado;

}
else{
Pilas--;
}

break;
   case 2:
       Resultado = Cuenta(Mat, Fila, Columna,Ecu, Direccion);
if (Resultado!=-1){
Puntaje+=Resultado;
}
else{
Pilas--;
}
    break;
    Resultado = Cuenta(Mat, Fila, Columna,Ecu, Direccion);
if (Resultado!=-1){
Puntaje+=Resultado;
}
else{
Pilas--;
}
   case 4:
       Resultado = Cuenta(Mat, Fila, Columna,Ecu, Direccion);
if (Resultado!=-1){
Puntaje+=Resultado;
}
else{
Pilas--;
}
    break;
   case 6:
       Resultado = Cuenta(Mat, Fila, Columna,Ecu, Direccion);
if (Resultado!=-1){
Puntaje+=Resultado;
}
else{
Pilas--;
}
    break;
}



BorrarNum(Mat,Fila,Columna,Direccion);

}
}
}
}

if(Pilas==0){
cout << endl << "PUNTAJE : " << Puntaje << endl << endl;
cout << endl  << "CANTIDAD DE PILAS " << Pilas << endl << endl;
rlutil::setColor(rlutil::RED);
cout << "GAME OVER" << endl;
}
rlutil::setColor(rlutil::WHITE);

cout << "------------------------" << endl;
cout << "Desea jugar otra vez: " << endl;
cout << "Si = 0" << endl;
cout << "No = 1" << endl;
cin >> z;
cout << endl << endl;
Max=Puntaje;
Ganador=jugador;
if(Puntaje>Max){
Max=Puntaje;
Ganador=jugador;
}

}
 cout << "GRACIAS POR JUGAR!" << endl;;
 if(Puntaje==0){
 cout << "LE RECOMIENDO CURSAR MATEMATICA 1" << endl;
 }
return 0;
}


