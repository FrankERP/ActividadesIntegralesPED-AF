//
//  utilidades.h
//  

#ifndef utilidades_h
#define utilidades_h

#include <fstream>
#include <time.h>
#include <map>

#include "Registro.h"
#include "Arbol.cpp"
#include "Repeticion.h"

#define SEGUNDOS_DIA 86400

time_t obtenerTiempo(string dia, string mes, string anno, string hora);

Arbol<Repeticion> cargaBitacora(string archivo);

void buscarMostrarRegistros(vector<Registro> &bitacora, Registro registroInicio, Registro registroFin);

#endif /* utilidades_hpp */
