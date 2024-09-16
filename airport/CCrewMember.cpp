#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>

using namespace std;

int CCrewMember::idCounter = 1000;

CCrewMember::CCrewMember(const string& name, const CAddress& address, int totalAirTime)
	:memberID(idCounter++),name(name),address(address),totalAirTime(totalAirTime) {}

CCrewMember::CCrewMember(const CCrewMember& other)
    :memberID(other.memberID), name(other.name), address(other.address), totalAirTime(other.totalAirTime){}




//+= operator updates total air time
const CCrewMember& CCrewMember::operator+=(int minutes) {
    if (minutes > 0) 
        totalAirTime += minutes;
    
    return *this;
}
const std::string& CCrewMember::GetName()const {
    return name;
}

void CCrewMember::SetName(const string& newName) {
    name = newName;
}

const CAddress& CCrewMember::GetAddress()const {
    return address;
}

void CCrewMember::SetAddress(const CAddress& newAddress) {
    address = newAddress;
}

int CCrewMember::GetAirTime()const {
    return totalAirTime;
}

ostream& operator<<(ostream& os, const CCrewMember& member) {
    os << "Member ID" << member.memberID << ", name:" << member.name 
        << ", total airtime:" << member.totalAirTime << endl;

        return os;
}
bool CCrewMember::operator==(const CCrewMember& other) const {
    return memberID == other.memberID;

}
bool CCrewMember::operator!=(const CCrewMember& other) const {
    return !(*this == other);
}
CCrewMember::~CCrewMember(){}

