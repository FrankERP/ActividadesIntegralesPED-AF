//
//  Repeticion.h
//

#ifndef Repeticion_h
#define Repeticion_h

#include "Registro.h"

class Repeticion{
public:
    Repeticion();
    ~Repeticion();
    int repeticionNum;
    vector<Registro> ips;
    friend bool operator< (Repeticion &b1, Repeticion &b2);
    friend bool operator> (Repeticion &b1, Repeticion &b2);
    friend bool operator==(Repeticion &b1, Repeticion &b2);
    friend ostream& operator<<(ostream &strm, const Repeticion &b);
};

#endif /* Repeticion_h */