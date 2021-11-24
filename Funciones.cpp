#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include "Funciones.h"
#include "rlutil.h"

using namespace std;


void CargarMatriz(int Mat[][6],int Nfilas, int Ncolum){

srand(time(NULL));

for(int i=0;i<Nfilas;i++){
for(int j=0;j<Ncolum;j++){
Mat[i][j]=rand()%10;
}
}
}

/*-------------------------------------------------------*/

void MostarMatriz(int Mat[][6], int Nfilas, int Ncolum){
 cout << "   " << "1" << "   " << "2" << "   " << "3" << "  " << " 4" << "   " << "5" << "   " << "6" << endl << endl;
for(int i=0;i<Nfilas;i++){
cout << i+1 << "|" ;
for(int j=0;j<Ncolum;j++){
if(Mat[i][j]==99){
cout << " -  ";
}
else{
cout << " " << Mat[i][j] << "  ";
}
}
cout << "" << endl;
}
}

/*-------------------------------------------------------*/
void MostarLugar(int Mat[][6],int Fila , int Columna){
 cout << "   " << "1" << "   " << "2" << "   " << "3" << "  " << " 4" << "   " << "5" << "   " << "6" << endl << endl;
for(int i=0;i<6;i++){
cout << i+1 << "|" ;
for(int j=0;j<6;j++){
if(Mat[i][j]==99){
cout << " -  ";
}
else{
if(i==Fila-1&&j==Columna-1){
rlutil::setColor(rlutil::LIGHTGREEN);
cout << "|" << Mat[i][j] << "| ";
rlutil::setColor(rlutil::WHITE);
}
else{
cout << " " << Mat[i][j] << "  ";
}
}
}
cout << "" << endl;

}
}

/*-------------------------------------------------------*/

void Menu()
{
rlutil::cls();
cout << "MATHRIX" << endl;
cout << "------------------------" << endl;
cout << "1   -    Jugar" << endl;
cout << "2   -    Estadisticas" << endl;
cout << "3   -    Creditos" << endl;
cout << "------------------------" << endl;
cout << "0   -    Salir" << endl;
cout << "------------------------" << endl;
 }



void MenuOperaciones(){
cout << "------------------------" << endl;
cout << "Elija el operador matematico: " << endl << endl;
cout << "Suma" << "                +" <<  endl;
cout << "Resta" << "               -" << endl;
cout << "Multiplicacion" <<"      *" << endl;
cout << "Division(cociente)" << "  /" << endl;
cout << "Division(resto)" << "     %" << endl;
cout << "Su eleccion: ";
}


void MenuDireccion (){
cout << "------------------------" << endl;
cout << "Elija la direccion: " << endl << endl;
cout << "Arriba" << "      8" <<  endl;
cout << "Abajo" << "       2" << endl;
cout << "Izquierda" <<"   5" << endl;
cout << "Derecha" << "     6" << endl;
cout << "Su eleccion: ";
}

int NumElegido(int Mat[][6],int Fila , int Columna){
int NumElegido2;

for(int i=0;i<6;i++){
for(int j=0;j<6;j++){
if(i==Fila-1&&j==Columna-1){
NumElegido2=Mat[Fila-1][Columna-1];
}
}
}
return NumElegido2;



}

int Cuenta(int Mat[][6],int Fila, int Columna,char simbolo ,int pos){
int Resultado,Pun;
int c1=-1,c2=-1,c3=-1,f1=-1,f2=-1,f3=-1;
    if(pos==8){
        f2=-2;
        f3=-3;

    }
    if(pos==2){

        f2=0;
        f3=1;
    }
    if(pos==4){
        c2=-2;
        c3=-3;

    }
    if(pos==6){
        c2=0;
        c3=1;
    }
if(simbolo=='+'){
    Resultado=Mat[Fila+f1][Columna+c1]+Mat[Fila+f2][Columna+c2];
    Pun=Mat[Fila+f1][Columna+c1]+Mat[Fila+f2][Columna+c2]+Mat[Fila+f3][Columna+c3];
    if(Resultado==Mat[Fila+f3][Columna+c3]){
    return Pun;
    }
     else{
     return -1;
     }
    }//IF

    //-----------------------------------------------------
    if(simbolo=='-'){
   Resultado=Mat[Fila+f1][Columna+c1]-Mat[Fila+f2][Columna+c2];
    Pun=Mat[Fila+f1][Columna+c1]+Mat[Fila+f2][Columna+c2]+Mat[Fila+f3][Columna+c3];
    if(Resultado==Mat[Fila+f3][Columna+c3]){
    return Pun;
    }
     else{
     return -1;
     }
    }//IFF


    if(simbolo=='*'){
    Resultado=Mat[Fila+f1][Columna+c1]*Mat[Fila+f2][Columna+c2];
    Pun=Mat[Fila+f1][Columna+c1]+Mat[Fila+f2][Columna+c2]+Mat[Fila+f3][Columna+c3];
    if(Resultado==Mat[Fila+f3][Columna+c3]){
    return Pun;
    }
     else{
     return -1;
     }
    }//IF


    if(simbolo=='/'){
   Resultado=Mat[Fila+f1][Columna+c1]/Mat[Fila+f2][Columna+c2];
    Pun=Mat[Fila+f1][Columna+c1]+Mat[Fila+f2][Columna+c2]+Mat[Fila+f3][Columna+c3];
    if(Resultado==Mat[Fila+f3][Columna+c3]){
    return Pun;
    }
     else{
     return -1;
     }
    }//IF


    if(simbolo=='%'){
 Resultado=Mat[Fila+f1][Columna+c1]%Mat[Fila+f2][Columna+c2];
    Pun=Mat[Fila+f1][Columna+c1]+Mat[Fila+f2][Columna+c2]+Mat[Fila+f3][Columna+c3];
    if(Resultado==Mat[Fila+f3][Columna+c3]){
    return Pun;
    }
     else{
     return -1;
     }
    }//IF


}

void BorrarNum(int Mat[][6],int Fila, int Columna, int pos){

int c1=-1,c2=-1,c3=-1,f1=-1,f2=-1,f3=-1;
    if(pos==8){
        f2=-2;
        f3=-3;
        Mat[Fila+f1][Columna+c1]=99;
        Mat[Fila+f2][Columna+c1]=99;
        Mat[Fila+f3][Columna+c1]=99;
    }
    if(pos==2){
        f1=-1;
        f2=0;
        f3=1;
        Mat[Fila+f1][Columna+c1]=99;
        Mat[Fila+f2][Columna+c1]=99;
        Mat[Fila+f3][Columna+c1]=99;
    }
    if(pos==4){
        c2=-2;
        c3=-3;
        Mat[Fila+f1][Columna+c1]=99;
        Mat[Fila+f2][Columna+c2]=99;
        Mat[Fila+f3][Columna+c3]=99;

    }
    if(pos==6){
        c1=-1;
        c2=0;
        c3=1;
        Mat[Fila+f1][Columna+c1]=99;
        Mat[Fila+f2][Columna+c2]=99;
        Mat[Fila+f3][Columna+c3]=99;
    }

}

int Prohibido(int Mat[][6],int Fila, int Columna, int pos){
    int c1=-1,c2=-1,c3=-1,f1=-1,f2=-1,f3=-1;

    if(pos==8){
        f2=-2;
        f3=-3;

    }
    if(pos==2){
        f1=-1;
        f2=0;
        f3=1;

    }
    if(pos==4){
        c2=-2;
        c3=-3;


    }
    if(pos==6){
        c1=-1;
        c2=0;
        c3=1;

    }


if(Mat[Fila+f1][Columna+c1]==99||Mat[Fila+f2][Columna+c2]==99||Mat[Fila+f3][Columna+c3]==99){
return 0;
}
else{
return 1;
}
}

int FueraMatriz(int Fila, int Columna, int pos){
    int c1=-1,c2=-1,c3=-1,f1=-1,f2=-1,f3=-1;
    if(pos==8){
      if(Fila-1==1||Fila-1==0){
       return 0;
      }
      else{
      return 1;
      }

    }
    if(pos==2){
      if(Fila-1==4||Fila-1==5){
       return 0;
      }
      else{
      return 1;
      }
    }
    if(pos==4){
     if(Columna-1==0||Columna-1==1){
     return 0;
     }
     else {
     return 1;
     }
    }
    if(pos==6){
    if(Columna-1==4||Columna-1==5){
       return 0;
     }
     else {
     return 1;
     }
    }


    }

int ReiniciaMatriz (int Fila,int Columna){
if(Fila==0&Columna==0){
return 0;
}
else{
return 1;
}
}
