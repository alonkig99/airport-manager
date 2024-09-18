#pragma once
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include <string>
class CFlight
{
public:
	CFlight(CFlightInfo flightInfo, const CPlane* plane= nullptr);
	CFlight(const CFlight& other);
	CFlight() = delete;
	void SetPlane(const CPlane* newPlane);
	const CFlightInfo& GetFlightInfo();
	// can be used as flight = flight + crewMember and flight = crewMember + flight
	friend CFlight operator+(const CCrewMember& newMember, const CFlight& flight);
	friend CFlight operator+(const CFlight& flight, const CCrewMember& newMember);
	friend std::ostream& operator<<(std::ostream& os, const CFlight& flight);
	bool operator ==(const CFlight& other)const;
	bool operator !=(const CFlight& other)const;
	//CFlight& operator=(const CFlight& other);
	bool exists(std::string memberName) const;
	~CFlight();

private:
	/*Note : plane and CCrewMember are const pointers pointing to existing plane and crew members,
	 without the ability to alter the original objects by dereferencing.*/
	CFlightInfo flightInfo;
	const CPlane* plane;
	static constexpr int MAX_CREW = 20;
	const CCrewMember* crewMembersArr[MAX_CREW];
	int crewMembersCount;
};


