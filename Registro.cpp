//
//  Registro.cpp
//

#include "Registro.h"

Registro::Registro(time_t fechaHora, string ip, string razon){
    this->fechaHora = fechaHora;
    this->ip = ip;
    this->razon = razon;
}

Registro::~Registro() {
}

void Registro::setFechaHora(time_t fh) {
    fechaHora = fh;
}

time_t Registro::getFechaHora() {
    return fechaHora;
}
string Registro::getFecha(){
    string anno, mes, dia;
    tm ts = *std::localtime(&fechaHora);
    std::stringstream fechaS;
    fechaS << std::put_time(&ts,"%F");
    getline(fechaS, anno, '-');
    getline(fechaS, mes, '-');
    getline(fechaS, dia);
    return anno + " " + mes + " " + dia;
}

void Registro::setIp(string ip) {
    this->ip = ip;
}

long Registro::getIpNum(){
    std::stringstream ipConvert;
    ipConvert.str(this->ip);
    string nums [4];
    getline(ipConvert, nums[3], '.');
    getline(ipConvert, nums[2], '.');
    getline(ipConvert, nums[1], '.');
    getline(ipConvert, nums[0], ':');
    long ipNum = 0;
    stringstream ss;
    for (int i = 0; i < sizeof(nums)/sizeof(string); i++){
        ipNum += stoi(nums[i])*pow(256,i);
    }
    return ipNum;
}

void Registro::setRazon(string razon) {
    this->razon = razon;
}

ostream& operator<<(ostream &os, const Registro &b) {
    tm ts = *std::localtime(&b.fechaHora);
    std::stringstream ss;
    //ss << put_time(&ts, L"%F %T");
    os << "fecha hora: " << b.fechaHora << " " << std::put_time(&ts,"%F %T") << " ip: " << b.ip << " razón: " << b.razon << " ";
    return os;
}

bool operator<(Registro &b1, Registro &b2) {
    return b1.getIpNum() < b2.getIpNum();
}

bool operator>(Registro &b1, Registro &b2) {
    return b1.getIpNum() > b2.getIpNum();
}

bool operator==(Registro &b1, Registro &b2){
    return b1.getIpNum() == b2.getIpNum();
}
