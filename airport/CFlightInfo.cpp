#include "CFlightInfo.h"
#include <string>
#include <iostream>

using namespace std;


CFlightInfo::CFlightInfo(const string& destination, int flightNum, int flightDuration, int flightDistance)
    : destination(destination), flightNum(flightNum), flightDuration(flightDuration), flightDistance(flightDistance)
{}


CFlightInfo::CFlightInfo(const CFlightInfo& other)
    : destination(other.destination), flightNum(other.flightNum), flightDuration(other.flightDuration), flightDistance(other.flightDistance)
{}


const string& CFlightInfo::GetDest() const {
    return destination;
}

void CFlightInfo::SetDest(const string& newDest) {
    destination = newDest;
}

int CFlightInfo::GetFlightNum() const {
    return flightNum;
}

void CFlightInfo::SetFlightNum(int newFlightNum) {
    flightNum = newFlightNum;
}

int CFlightInfo::GetFlightDuration() const {
    return flightDuration;
}

void CFlightInfo::SetFlightDuration(int newFlightDur) {
    flightDuration = newFlightDur;
}

int CFlightInfo::GetFlightDistance() const {
    return flightDistance;
}

void CFlightInfo::SetFlightDistance(int newFlightDist) {
    flightDistance = newFlightDist;
}


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
CFlightInfo::~CFlightInfo() {}
