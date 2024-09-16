#pragma once
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include <string>
class Flight
{
public:
	Flight(CFlightInfo flightInfo, const CPlane* plane);
	Flight(const Flight& other);
	Flight() = delete;
	bool UpdatePlane(const CPlane* newPlane);
	// can be used as flight = flight + crewMember and flight = crewMember + flight
	friend Flight operator+(const CCrewMember& newMember, const Flight& flight);
	friend Flight operator+(const Flight& flight, const CCrewMember& newMember);
	friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
	// need to add a print function. 
	bool operator ==(const Flight& other)const;
	bool operator !=(const Flight& other)const;
	Flight& operator=(const Flight& other);
	bool exists(std::string memberName) const;

private:
	CFlightInfo flightInfo;
	const CPlane* plane;
	static const int MAX_CREW = 50;
	const CCrewMember* crewMembersArr[MAX_CREW];
	int crewMembersCount;
};


