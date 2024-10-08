#include "CFlightInfo.h"
#include <string>
#include <iostream>

using namespace std;

/* =====================================
   constructors&destructor
   ===================================== */

CFlightInfo::CFlightInfo(const string& destination, int flightNum, int flightDuration, int flightDistance)
    : destination(destination), flightNum(flightNum),  flightDuration(flightDuration), flightDistance(flightDistance) {}


CFlightInfo::CFlightInfo(const CFlightInfo& other) {
    *this = other;
}

CFlightInfo::~CFlightInfo() {}


/* =====================================
   getters&setters
   ===================================== */

const string& CFlightInfo::GetDest() const {
    return destination;
}

void CFlightInfo::SetDest(const string& newDest) {
    destination = newDest;
}

int CFlightInfo::GetFNum() const {
    return flightNum;
}

void CFlightInfo::SetFNum(int newFlightNum) {
    flightNum = newFlightNum;
}

int CFlightInfo::GetFDuration() const {
    return flightDuration;
}

void CFlightInfo::SetFDuration(int newFlightDur) {
    flightDuration = newFlightDur;
}

int CFlightInfo::GetFDistance() const {
    return flightDistance;
}

void CFlightInfo::SetFDistance(int newFlightDist) {
    flightDistance = newFlightDist;
}

/* =====================================
   operator overloading
   ===================================== */

CFlightInfo::operator int() const { return flightDuration; }

ostream& operator<<(ostream & os, const CFlightInfo& flightInfo) {
    os << "Destination: " << flightInfo.destination
        << ",  Number: " << flightInfo.flightNum
        << ", Duration: " << flightInfo.flightDuration << " minutes"
        << ",  Distance: " << flightInfo.flightDistance << " km"
        << endl;

    return os;
}
bool CFlightInfo::operator==(const CFlightInfo& other)const {
    return flightNum == other.flightNum;
}
bool CFlightInfo::operator!=(const CFlightInfo& other)const {
    return !(*this == other);

}

const CFlightInfo& CFlightInfo::operator=(const CFlightInfo& other) {

    if (this != &other) {
        SetDest(other.destination);
        SetFNum(other.flightNum);
        SetFDuration(other.flightDuration);
        SetFDistance(other.flightDistance);   
    }
    return *this;
}

