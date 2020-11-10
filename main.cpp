//
//  main.cpp
//  Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
//
//  Autores: 
//  Raúl Navarro Guevara                A01652351
//  Santiago Orozco Quintero            A01658308     
//  Francisco Emiliano Rocha Pineda     A01652082
//  Pedro Murillo Ángeles               A01652052
//
//  Fecha:  13 de noviembre de 2020
//  

#include "utilidades.h"

int main() {    
    const string ARCHIVO = "bitacoraOrdenada.txt";
    
    Arbol<Repeticion> bitacora = cargaBitacora(ARCHIVO);

    bitacora.levelByLevel();

    return 0;
}