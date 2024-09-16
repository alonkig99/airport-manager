#include "Flight.h"
#include "CFlightInfo.h"
#include <iostream>
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

 Flight operator+(const CCrewMember& newMember, const Flight& flight) {


}

 Flight operator+(const Flight& flight, const CCrewMember& newMember) {


}
ostream& operator<<(ostream& os, const Flight& flight) {
	// os << ............ implement printing .............. << endl;

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

