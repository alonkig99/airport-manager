#pragma once
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include <string>
class CFlight
{
public:

	//constructors&destructor
	CFlight(CFlightInfo flightInfo, CPlane* plane= nullptr);
	CFlight(const CFlight& other);
	CFlight() = delete;
	~CFlight();

	//getters&setters
	void SetPlane(CPlane* newPlane);
	const CFlightInfo& GetFlightInfo();

	//operator overloading
	friend CFlight operator+(CCrewMember* newMember, CFlight& flight);
	friend CFlight operator+(CFlight& flight, CCrewMember* newMember);
	friend std::ostream& operator<<(std::ostream& os, const CFlight& flight);
	bool operator ==(const CFlight& other)const;
	bool operator !=(const CFlight& other)const;
	const CFlight& operator=(const CFlight& other);

	//other methods
	bool exists(std::string memberName) const;
	bool TakeOff();
	bool VerifyPlane() const;
	bool VerifyCargo() const;

private:
	/*Note : plane and CCrewMember are const pointers pointing to 
	existing plane and crew members without alocating heap memory*/
	CFlightInfo flightInfo;
	 CPlane* plane;
	static constexpr int MAX_CREW = 20;
	 CCrewMember* crewMembersArr[MAX_CREW];
	int crewMembersCount;
};


