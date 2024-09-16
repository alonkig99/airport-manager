#pragma once
#include <string>
#include "CPlane.h"
#include "CCrewMember.h"
#include "Flight.h"
class CFlightCompany
{
public:
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other);
	CFlightCompany() = delete;

	const std::string& GetName()const;
	void SetName(std::string newName);
	// void Print()const; REPLACE WITH OSTREAM OP
	~CFlightCompany();
	bool addCrewMember(const CCrewMember& newMember); 
	bool addPlane(const CPlane& newPlane);
	bool addFlight(const Flight& newFlight);
	CPlane* getPlaneByIndex(int index);
	bool addCrewMemberToFlight(int flightNum, int memberID);
	Flight getFlightByNumber(int flightNum);
	CCrewMember getMemberByID(int memberID);

private:
	std::string name;
	static const int MAX_CREWS = 50;
	static const int MAX_PLANES = 50;
	static const int MAX_FLIGHT = 50;
	CPlane planesArr[MAX_PLANES];
	CCrewMember membersArr[MAX_CREWS];
	Flight flightsArr[MAX_FLIGHT];
	int planesCount;
	int memberCount;
	int flightsCount;
};

