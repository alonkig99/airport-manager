#include "CCrewMember.h"
#include "CAddress.h"
#include <string>
#include <iostream>

using namespace std;


/* =====================================
   constructors&destructor
   ===================================== */

CCrewMember::CCrewMember(const string& name, int totalAirTime)
	: name(name), totalAirTime(totalAirTime) {}

CCrewMember::CCrewMember(const CCrewMember& other) {
    *this = other;
}
CCrewMember::~CCrewMember() {}

/* =====================================
   getters&setters
   ===================================== */

const string& CCrewMember::GetName()const {
    return name;
}

void CCrewMember::SetName(const string& newName) {
    name = newName;
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
    os << typeid(member).name() + 7 << " ";
    member.ToOs(os);
    return os;
}
bool CCrewMember::operator==(const CCrewMember& other) const {
  
    return name == other.name;

}
bool CCrewMember::operator!=(const CCrewMember& other) const {
    return !(*this == other);
}

const CCrewMember& CCrewMember::operator=(const CCrewMember& other) {

    if (this != &other) {
        SetName(other.name);
        this->totalAirTime = other.totalAirTime;
    }
    return *this;
}

////////////////////////

void CCrewMember::GetPresent() const
{
    cout << name << " thanking the company for receiving the holiday gift" << endl;
}

void CCrewMember::TakeOff(int minutes) {

    totalAirTime += minutes;
}

