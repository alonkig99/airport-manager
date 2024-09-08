#include "CAddress.h"
#include <iostream>
#include <string>
using namespace std;

CAddress::CAddress(int houseNumber,const string& streetName, const string& cityName)
    :houseNumber(houseNumber),streetName(streetName),cityName(cityName){}

CAddress::CAddress(const CAddress& other)
    : houseNumber(other.houseNumber), streetName(other.streetName), cityName(other.cityName){}


std::string CAddress::GetCityName() const {
    return cityName;
}

std::string CAddress::GetStreetName() const {
    return streetName;
}

int CAddress::GetHouseNumber() const {
    return houseNumber;
}

void CAddress::Print() const {
    std::cout  << streetName <<" "<< houseNumber <<", "<< cityName << std::endl;
}

void CAddress::UpdateAddress(const string& newCity, const string& newStreet, int newHouseNum) {
    cityName = newCity;
    streetName = newStreet;
    houseNumber = newHouseNum;
}

CAddress::~CAddress(){}


