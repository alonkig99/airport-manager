#pragma once
#include "CAddress.h"
#include <string>

class CCrewMember
{
public:

	CCrewMember(std::string name,const CAddress& address, int totalAirTime=0);
	CCrewMember(const CCrewMember& other);
	bool UpdateMinutes(int newMinutes);
	std::string GetName()const;
	void SetName(const std::string& newName);
	CAddress GetAddress()const;
	void SetAddress(const CAddress& newAddress);
	int GetAirTime()const;
	void Print()const;
	bool IsEqual(const CCrewMember& other)const;
	~CCrewMember();


private:
	std::string name;
	CAddress address;
	int totalAirTime;
	
};

