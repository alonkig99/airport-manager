#include "Flight.h"
#include "CFlightInfo.h"
#include <iostream>
#include <string>
using namespace std;
Flight::Flight(CFlightInfo flightInfo, const CPlane* plane):flightInfo(flightInfo), plane(plane), crewMembersCount(0){
	for (int i = 0; i < MAX_CREW; i++) 
		crewMembersArr[i] = nullptr;
	

}

Flight::Flight(const Flight& other):flightInfo(other.flightInfo),plane(other.plane), crewMembersCount(other.crewMembersCount) {
	for (int i = 0; i < MAX_CREW; i++) 
		crewMembersArr[i] = nullptr;
	
	for (int i = 0; i < crewMembersCount; i++) 
	 crewMembersArr[i] = other.crewMembersArr[i];

}
bool Flight::exists(string memberName) const {
	for (int i = 0; i < crewMembersCount; i++) {
		if (crewMembersArr[i]->GetName() == memberName) return true;
	}
	return false;
}
 Flight operator+(const CCrewMember& newMember, const Flight& flight) {
	 Flight flt(flight);
	 if (flt.crewMembersCount < flt.MAX_CREW && !flt.exists(newMember.GetName())) {
		 flt.crewMembersArr[flt.crewMembersCount++] = &newMember;
	
	 }
	 return flt;
}

 Flight operator+(const Flight& flight, const CCrewMember& newMember) {
	 return newMember + flight;

}
ostream& operator<<(ostream& os, const Flight& flight) {
	// Print flight info
	os << "Flight Info: " << flight.flightInfo << endl;

	// Print plane info if a plane is assigned
	if (flight.plane) {
		os << "Assigned Plane: " << *flight.plane << endl; // Dereference plane pointer to print the plane
	}
	else {
		os << "Assigned Plane: None" << endl;
	}

	// Print crew members
	os << "Crew Members: ";
	if (flight.crewMembersCount > 0) {
		for (int i = 0; i < flight.crewMembersCount; ++i) {
			os << flight.crewMembersArr[i]->GetName(); // Access name of each crew member
			if (i < flight.crewMembersCount - 1) {
				os << ", "; // Add a comma between names
			}
		}
	}
	else {
		os << "None";
	}
	os << endl;

	return os;

}

bool Flight::operator ==(const Flight& other)const {
	return flightInfo == other.flightInfo;
}

bool Flight::operator !=(const Flight& other)const {
	return !(*this == other);
}

bool Flight::UpdatePlane(const CPlane* newPlane) {
	plane = newPlane;
	return true;
}


//Flight& Flight::operator=(const Flight& other) {
//	if (this != &other) {
//		flightInfo = other.flightInfo;
//		plane = other.plane;
//		crewMembersCount = other.crewMembersCount;
//
//		for (int i = 0; i < MAX_CREW; i++) {
//			crewMembersArr[i] = other.crewMembersArr[i]; // Copy pointers
//		}
//	}
//	return *this;
//}
