#include "CFlight.h"
#include "CFlightInfo.h"
#include "CPilot.h"
#include "CHost.h"
#include "CCargo.h"
#include <iostream>
#include <string>
using namespace std;

/* =====================================
   constructors&destructor
   ===================================== */

CFlight::CFlight(CFlightInfo flightInfo, CPlane* plane):flightInfo(flightInfo), plane(plane), crewMembersCount(0){
	for (int i = 0; i < MAX_CREW; i++) 
		crewMembersArr[i] = nullptr;
}

CFlight::CFlight(const CFlight& other) :flightInfo(other.flightInfo), plane(other.plane), crewMembersCount(other.crewMembersCount) {
	for (int i = 0; i < MAX_CREW; i++)
		crewMembersArr[i] = nullptr;

	for (int i = 0; i < crewMembersCount; i++)
		crewMembersArr[i] = other.crewMembersArr[i];
}

CFlight::~CFlight() {}


/* =====================================
   getters&setters
   ===================================== */

void CFlight::SetPlane(CPlane* newPlane) {
	plane = newPlane;

}
const CFlightInfo& CFlight::GetFlightInfo() {
	return flightInfo;

}


/* =====================================
   operator overloading
   ===================================== */

 CFlight operator+(CCrewMember* newMember, CFlight& flight) {

	 return flight +newMember;
}


 CFlight operator+(CFlight& flight,CCrewMember* newMember) {

	 if (flight.crewMembersCount >= CFlight::MAX_CREW)
		 return flight;

	 for (int i = 0; i < flight.crewMembersCount; i++)
	 {
		 if (flight.crewMembersArr[i] == newMember)
			 return flight;
	 }

	 flight.crewMembersArr[flight.crewMembersCount++] = newMember;
	 return flight;

}
ostream& operator<<(ostream& os, const CFlight& flight) {

	os << "Flight Info: " << flight.flightInfo << endl;

	
	if (flight.plane) {
		os  << *flight.plane << endl;
	}
	else {
		os << "Plane: None" << endl;
	}

	os << "There are "<<  flight.crewMembersCount <<" crew members in flight:"<<endl;
	if (flight.crewMembersCount > 0) {
		for (int i = 0; i < flight.crewMembersCount; ++i) {
			os << *flight.crewMembersArr[i]; 
		
		}
	}
	else {
		os << "None";
	}
	os << endl;

	return os;

}

bool CFlight::operator ==(const CFlight& other)const {
	return flightInfo == other.flightInfo;
}

bool CFlight::operator !=(const CFlight& other)const {
	return !(*this == other);
}



const CFlight& CFlight::operator=(const CFlight& other) {
	if (this != &other) {

		flightInfo = other.flightInfo;
		plane = other.plane;
		crewMembersCount = other.crewMembersCount;

		for (int i = 0; i < MAX_CREW; i++)
			crewMembersArr[i] = nullptr;

		for (int i = 0; i < MAX_CREW; i++) {
			crewMembersArr[i] = other.crewMembersArr[i]; 
		}
	}
	return *this;
}

/* =====================================
   *
   ===================================== */

bool CFlight::exists(string memberName) const {
	for (int i = 0; i < crewMembersCount; i++) {
		if (crewMembersArr[i]->GetName() == memberName) return true;
	}
	return false;
}



bool CFlight::VerifyPlane() const {
	CHost* host = nullptr;
	int isOnePilot = 0, isSuperHost = 0;

	for (int i = 0; i < crewMembersCount; i++)
	{
		if (typeid(*crewMembersArr[i]) == typeid(CPilot))
		{
			if (isOnePilot == 1)
				return false;
			isOnePilot = 1;
		}
		else
		{
			host = dynamic_cast<CHost*>(crewMembersArr[i]);
			if (host && host->GetHostType() == CHost::eSuper)
			{
				if (isSuperHost == 1)
					return false;
				isSuperHost = 1;
			}
		}
	}
	return isOnePilot == 1;
}

bool CFlight::VerifyCargo() const {
	for (int i = 0; i < crewMembersCount; i++)
	{
		if (typeid(*crewMembersArr[i]) == typeid(CPilot))
			return true;
	}

	return false;
}



bool CFlight::TakeOff()
{
	int minutes = flightInfo.GetFDuration();

	if (!this->plane|| (typeid(*this->plane) == typeid(CPlane) && !VerifyPlane()) ||
		(typeid(*this->plane) == typeid(CCargo) && !VerifyCargo()))
		return false;

	for (int i = 0; i < crewMembersCount; i++)
		crewMembersArr[i]->TakeOff(minutes);

	this->plane->TakeOff(minutes);

	return true;
}