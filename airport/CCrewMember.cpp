#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>

using namespace std;

int CCrewMember::idCounter = START_ID;

/* =====================================
   constructors&destructor
   ===================================== */

CCrewMember::CCrewMember(const string& name, int totalAirTime, const CAddress* address)
	:memberID(idCounter++),name(name), totalAirTime(totalAirTime) {

    SetAddress(address);

}

CCrewMember::CCrewMember(const CCrewMember& other) {
    *this = other;
}
CCrewMember::~CCrewMember() {
    delete address;
}


/* =====================================
   getters&setters
   ===================================== */

const string& CCrewMember::GetName()const {
    return name;
}
int CCrewMember::GetID()const {
    return memberID;
}
void CCrewMember::SetName(const string& newName) {
    name = newName;
}

const CAddress* CCrewMember::GetAddress()const {
    return address;
}

void CCrewMember::SetAddress(const CAddress* newAddress) {

    if (newAddress != nullptr) {
        if (address != newAddress) { //self address assignment check
            delete address;
            address = new CAddress(*newAddress);
        }
    }
}

int CCrewMember::GetAirTime()const {
    return totalAirTime;
}


/* =====================================
   operator overloading
   ===================================== */

bool CCrewMember::operator+=(int minutes) {
    if (minutes > 0) {
        totalAirTime += minutes;
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const CCrewMember& member) {
    os << "Crewmember: " << member.name << ", total airtime: " << member.totalAirTime << endl;
    return os;
}
bool CCrewMember::operator==(const CCrewMember& other) const {
    return memberID == other.memberID;

}
bool CCrewMember::operator!=(const CCrewMember& other) const {
    return !(*this == other);
}

const CCrewMember& CCrewMember::operator=(const CCrewMember& other) {

    if (this != &other) {
        SetAddress(other.GetAddress());
        SetName(other.name);
        this->memberID =other.memberID;
        this->totalAirTime = other.totalAirTime;
    }
    return *this;
}


