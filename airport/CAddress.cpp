#include "CAddress.h"
#include <iostream>
#include <string>
using namespace std;

CAddress::CAddress(int houseNumber,const string& streetName, const string& cityName) {
	this->houseNumber = houseNumber;
	this->streetName = streetName;
	this->cityName = cityName;
}

CAddress::CAddress(const CAddress& other)
{
    this->houseNumber = other.houseNumber;
    this->streetName = other.streetName;
    this->cityName = other.cityName;
}

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
    this->cityName = newCity;
    this->streetName = newStreet;
    this->houseNumber = newHouseNum;
}

CAddress::~CAddress(){}


