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


string CFlightInfo::GetDest() const {
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

bool CFlightInfo::IsEqual(const CFlightInfo& other) const {
    return this->flightNum == other.flightNum;
}

void CFlightInfo::Print() const {
    cout << "Destination: " << destination
        << ", Flight Number: " << flightNum
        << ", Flight Duration: " << flightDuration << " minutes"
        << ", Flight Distance: " << flightDistance << " km"
        << endl;
}

CFlightInfo::~CFlightInfo() {}
