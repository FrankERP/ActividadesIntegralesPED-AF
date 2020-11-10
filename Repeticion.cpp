//
//  Repeticion.cpp
//

#include "Repeticion.h"

Repeticion::Repeticion(){}

Repeticion::~Repeticion(){}

bool operator<(Repeticion &b1, Repeticion &b2) {
    return b1.repeticionNum < b2.repeticionNum;
}

bool operator>(Repeticion &b1, Repeticion &b2) {
    return b1.repeticionNum > b2.repeticionNum;
}

bool operator==(Repeticion &b1, Repeticion &b2){
    return b1.repeticionNum == b2.repeticionNum;
}

ostream& operator<<(ostream &os, const Repeticion &b) {
    os << b.repeticionNum;
    return os;
}








