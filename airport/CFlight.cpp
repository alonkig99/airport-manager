#include "CFlight.h"
#include "CFlightInfo.h"
#include <iostream>
#include <string>
using namespace std;
CFlight::CFlight(CFlightInfo flightInfo, const CPlane* plane):flightInfo(flightInfo), plane(plane), crewMembersCount(0){
	for (int i = 0; i < MAX_CREW; i++) 
		crewMembersArr[i] = nullptr;
	

}


CFlight::CFlight(const CFlight& other) :flightInfo(other.flightInfo), plane(other.plane), crewMembersCount(other.crewMembersCount) {
	for (int i = 0; i < MAX_CREW; i++)
		crewMembersArr[i] = nullptr;

	for (int i = 0; i < crewMembersCount; i++)
		crewMembersArr[i] = other.crewMembersArr[i];

}

bool CFlight::exists(string memberName) const {
	for (int i = 0; i < crewMembersCount; i++) {
		if (crewMembersArr[i]->GetName() == memberName) return true;
	}
	return false;
}

 CFlight operator+(const CCrewMember& newMember, const CFlight& flight) {
	 CFlight flt(flight);
	 if (flt.crewMembersCount < flt.MAX_CREW && !flt.exists(newMember.GetName())) {
		 flt.crewMembersArr[flt.crewMembersCount++] = &newMember;
	
	 }
	 return flt;
}

 CFlight operator+(const CFlight& flight, const CCrewMember& newMember) {
	 return newMember + flight;

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

void CFlight::SetPlane(const CPlane* newPlane) {
	plane = newPlane;
	
}
const CFlightInfo& CFlight::GetFlightInfo() {
	return flightInfo;

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


CFlight::~CFlight() {}
