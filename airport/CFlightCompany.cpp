#include "CFlightCompany.h"
#include "CFlight.h"
#include "CCrewMember.h"
#include "CHost.h"
#include "CPilot.h"
#include "CPlane.h"
#include "CCargo.h"
#include <string>
#include <iostream>

using namespace std;

/* =====================================
   constructors&destructor
   ===================================== */
CFlightCompany::CFlightCompany(const string& name):name(name),planesCount(0),membersCount(0),flightsCount(0) {}

CFlightCompany::CFlightCompany(const CFlightCompany& other){}

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


 CPlane* CFlightCompany::GetPlane(int index) const {
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

		for (int i = 0; i < membersCount; i++) {
			const CPilot* cPilot = dynamic_cast<const CPilot*>(other.membersArr[i]);
			const CHost* cHost = dynamic_cast<const CHost*>(other.membersArr[i]);

			if (cPilot)
			membersArr[i] = new CPilot(*cPilot);
			if (cHost)
				membersArr[i] = new CHost(*cHost);
		}

		for (int i = 0; i < planesCount; i++) {
			const CCargo* cCargo = dynamic_cast<const CCargo*>(other.planesArr[i]);

			if (cCargo)
				planesArr[i] = new CCargo(*cCargo);
			else
			planesArr[i] = new CPlane(*other.planesArr[i]);

		
		}



		for (int i = 0; i < flightsCount; i++) { flightsArr[i] = new CFlight(*other.flightsArr[i]); }
	}

	return *this;
}

/* =====================================
   other methods
   ===================================== */
CFlight* CFlightCompany::GetFlightByNum(int num)const {
	for (int i = 0; i < flightsCount; i++){
		if (flightsArr[i]->GetFlightInfo().GetFNum() == num)
			return flightsArr[i];
	}
	return nullptr;

}


CCrewMember* CFlightCompany::GetCrewMember(int index) {
	if (index >= membersCount)
		return nullptr;
	return membersArr[index];
}


void CFlightCompany::AddCrewToFlight(int flightNum, int memberIndex) {
	*GetFlightByNum(flightNum) = *GetFlightByNum(flightNum) + GetCrewMember(memberIndex);

}


bool CFlightCompany::AddCrewMember(const CCrewMember& newMember) {

	const CPilot* cPilot = dynamic_cast<const CPilot*>(&newMember);
	const CHost* cHost = dynamic_cast<const CHost*>(&newMember);

	if (this->membersCount >= MAX_CREWS)
		return false;

	for (int i = 0; i < membersCount; i++) {
		if (*membersArr[i] == newMember)
			return false;
	}
	
	if (cPilot)
		 membersArr[membersCount++] = new CPilot(*cPilot);
	else if (cHost)
		membersArr[membersCount++] = new CHost(*cHost);

	return true;


}
bool CFlightCompany::AddPlane(const CPlane& newPlane) {

	const CCargo* cCargo = dynamic_cast<const CCargo*>(&newPlane);

	if (planesCount >= MAX_PLANES)
		return false;

	for (int i = 0; i < planesCount; i++)
	{
		if (*planesArr[i]==newPlane)
			return false;
	}

	if (cCargo)
		this->planesArr[planesCount++] = new CCargo(*cCargo);
	else
		this->planesArr[planesCount++] = new CPlane(newPlane);

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



//////////////////////////
int CFlightCompany::GetCargoCount() const {
	int count=0;
	for (int i = 0; i < flightsCount; i++) {
		if (typeid(*planesArr[i]) == typeid(CCargo)) {
			count++;
		}
	}
	return count;

}



void CFlightCompany::CrewGetPresent() const {
	for (int i = 0; i < membersCount; i++) {
		membersArr[i]->GetPresent();
	}
}
void CFlightCompany::PilotsToSimulator() const {
	for (int i = 0; i < membersCount; i++) {
		CPilot* temp = dynamic_cast<CPilot*>(membersArr[i]);
		if (temp)
			temp->ToSimulator();

	}
}
void CFlightCompany::CrewGetUniform() const {
	for (int i = 0; i < membersCount; i++) {
		membersArr[i]->GetUniform();
	}
}


bool CFlightCompany::TakeOff(int flightNum) const {
	return GetFlightByNum(flightNum)->TakeOff();
}