//
//  Registro.h
//

#ifndef Registro_h
#define Registro_h

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Registro {
    
private:
    time_t fechaHora;
    string ip;
    string razon;
    
public:
    Registro(time_t fechaHora, string ip, string razon);
    
    void setFechaHora(time_t fh);
    void setIp(string ip);
    long getIpNum();
    void setRazon(string razon);
    
    time_t getFechaHora();
    string getFecha();
    
    friend ostream& operator<<(ostream &strm, const Registro &b);
    friend bool operator< (Registro &b1, Registro &b2);
    friend bool operator> (Registro &b1, Registro &b2);
    friend bool operator==(Registro &b1, Registro &b2);
    ~Registro();
    
};

#endif /* Registro_hpp */
