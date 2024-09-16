#include "CAddress.h"
#include <iostream>
#include <string>
using namespace std;

CAddress::CAddress(int houseNumber,const string& streetName, const string& cityName)
    :houseNumber(houseNumber),streetName(streetName),cityName(cityName){}

CAddress::CAddress(const CAddress& other)
    : houseNumber(other.houseNumber), streetName(other.streetName), cityName(other.cityName){}


const string& CAddress::GetCityName() const {
    return cityName;
}

const string& CAddress::GetStreetName() const {
    return streetName;
}

int CAddress::GetHouseNumber() const {
    return houseNumber;
}

string CAddress::getCurrentAddress() const {
    string res = streetName + " "+cityName + " " +to_string(houseNumber);
        return res;
}



ostream& operator<<(ostream& os, const CAddress& adr){
  os << adr.streetName << "," << adr.houseNumber << ", " << adr.cityName << std::endl;

    return os;
}

istream& operator>> (istream& is, CAddress& adr) {

    is >> adr.houseNumber >> adr.streetName >> adr.cityName;

}

//const CAddress& CAddress::operator=(const CAddress& other) {
//
//    if (this != &other) {
//        houseNumber = other.houseNumber;
//        streetName = other.streetName;
//        cityName = other.cityName;
//
//    }
//
//    return *this;
//}
bool  CAddress::operator ==(const CAddress& other)const {
    return houseNumber == other.houseNumber && streetName == other.streetName && cityName == other.cityName;
}
bool CAddress::operator !=(const CAddress& other) const {
    return !(*this == other);
}
void CAddress::UpdateAddress(const string& newCity, const string& newStreet, int newHouseNum) {
    cityName = newCity;
    streetName = newStreet;
    houseNumber = newHouseNum;
}

CAddress::~CAddress(){}


