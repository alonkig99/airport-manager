#include "CFlightCompany.h"
#include "CFlight.h"
#include "CCrewMember.h"
#include "CPlane.h"
#include <string>
#include <iostream>

using namespace std;

/* =====================================
   constructors&destructor
   ===================================== */
CFlightCompany::CFlightCompany(const string& name):name(name),planesCount(0),membersCount(0),flightsCount(0) {}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
	: name(other.name), membersCount(other.membersCount),
	flightsCount(other.flightsCount), planesCount(other.planesCount) {
	for (int i = 0; i < membersCount; i++) {
		membersArr[i] = new CCrewMember(*other.membersArr[i]);
	}
	for (int i = 0; i < flightsCount; i++) {
		flightsArr[i] = new CFlight(*other.flightsArr[i]);
	}
	for (int i = 0; i < planesCount; i++) {
		planesArr[i] = new CPlane(*other.planesArr[i]);
	}
}

CFlightCompany::~CFlightCompany() {
	for (int i = 0; i < membersCount; i++)
		delete membersArr[i];

	for (int i = 0; i < flightsCount; i++)
		delete flightsArr[i];

	for (int i = 0; i < planesCount; i++)
		delete planesArr[i];

}

/* =====================================
   getters&setters
   ===================================== */


const CPlane* CFlightCompany::GetPlane(int index) const {
	if (index < 0 || index >= planesCount) return nullptr;
	return planesArr[index];

}

const string& CFlightCompany::GetName()const {
	return name;
}

void CFlightCompany::SetName(string newName) {
	name = newName;
}

/* =====================================
   operator overloading
   ===================================== */

ostream& operator<<(ostream& os, const CFlightCompany& flightCompany) {
    os << "Flight company: " << flightCompany.name << endl
        << "There are " << flightCompany.membersCount << " Crew members: " << endl;

    for (int i = 0; i < flightCompany.membersCount; i++) {
        os << *flightCompany.membersArr[i];
    }

    os << "There are " << flightCompany.planesCount << " Planes: " << endl;
    for (int i = 0; i < flightCompany.planesCount; i++) {
        os << *flightCompany.planesArr[i]; 
    }

    os << "There are " << flightCompany.flightsCount << " Flights: " << endl;
    for (int i = 0; i < flightCompany.flightsCount; i++) {
        os << *flightCompany.flightsArr[i]; 
    }

    return os; 
}

const CFlightCompany& CFlightCompany::operator=(const CFlightCompany& other) {
	if (this != &other) {

		for (int i = 0; i < membersCount; i++) {delete membersArr[i];}
		for (int i = 0; i < flightsCount; i++) {delete flightsArr[i];}
		for (int i = 0; i < planesCount; i++) {delete planesArr[i];}

		name = other.name;
		membersCount = other.membersCount;
		flightsCount = other.flightsCount;
		planesCount = other.planesCount;

		for (int i = 0; i < membersCount; i++) {membersArr[i] = new CCrewMember(*other.membersArr[i]);}
		for (int i = 0; i < flightsCount; i++) {flightsArr[i] = new CFlight(*other.flightsArr[i]);}
		for (int i = 0; i < planesCount; i++) {planesArr[i] = new CPlane(*other.planesArr[i]);}
	}

	return *this;
}

/* =====================================
   other methods
   ===================================== */
CFlight* CFlightCompany::getFlightByNum(int num)const {
	for (int i = 0; i < flightsCount; i++){
		if (flightsArr[i]->GetFlightInfo().GetFNum() == num)
			return flightsArr[i];
	}
	return nullptr;

}

CCrewMember* CFlightCompany::getMemberByID(int id)const {
	for (int i = 0; i < membersCount; i++) {
		if (membersArr[i]->GetID() == id) {
			return membersArr[i];
		}
	 }
	return nullptr;
}

void CFlightCompany::AddCrewToFlight(int flightNum, int memberID) {
	*getFlightByNum(flightNum) = *getFlightByNum(flightNum) + *getMemberByID(memberID);

}


bool CFlightCompany::AddCrewMember(const CCrewMember& newMember) {
	if (membersCount >= MAX_CREWS) return false;

	for (int i = 0; i < membersCount; i++)
		if (*membersArr[i] == newMember) return false; // == compares crewMembers by memberID.

	membersArr[membersCount] = new CCrewMember(newMember);
	membersCount++;
	return true;

}
bool CFlightCompany::AddPlane(const CPlane& newPlane) {

	if (planesCount >= MAX_PLANES) return false;

	for (int i = 0; i < planesCount; i++)
		if (*planesArr[i] == newPlane) return false; // == compares planes by serialNumber.

	planesArr[planesCount] = new CPlane(newPlane);
	planesCount++;
	return true;

}
bool CFlightCompany::AddFlight(const CFlight& newFlight) {

	if (flightsCount >= MAX_FLIGHT) return false;

	for (int i = 0; i < flightsCount; i++)
		if (*flightsArr[i] == newFlight) return false; // == compares flights by flightInfo.

	flightsArr[flightsCount] = new CFlight(newFlight);
	flightsCount++;
	return true;

}