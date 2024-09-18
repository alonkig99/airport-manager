#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>

using namespace std;

int CCrewMember::idCounter = START_ID;

CCrewMember::CCrewMember(const string& name, int totalAirTime)
	:memberID(idCounter++),name(name), totalAirTime(totalAirTime) {}

CCrewMember::CCrewMember(const CCrewMember& other)
    :memberID(other.memberID), name(other.name),totalAirTime(other.totalAirTime) {}




//+= operator updates total air time
bool CCrewMember::operator+=(int minutes) {
    if (minutes > 0) {
        totalAirTime += minutes;
        return true;
    }
    return false;
}
const string& CCrewMember::GetName()const {
    return name;
}
int CCrewMember::GetID()const {
    return memberID;
}
void CCrewMember::SetName(const string& newName) {
    name = newName;
}

//const CAddress& CCrewMember::GetAddress()const {
//    return address;
//}

//void CCrewMember::SetAddress(const CAddress& newAddress) {
//    address = newAddress;
//}

int CCrewMember::GetAirTime()const {
    return totalAirTime;
}

ostream& operator<<(ostream& os, const CCrewMember& member) {
    os << "name:" << member.name 
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

