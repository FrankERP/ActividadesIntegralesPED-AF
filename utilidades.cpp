//
//  utilidades.cpp
//

#include "utilidades.h"

time_t obtenerTiempo(string dia, string mes, string anno, string hora){
    tm ts;
    //memset(&ts, 0, sizeof(struct tm));
    ts.tm_isdst = 1;
    string tss = anno + " " + mes + " " + dia + " " + hora;
    strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
    //ts.tm_year = 119;
    time_t fechaHora = mktime(&ts);
    return fechaHora;
}

Arbol<Repeticion> cargaBitacora(string archivo){
    Arbol<Repeticion> bitacora;
    vector<Repeticion> repeticiones;
    Registro ipAnterior(0, "", "");

    int count = 0;
    
    ifstream f;
    string mes, dia, tiempo;
    
    f.open(archivo);
    for(int i = 0; i < 500; i++) {
    //while(!f.eof()) {
        getline(f, mes, ' ');
        getline(f, dia, ' ');
        getline(f, tiempo, ' ');
        time_t fechaHora = obtenerTiempo(dia, mes, "2019", tiempo);
        string ip;
        getline(f, ip, ' ');
        string razon;
        getline(f, razon);
        Registro ipActual(fechaHora, ip, razon);

        if (ipAnterior == ipActual){
            count++;
        }else if (ipAnterior.getFechaHora() == 0) {
            ipAnterior = ipActual;
            cout << ipAnterior << endl;
        }else{
            ipAnterior = ipActual;
            bool encontrado = false;
            int count2 = 0;
            while ( repeticiones.at(count2).repeticionNum != count && count2 < repeticiones.size()){
                count2++;
            }
            if (count2 == repeticiones.size()){
                Repeticion rep;
                rep.ips.push_back(ipActual);
                rep.repeticionNum = count;
                repeticiones.push_back(rep);
            }else{
                repeticiones.at(count2).ips.push_back(ipActual);
            }
            count = 0;
        }
    }

    for (auto rep : repeticiones){
        bitacora.add(rep);
    }

    return bitacora;
}

void buscarMostrarRegistros(vector<Registro> &bitacora, Registro registroInicio, Registro registroFin){
    
}
