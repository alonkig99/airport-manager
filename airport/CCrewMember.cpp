#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>

using namespace std;

CCrewMember::CCrewMember(const string& name, const CAddress& address, int totalAirTime)
	:name(name),address(address),totalAirTime(totalAirTime) {}

CCrewMember::CCrewMember(const CCrewMember& other)
    : name(other.name), address(other.address), totalAirTime(other.totalAirTime){}


bool CCrewMember::UpdateMinutes(int newMinutes) {
    if (newMinutes <= 0) return false;
   totalAirTime += newMinutes;
    return true;
}
std::string CCrewMember::GetName()const {
    return name;
}

void CCrewMember::SetName(const string& newName) {
    name = newName;
}

CAddress CCrewMember::GetAddress()const {
    return address;
}

void CCrewMember::SetAddress(const CAddress& newAddress) {
    address = newAddress;
}

int CCrewMember::GetAirTime()const {
    return totalAirTime;
}

void CCrewMember::Print()const {
    cout << "Crewmember: " << name << endl;
    cout << "Address: ";
    address.Print(); 
    cout << "Total Air Time: " << totalAirTime << " minutes" << endl;
}


bool CCrewMember::IsEqual(const CCrewMember& other) const{
    return this->name == other.name;
}

CCrewMember::~CCrewMember(){}

