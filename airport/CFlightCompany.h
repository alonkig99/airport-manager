#pragma once
#include <string>
#include "CPlane.h"
#include "CCrewMember.h"
#include "CFlight.h"
#include <ostream>
class CFlightCompany
{
public:
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other);
	CFlightCompany() = delete;

	const std::string& GetName()const;
	void SetName(std::string newName);
	friend std::ostream& operator<<(std::ostream& os, const CFlightCompany& flightCompany);
	~CFlightCompany();
	bool AddCrewMember(const CCrewMember& newMember); 
	bool AddPlane(const CPlane& newPlane);
	bool AddFlight(const CFlight& newFlight);
	const CPlane* GetPlane(int index)const;
	void AddCrewToFlight(int flightNum, int memberID);
	const CFlightCompany& operator=(const CFlightCompany& other);

	

private:
	std::string name;
	static constexpr int MAX_CREWS = 50;
	static constexpr int MAX_PLANES = 50;
	static constexpr int MAX_FLIGHT = 50;
	CPlane* planesArr[MAX_PLANES];
	CCrewMember* membersArr[MAX_CREWS];
	CFlight* flightsArr[MAX_FLIGHT];
	int planesCount=0;
	int membersCount=0;
	int flightsCount=0;
	// internal helper functions:
	 CFlight* getFlightByNum(int num)const;
	 CCrewMember* getMemberByID(int id)const;

};

