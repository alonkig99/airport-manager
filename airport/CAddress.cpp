#include "CAddress.h"
#include <iostream>
#include <string>

using namespace std;

/* =====================================
   constructors&destructor
   ===================================== */

CAddress::CAddress(int houseNumber,const string& streetName, const string& cityName)
    :houseNumber(houseNumber),streetName(streetName),cityName(cityName){}

CAddress::CAddress(const CAddress& other){
    *this = other;
}

CAddress::~CAddress() {}

/* =====================================
   getters&setters
   ===================================== */

void CAddress::SetCityName(const string& cityName) {
    this->cityName = cityName;
}

void CAddress::SetStreetName(const string& streetName) {
    this->streetName = streetName;
}
void CAddress::SetHouseNumber(int houseNumber) {
    this->houseNumber = houseNumber;
}
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

/* =====================================
   operator overloading
   ===================================== */

ostream& operator<<(ostream& os, const CAddress& adr){
  os << adr.streetName << "," << adr.houseNumber << ", " << adr.cityName << endl;

    return os;
}


istream& operator>>(istream& in, CAddress& cAddress)
{
    cout << "Please enter house number street name and city name:" << endl;
    in >> cAddress.houseNumber >> cAddress.streetName >> cAddress.cityName;
    return in;
}


const CAddress& CAddress::operator=(const CAddress& other) {

    if (this != &other) {
        UpdateAddress(other.cityName,other.streetName, other.houseNumber);
    }

    return *this;
}
bool  CAddress::operator ==(const CAddress& other)const {
    return houseNumber == other.houseNumber && streetName == other.streetName && cityName == other.cityName;
}
bool CAddress::operator !=(const CAddress& other) const {
    return !(*this == other);
}

/* =====================================
   other methods
   ===================================== */
void CAddress::UpdateAddress(const string& newCity, const string& newStreet, int newHouseNum) {

    SetCityName(newCity);
    SetStreetName(newStreet);
    SetHouseNumber(newHouseNum);
}




