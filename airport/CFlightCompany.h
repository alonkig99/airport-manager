#pragma once
#include <string>
#include "CPlane.h"
#include "CCrewMember.h"
#include "CFlight.h"
#include <ostream>
class CFlightCompany
{
public:
	//constructors&destructor
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other);
	CFlightCompany() = delete;
	~CFlightCompany();

	//getters&setters
	const std::string& GetName()const;
	void SetName(std::string newName);
	 CPlane* GetPlane(int index)const;

	//operator overloading
	friend std::ostream& operator<<(std::ostream& os, const CFlightCompany& flightCompany);
	const CFlightCompany& operator=(const CFlightCompany& other);

	//other methods
	bool AddCrewMember(const CCrewMember& newMember); 
	bool AddPlane(const CPlane& newPlane);
	bool AddFlight(const CFlight& newFlight);
	void AddCrewToFlight(int flightNum, int memberIndex);

	///////////////////////////

	int GetCargoCount() const;
	void CrewGetPresent() const;
	void PilotsToSimulator() const;
	void CrewGetUniform() const;
    bool TakeOff(int flightNum) const;
	CFlight* GetFlightByNum(int num)const;
	CCrewMember* GetCrewMember(int index);
	

private:
	std::string name;
	static constexpr int MAX_CREWS = 50;
	static constexpr int MAX_PLANES = 50;
	static constexpr int MAX_FLIGHT = 50;
	CPlane* planesArr[MAX_PLANES] = { nullptr };
	CCrewMember* membersArr[MAX_CREWS] = { nullptr };
	CFlight* flightsArr[MAX_FLIGHT] = { nullptr };
	int planesCount;
	int membersCount;
	int flightsCount;





};

