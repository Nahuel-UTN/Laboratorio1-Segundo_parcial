#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include "Funciones.h"
#endif // FUNCIONES_H_INCLUDED

using namespace std;

void CargarMatriz (int[][6], int , int);
void MostarMatriz  (int[][6], int, int);
char CargarNombre (char[], int);
void MostarLugar (int[][6],int, int);
void MoverMatriz (int[][6],int,int);
void Menu();
void MenuOperaciones();
void MenuDireccion ();
int NumElegido(int [][6], int, int);
int Cuenta (int Mat[][6], int , int, char, int);
void BorrarNum (int Mat[][6],int,int,int);
int Prohibido (int Mat[][6],int,int,int);
int FueraMatriz (int,int,int);
int ReiniciaMatriz (int,int);
